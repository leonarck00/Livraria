#include "Livro.h"


Livro::Livro()
{
    ISBN=0;
    Titulo="";
    Autor="";
    Editora="";
    QuantidadeDeExemplares=0;
    QuantidadeDisponivel=0;
}
Livro::Livro(long long ISBN,QString Titulo,QString Autor,QString Editora,int QuantidadeDeExemplares)
{
    SetISBN(ISBN);
    SetTitulo(Titulo);
    SetAutor(Autor);
    SetEditora(Editora);
    SetQuantidadeDeExemplares(QuantidadeDeExemplares);
    SetQuantidadeDisponivel(QuantidadeDeExemplares);
}
void Livro::SetISBN(long long ISBN)
{
    this->ISBN=ISBN;
}
void Livro::SetTitulo(QString Titulo)
{
    if(Titulo=="")
         throw QString ("Titulo invalido!!");
    if(Titulo[0]==" ")
        throw QString ("Titulo invalido, verifique se não iniciou o Titulo com um espaço em branco!!");
    this->Titulo=Titulo;
}
void Livro::SetAutor(QString Autor)
{
    if(Autor=="")
         throw QString ("Autor invalido!!");
    if(Autor[0]==" ")
        throw QString ("Autor invalido, verifique se não iniciou o nome do Autor com um espaço em branco!!");
    this->Autor=Autor;

}
void Livro::SetEditora(QString Editora)
{
    if(Editora=="")
         throw QString ("Editora invalida!!");
    if(Editora[0]==" ")
        throw QString ("Editora invalida, verifique se não iniciou o nome da Editora com um espaço em branco!!");
    this->Editora=Editora;
}
void Livro::SetQuantidadeDeExemplares(int QuantidadeDeExemplares)
{
    if(QuantidadeDeExemplares<=0)
         throw QString ("Quantidade De Exemplares invalido!!");
    this->QuantidadeDeExemplares=QuantidadeDeExemplares;

}
void Livro::SetQuantidadeDisponivel(int QuantidadeDisponivel)
{
    if(QuantidadeDisponivel<=0)
         throw QString ("Quantidade De Exemplares Disponiveis invalido!!");
    this->QuantidadeDisponivel=QuantidadeDisponivel;
}

QString Livro::desmontarDados()const
{
    return QString::number(ISBN) + ";" + Titulo + ";" + Autor + ";" + Editora + ";" + QString::number(QuantidadeDeExemplares) + ";" + QString::number(QuantidadeDisponivel);
}

void Livro::montarDados(QString &str)
{
    try
    {
        QStringList strList = str.split(';');
        if(strList.length()!=6)
            throw QString ("Linha não a quantidade de parâmetros indicada.");
        ISBN = strList[0].toLongLong();
        Titulo = strList[1];
        Autor = strList[2];
        Editora = strList[3];
        QuantidadeDeExemplares = strList[4].toInt();
        QuantidadeDisponivel = strList[5].toInt();

    }
    catch (QString erro)
    {
        throw QString("Erro no metodo montarDados da classe Contato.");
    }
}

