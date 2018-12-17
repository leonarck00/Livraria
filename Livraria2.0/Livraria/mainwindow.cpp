#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Usuario.h"
#include "Livro.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   ui->textEdit->setText("Bem vindo a livraria!!\nSelecione a opção desejada!");
   BloquearCampoL();
   BloquearCampoU();
}
void MainWindow::LimparCampos()
{
    ui->lineEdit_ISBN->setText("");
    ui->lineEdit_Editora->setText("");
    ui->lineEdit_Autor->setText("");
    ui->lineEdit_Titulo->setText("");
    ui->lineEdit_quantidade->setText("");
    ui->lineEdit_Nome->setText("");
    ui->lineEdit_Email->setText("");
    ui->lineEdit_Telefone->setText("");
    ui->lineEdit_codigo->setText("");
}
void MainWindow::LiberarCampoL()
{
    LimparCampos();
    ui->lineEdit_ISBN->setEnabled(true);
    ui->lineEdit_Editora->setEnabled(true);
    ui->lineEdit_Autor->setEnabled(true);
    ui->lineEdit_Titulo->setEnabled(true);
    ui->lineEdit_quantidade->setEnabled(true);
}
void MainWindow::LiberarCampoU()
{
    LimparCampos();
    ui->lineEdit_Nome->setEnabled(true);
    ui->lineEdit_Email->setEnabled(true);
    ui->lineEdit_Telefone->setEnabled(true);
    ui->lineEdit_codigo->setEnabled(true);
}
void MainWindow::BloquearCampoL()
{
    LimparCampos();
    ui->lineEdit_ISBN->setEnabled(false);
    ui->lineEdit_Editora->setEnabled(false);
    ui->lineEdit_Autor->setEnabled(false);
    ui->lineEdit_Titulo->setEnabled(false);
    ui->lineEdit_quantidade->setEnabled(false);
}
void MainWindow::BloquearCampoU()
{
    LimparCampos();
    ui->lineEdit_Nome->setEnabled(false);
    ui->lineEdit_Email->setEnabled(false);
    ui->lineEdit_Telefone->setEnabled(false);
    ui->lineEdit_codigo->setEnabled(false);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    esc=1;
    LiberarCampoU();
    BloquearCampoL();
    ui->textEdit->setText("Preencha os campos com os dados do Usuario!!");
}
void MainWindow::on_pushButton_2_clicked()
{
    esc=2;
    LiberarCampoL();
    BloquearCampoU();
    ui->textEdit->setText("Preencha os campos com os dados do livro!!");
}
void MainWindow::on_pushButton_4_clicked()
{
    esc=3;
    BloquearCampoL();
    BloquearCampoU();
    ui->lineEdit_ISBN->setEnabled(true);
    ui->textEdit->setText("Digite o ISBN do livro que deseja excluir!!");
}
void MainWindow::on_pushButton_9_clicked()
{
    esc=4;
    BloquearCampoL();
    BloquearCampoU();
    ui->lineEdit_ISBN->setEnabled(true);
    ui->textEdit->setText("Digite o ISBN do livro que deseja buscar!!");

}
void MainWindow::on_pushButton_10_clicked()
{
    esc=5;
    BloquearCampoL();
    BloquearCampoU();
    ui->lineEdit_codigo->setEnabled(true);
    ui->textEdit->setText("Digite o codigo do usuario que deseja buscar!!");

}
void MainWindow::on_pushButton_6_clicked()
{
    esc=6;
    BloquearCampoL();
    BloquearCampoU();
    ui->lineEdit_codigo->setEnabled(true);
    ui->textEdit->setText("Digite o codigo do usuario alterar!!");
}

void MainWindow::on_pushButton_7_clicked()
{
    esc=8;
    BloquearCampoL();
    BloquearCampoU();
    ui->lineEdit_codigo->setEnabled(true);
    ui->textEdit->setText("Digite o codigo do usuario que deseja efetuar o emprestimo!!");
}

void MainWindow::on_pushButton_5_clicked()
{
    int Codigo;
    QString Nome;
    QString Email;
    long long Telefone;
    QString saida;
    ofstream user_saida;//("C:/Users/brunoh/Documents/CDC/TP2/Livraria2.0/Livraria/usuario.txt");
    if(esc==1)
    {
        try{
            Codigo=ui->lineEdit_codigo->text().toInt();
            Nome=ui->lineEdit_Nome->text();
            Email=ui->lineEdit_Email->text();
            Telefone=ui->lineEdit_Telefone->text().toLongLong();
            Usuario y(Codigo,Nome,Email,Telefone);

            if(X.AddUser(y,false))
            {
                saida="Cadastrado com sucesso!!\nCodigo: "+QString::number(y.GetCodigo())+"\nNome:"+y.GetNome();
                saida+="\nEmail: "+y.GetEmail()+"\nTelefone: "+QString::number(y.GetTelefone());
                ui->textEdit->setText(saida);
            }
            else
            {
                ui->textEdit->setText("Usuario Ja cadastrado!!\nSe deseja alterar o cadastro clique na area de editar usuario!");
            }
        }
        catch(QString &erro)
        {
            QMessageBox::information(this,"ERRO DO SISTEMA",erro);
        }
    }
    else if(esc==2)
    {
        saida="/home/puc/Downloads/Livro";
        long long ISBN;
        QString Titulo;
        QString Autor;
        QString Editora;
        int QuantidadeDeExemplares;
        try{
            ISBN=ui->lineEdit_ISBN->text().toLongLong();
            Titulo=ui->lineEdit_Titulo->text();
            Autor=ui->lineEdit_Autor->text();
            Editora=ui->lineEdit_Editora->text();
            QuantidadeDeExemplares=ui->lineEdit_quantidade->text().toInt();
            Livro z(ISBN,Titulo,Autor,Editora,QuantidadeDeExemplares);

            X.AddBook(z);

            saida="Cadastrado com sucesso!!\nISBN: "+QString::number(z.GetISBN())+"\nTitulo:"+z.GetTitulo();
            saida+="\nAutor: "+z.GetAutor()+"\nEditora: "+z.GetEditora()+"\nQuantidade de Exemplares: "+QString::number(z.GetQuantidadeDeExemplares());
            ui->textEdit->setText(saida);
        }
        catch(QString &erro)
        {
            QMessageBox::information(this,"ERRO DO SISTEMA",erro);
        }
    }
    else if(esc==3)
    {
        long long ISBN;
        ISBN=ui->lineEdit_ISBN->text().toLongLong();
        Livro ret;

        if(X.DeletBook(ISBN,&ret))
        {
            saida="Deletado com sucesso com sucesso!!\nISBN: "+QString::number(ret.GetISBN())+"\nTitulo:"+ret.GetTitulo();
            saida+="\nAutor: "+ret.GetAutor()+"\nEditora: "+ret.GetEditora()+"\nQuantidade de Exemplares: "+QString::number(ret.GetQuantidadeDeExemplares());
            ui->textEdit->setText(saida);
        }
        else
        {
            ui->textEdit->setText("Livro não encontrado!");
        }
    }
    else if(esc==4)
    {
        long long ISBN;
        ISBN=ui->lineEdit_ISBN->text().toLongLong();
        Livro ret;

        if(X.BuscaLivro(ISBN,&ret))
        {
            saida="Livro encontrado!!\nISBN: "+QString::number(ret.GetISBN())+"\nTitulo:"+ret.GetTitulo();
            saida+="\nAutor: "+ret.GetAutor()+"\nEditora: "+ret.GetEditora()+"\nQuantidade de Exemplares: "+QString::number(ret.GetQuantidadeDeExemplares());
            saida+="\nDisponivel:"+QString::number(ret.GetQuantidadeDisponivel());
            ui->textEdit->setText(saida);
        }
        else
        {
            ui->textEdit->setText("Livro não encontrado!");
        }
    }
    else if(esc==5)
    {
        int cod;
        cod=ui->lineEdit_codigo->text().toInt();
        Usuario ret;

        if(X.BuscaUsario(cod,&ret))
        {
            saida="Usuario encontardo!!\nCodigo: "+QString::number(ret.GetCodigo())+"\nNome:"+ret.GetNome();
            saida+="\nEmail: "+ret.GetEmail()+"\nTelefone: "+QString::number(ret.GetTelefone());
            ui->textEdit->setText(saida);
        }
        else
        {
            ui->textEdit->setText("Usuario não encontrado!");
        }
    }
    else if(esc==6)
    {
        int cod;
        cod=ui->lineEdit_codigo->text().toInt();
        Usuario ret;

        if(X.BuscaUsario(cod,&ret))
        {
            saida="Usuario encontardo!!\nCodigo: "+QString::number(ret.GetCodigo())+"\nNome:"+ret.GetNome();
            saida+="\nEmail: "+ret.GetEmail()+"\nTelefone: "+QString::number(ret.GetTelefone());
            saida+="\n\nDigite os novos dados do usuario e confirme!";
            BloquearCampoL();
            LiberarCampoU();
            ui->lineEdit_codigo->setEnabled(false);
            ui->lineEdit_codigo->setText(QString::number(cod));
            esc=7;
            n=cod;
            ui->textEdit->setText(saida);
        }
        else
        {
            ui->textEdit->setText("Usuario não encontrado!\nDigite cum codigo valido!");
        }
    }
    else if(esc==7)
    {
        Codigo=n;
        Nome=ui->lineEdit_Nome->text();
        Email=ui->lineEdit_Email->text();
        Telefone=ui->lineEdit_Telefone->text().toLongLong();
        Usuario y(Codigo,Nome,Email,Telefone);
        X.AddUser(y,true);
        saida="Alterado com sucesso!!\nCodigo: "+QString::number(y.GetCodigo())+"\nNome:"+y.GetNome();
        saida+="\nEmail: "+y.GetEmail()+"\nTelefone: "+QString::number(y.GetTelefone());
        ui->textEdit->setText(saida);
    }
    else if(esc==8)
    {
        int cod;
        cod=ui->lineEdit_codigo->text().toInt();
        Usuario ret;

        if(X.BuscaUsario(cod,&ret))
        {
            saida="Usuario encontardo!!\nCodigo: "+QString::number(ret.GetCodigo())+"\nNome:"+ret.GetNome();
            saida+="\nEmail: "+ret.GetEmail()+"\nTelefone: "+QString::number(ret.GetTelefone());
            saida+="\n\nDigite o ISBN do livro que deseja alugar!";
            BloquearCampoL();
            BloquearCampoU();
            ui->lineEdit_codigo->setEnabled(false);
            ui->lineEdit_ISBN->setEnabled(true);
            ui->lineEdit_codigo->setText(QString::number(cod));
            esc=9;
            n=ret.GetCodigo();
            ui->textEdit->setText(saida);
        }
        else
        {
            ui->textEdit->setText("Usuario não encontrado!\nDigite cum codigo valido!");
        }
    }
    else if(esc==9)
    {
        long long ISBN;
        ISBN=ui->lineEdit_ISBN->text().toLongLong();
        Livro ret;

        if(X.BuscaLivro(ISBN,&ret))
        {
            saida="Livro encontrado!!\nISBN: "+QString::number(ret.GetISBN())+"\nTitulo:"+ret.GetTitulo();
            saida+="\nAutor: "+ret.GetAutor()+"\nEditora: "+ret.GetEditora()+"\nQuantidade de Exemplares: "+QString::number(ret.GetQuantidadeDeExemplares());
            saida+="\nDisponivel:"+QString::number(ret.GetQuantidadeDisponivel());
            saida+="\n\nDigite a quantidade que deseja alugar!!";
            ui->lineEdit_ISBN->setEnabled(false);
            ui->lineEdit_quantidade->setEnabled(true);
            ui->textEdit->setText(saida);
            esc=10;
            nli=ISBN;
        }
        else
        {
            ui->textEdit->setText("Livro não encontrado!");
        }
    }
    else if(esc==10)
    {
        int quant=ui->lineEdit_quantidade->text().toInt();
        if(quant>0)
        {
            if(X.emprestimo(n,nli,quant))
            {
                ui->textEdit->setText("Aluguel registrado com sucesso!!");
            }
            else
            {
                ui->textEdit->setText("Quantidade indisponivel ou o usuario não pode mais pegar livros!");
            }
        }
        else
        {
            ui->textEdit->setText("Quantidade invalida!!");
        }
    }

}
void MainWindow::on_pushButton_8_clicked()
{
    QString saida="Possuimos um acervo de "+QString::number(X.GetQuantidadeDeLivros())+" Livros!!";
    ui->textEdit->setText(saida);
}






