#ifndef DADOS_H
#define DADOS_H
#include<QString>
//#include "Livro.h"

namespace TP2
{
    class Dados;
}

class Dados
{
    virtual QString desmontarDados()const = 0;
    virtual void montarDados(QString &str) = 0;
};


#endif // DADOS_H
