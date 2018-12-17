#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    ifstream Quant_livro;
    QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/acervo.txt";
    Quant_livro.open(end.toStdString().c_str());
    Quant_livro>>QuantidadeDeLivros;
}


void Biblioteca::AddBook(Livro book)
{
    ifstream Cad_Livro;
    QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/Livro.txt";
    Cad_Livro.open(end.toStdString().c_str());
    if(!Cad_Livro.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");
    std::string ent;
    std::getline(Cad_Livro,ent);
    bool flag=true;
    while(!Cad_Livro.eof())
    {
        Livro livro;
        QString str = QString::fromStdString(ent);
        livro.montarDados(str);
        if(livro.GetISBN()== book.GetISBN())
        {
            int y=livro.GetQuantidadeDeExemplares()+book.GetQuantidadeDeExemplares();
            int x=livro.GetQuantidadeDisponivel()+book.GetQuantidadeDisponivel();
            livro.SetQuantidadeDeExemplares(y);
            livro.SetQuantidadeDisponivel(x);
            QuantidadeDeLivros=QuantidadeDeLivros+book.GetQuantidadeDeExemplares();
            flag=false;
            ofstream Quant_livro;
            QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/acervo.txt";
            Quant_livro.open(end.toStdString().c_str());
            Quant_livro<<QuantidadeDeLivros;

        }
        books.push_back(livro);
        std::getline(Cad_Livro,ent);
    }
    Cad_Livro.close();
    if(flag)
    {
        books.push_back(book);
        QuantidadeDeLivros=QuantidadeDeLivros+book.GetQuantidadeDeExemplares();
        ofstream Quant_livro;
        QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/acervo.txt";
        Quant_livro.open(end.toStdString().c_str());
        Quant_livro<<QuantidadeDeLivros;
    }


    ofstream Cad_livro2;
    QString end2="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/Livro.txt";
    Cad_livro2.open(end2.toStdString().c_str());
    if(!Cad_livro2.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");

    while(!books.empty())
    {
        Livro livro = books.front();
        Cad_livro2 << livro.desmontarDados().toStdString() + "\n";
        books.pop_front();
    }
    Cad_livro2.close();
}
bool Biblioteca::AddUser(Usuario usuario,bool mod)
{
    ifstream Cad_User;
    QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/usuario.txt";
    Cad_User.open(end.toStdString().c_str());
    if(!Cad_User.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");
    std::string ent;
    std::getline(Cad_User,ent);
    bool flag=true;
    while(!Cad_User.eof())
    {
        Usuario user;
        QString str = QString::fromStdString(ent);
        user.montarDados(str);
        if(user.GetCodigo()==usuario.GetCodigo())
        {
            if(!mod)
            {
                users.push_back(user);
            }
            flag=false;
        }
        else
        {
            users.push_back(user);
        }
        std::getline(Cad_User,ent);
    }
    Cad_User.close();
    if(flag||mod)
    {
        users.push_back(usuario);
    }
    ofstream Cad_User2;
    QString end2="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/usuario.txt";
    Cad_User2.open(end2.toStdString().c_str());
    if(!Cad_User2.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");
    while(!users.empty())
    {
        Usuario user = users.front();
        Cad_User2 << user.desmontarDados().toStdString() + "\n";
        users.pop_front();
    }
    Cad_User2.close();
    return flag;
}
bool Biblioteca::DeletBook(long long ISBN,Livro *ret)
{
    ifstream Cad_Livro;
    QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/Livro.txt";
    Cad_Livro.open(end.toStdString().c_str());
    if(!Cad_Livro.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");
    std::string ent;
    std::getline(Cad_Livro,ent);
    bool flag=false;
    while(!Cad_Livro.eof())
    {
        Livro livro;
        QString str = QString::fromStdString(ent);
        livro.montarDados(str);
        if(livro.GetISBN()==ISBN)
        {
            *ret=livro;
            QuantidadeDeLivros=QuantidadeDeLivros-livro.GetQuantidadeDeExemplares();
            flag=true;
            ofstream Quant_livro;
            QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/acervo.txt";
            Quant_livro.open(end.toStdString().c_str());
            Quant_livro<<QuantidadeDeLivros;

        }
        else
        {
            books.push_back(livro);
        }
        std::getline(Cad_Livro,ent);

    }
    Cad_Livro.close();

    ofstream Cad_livro2;
    QString end2="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/Livro.txt";
    Cad_livro2.open(end2.toStdString().c_str());
    if(!Cad_livro2.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");

    while(!books.empty())
    {
        Livro livro = books.front();
        Cad_livro2 << livro.desmontarDados().toStdString() + "\n";
        books.pop_front();
    }
    Cad_livro2.close();
    return flag;
}
bool Biblioteca::BuscaLivro(long long ISBN,Livro *ret)
{
    ifstream Cad_Livro;
    QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/Livro.txt";
    Cad_Livro.open(end.toStdString().c_str());
    if(!Cad_Livro.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");
    std::string ent;
    std::getline(Cad_Livro,ent);
    bool flag=false;
    while(!Cad_Livro.eof())
    {
        Livro livro;
        QString str = QString::fromStdString(ent);
        livro.montarDados(str);
        if(livro.GetISBN()==ISBN)
        {
            flag=true;
            *ret=livro;
        }
        books.push_back(livro);
        std::getline(Cad_Livro,ent);

    }
    Cad_Livro.close();

    ofstream Cad_livro2;
    QString end2="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/Livro.txt";
    Cad_livro2.open(end2.toStdString().c_str());
    if(!Cad_livro2.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");

    while(!books.empty())
    {
        Livro livro = books.front();
        Cad_livro2 << livro.desmontarDados().toStdString() + "\n";
        books.pop_front();
    }
    Cad_livro2.close();
    return flag;
}
bool Biblioteca::BuscaUsario(int cod,Usuario* ret)
{
    ifstream Cad_User;
    QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/usuario.txt";
    Cad_User.open(end.toStdString().c_str());
    if(!Cad_User.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");
    std::string ent;
    std::getline(Cad_User,ent);
    bool flag=false;
    while(!Cad_User.eof())
    {
        Usuario user;
        QString str = QString::fromStdString(ent);
        user.montarDados(str);
        if(user.GetCodigo()==cod)
        {
            *ret=user;
            flag=true;
        }
        users.push_back(user);
        std::getline(Cad_User,ent);
    }
    Cad_User.close();
    ofstream Cad_User2;
    QString end2="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/usuario.txt";
    Cad_User2.open(end2.toStdString().c_str());
    if(!Cad_User2.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");
    while(!users.empty())
    {
        Usuario user = users.front();
        Cad_User2 << user.desmontarDados().toStdString() + "\n";
        users.pop_front();
    }
    Cad_User2.close();
    return flag;
}
bool Biblioteca::emprestimo(int cod,long long ISBN,int quant)
{
    int c;
    long long i;
    int q;
    Livro ret;
    bool flag=true;
    ifstream Cad_User2;
    QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/relacao.txt";
    Cad_User2.open(end.toStdString().c_str());
    if(!Cad_User2.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");
    Cad_User2>>c;
    while(!Cad_User2.eof())
    {
        if(c==cod)
        {
            flag=false;
        }
        Cad_User2>>i>>q;
        QString saida=QString::number(c)+" "+QString::number(i)+" "+QString::number(q)+" ";
        relacao.push_back(saida.toStdString());
        Cad_User2>>c;
    }
    Cad_User2.close();
    ofstream Cad_User3;
    QString end3="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/relacao.txt";
    Cad_User3.open(end3.toStdString().c_str());
    if(!Cad_User3.is_open())
        throw QString("Arquivo de Lista de Livros nao foi aberto");
    string x;
    while(!relacao.empty())
    {
        x=relacao.front();
        relacao.pop_front();
        Cad_User3<<x+" ";
    }
    Cad_User3.close();
    if(flag)
    {
        DeletBook(ISBN,&ret);
        if(ret.GetQuantidadeDisponivel()>=quant)
        {

            ret.SetQuantidadeDisponivel(ret.GetQuantidadeDisponivel()-quant);
            ofstream Cad_User;
            QString end="C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/relacao.txt";
            Cad_User.open(end.toStdString().c_str(),std::ios::out|std::ios::app);
            if(!Cad_User.is_open())
                throw QString("Arquivo de Lista de Livros nao foi aberto");
            QString saida=QString::number(cod)+" "+QString::number(ISBN)+" "+QString::number(quant)+" ";
            Cad_User<<saida.toStdString();
            Cad_User.close();

        }
        else
        {
            flag=false;
        }
        AddBook(ret);
    }

    return flag;
}
