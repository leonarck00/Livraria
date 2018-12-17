#ifndef USUARIO_H
#define USUARIO_H
#include <QString>
#include<QStringList>
#include "Dados.h"
namespace TP2
{
    class Usuario;
}


class Usuario : public Dados
{

private:
     int Codigo;
     QString Nome;
     QString Email;
     long long Telefone;
public:
    Usuario(){Codigo=0,Nome="",Email="",Telefone=0;}
    Usuario(int Codigo,QString Nome,QString Email,long long Telefone);
    int GetCodigo(){return Codigo;}
    QString GetNome(){return Nome;}
    QString GetEmail(){return Email;}
    long long GetTelefone(){return Telefone;}
    void SetCodigo(int Codigo);
    void SetNome(QString Nome);
    void SetEmail(QString Email);
    void SetTelefone(long long Telefone);
    virtual QString desmontarDados()const;
    virtual void montarDados(QString &str);
};

#endif // USUARIO_H
