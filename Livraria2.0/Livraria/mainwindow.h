#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<fstream>
#include <QMessageBox>
#include <QMainWindow>
using namespace std;
#include "Biblioteca.h";
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();
    void LiberarCampoL();
    void LiberarCampoU();
    void BloquearCampoL();
    void BloquearCampoU();
    void LimparCampos();
    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Biblioteca X;
    int esc=0;
    Ui::MainWindow *ui;
    int n;
    long long nli;
};

#endif // MAINWINDOW_H
