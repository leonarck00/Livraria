#include "Usuario.h"

Usuario::Usuario(int Codigo,QString Nome,QString Email,long long Telefone)
{
    SetCodigo(Codigo);
    SetNome(Nome);
    SetEmail(Email);
    SetTelefone(Telefone);
}
void Usuario::SetCodigo(int Codigo)
{
    this->Codigo=Codigo;
    if(Codigo<=0)
         throw QString ("Codigo invalido!!");
}
void Usuario::SetNome(QString Nome)
{
    if(Nome=="")
         throw QString ("Nome invalido!!");
    if(Nome[0]==" ")
        throw QString ("Nome invalido, verifique se não iniciou o nome com um espaço em branco!!");
    this->Nome=Nome;
}
void Usuario::SetEmail(QString Email)
{
    if(Email=="")
         throw QString ("Email invalido!!");
    if(Email[0]==" ")
        throw QString ("Email invalido, verifique se não iniciou o Email com um espaço em branco!!");
    this->Email=Email;
}
void Usuario::SetTelefone(long long Telefone)
{
    if(Telefone<=0)
         throw QString ("Telefone invalido!!");
    this->Telefone=Telefone;
}
QString Usuario::desmontarDados()const
{
    return QString::number(Codigo) + ";" + Nome + ";" + Email + ";" + QString::number(Telefone);
}

void Usuario::montarDados(QString &str)
{
    try
    {
        QStringList strList = str.split(';');
        if(strList.length()!=4)
            throw QString ("Linha não a quantidade de parâmetros indicada.");
        Codigo = strList[0].toLong();
        Nome = strList[1];
        Email = strList[2];
        Telefone = strList[3].toLongLong();
    }
    catch (QString erro)
    {
        throw QString("Erro no metodo montarDados da classe Contato.");
    }
}


