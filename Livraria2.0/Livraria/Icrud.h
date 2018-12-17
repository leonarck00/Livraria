#ifndef ICRUD_H
#define ICRUD_H
#include "Livro.h"
#include "Usuario.h"
#include<list>

namespace TP2
{
class Icrud;
}


class Icrud
{
    virtual int incluir(Livro user_book)const=0;
    virtual int excluir(long long ISBN) const =0;
    virtual void incluir(Usuario user)const=0;
    virtual void excluir(QString nome) const =0;

    // STL - define uma lista de contatos
    virtual std::list<Livro>* listagem() const = 0;
    virtual std::list<Usuario>* listagem2() const = 0;

};

#endif // ICRUD_H
