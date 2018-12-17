#ifndef LIVRO_H
#define LIVRO_H
#include <QString>
#include<QStringList>
#include "Dados.h"
namespace TP2
{
    class Livro;
}

class Livro : public Dados
{
private:
    long long ISBN;
    QString Titulo;
    QString Autor;
    QString Editora;
    int QuantidadeDeExemplares;
    int QuantidadeDisponivel;
public:
    Livro();
    Livro(long long ISBN,QString Titulo,QString Autor,QString Editora,int QuantidadeDeExemplares);
    long long GetISBN(){return ISBN;}
    QString GetTitulo(){return Titulo;}
    QString GetAutor(){return  Autor;}
    QString GetEditora(){return Editora;}
    int GetQuantidadeDeExemplares(){return QuantidadeDeExemplares;}
    int GetQuantidadeDisponivel(){return QuantidadeDisponivel;}
    void SetISBN(long long ISBN);
    void SetTitulo(QString Titulo);
    void SetAutor(QString Autor);
    void SetEditora(QString Editora);
    void SetQuantidadeDeExemplares(int QuantidadeDeExemplares);
    void SetQuantidadeDisponivel(int QuantidadeDisponivel);

    virtual QString desmontarDados()const;
    virtual void montarDados(QString &str);
};

#endif // LIVRO_H
