#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include<QString>
#include<list>
#include<fstream>
using namespace std;

#include "Livro.h"
#include "Usuario.h"

class Biblioteca
{
private:
    int QuantidadeDeLivros;
    list<Usuario> users;
    list<Livro> books;
    list<string> relacao;
public:
    Biblioteca();
    void AddBook(Livro book);
    bool AddUser(Usuario usuario,bool mod);
    bool DeletBook(long long ISBN,Livro *ret);
    bool BuscaLivro(long long ISBN,Livro *ret);
    bool BuscaUsario(int cod,Usuario* ret);
    bool emprestimo(int cod,long long ISBN,int quant);
    int GetQuantidadeDeLivros(){return QuantidadeDeLivros;}
};

#endif // BIBLIOTECA_H
