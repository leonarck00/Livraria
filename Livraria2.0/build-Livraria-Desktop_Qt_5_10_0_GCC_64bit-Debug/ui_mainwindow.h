/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_Nome;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_codigo;
    QLabel *label_3;
    QLineEdit *lineEdit_Email;
    QLabel *label_4;
    QLineEdit *lineEdit_Telefone;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_Editora;
    QLineEdit *lineEdit_Titulo;
    QLineEdit *lineEdit_Autor;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_ISBN;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTextEdit *textEdit;
    QPushButton *pushButton_5;
    QLabel *label_13;
    QLineEdit *lineEdit_quantidade;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(614, 455);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_Nome = new QLineEdit(centralWidget);
        lineEdit_Nome->setObjectName(QStringLiteral("lineEdit_Nome"));
        lineEdit_Nome->setGeometry(QRect(120, 100, 251, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 0, 51, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 100, 51, 16));
        lineEdit_codigo = new QLineEdit(centralWidget);
        lineEdit_codigo->setObjectName(QStringLiteral("lineEdit_codigo"));
        lineEdit_codigo->setGeometry(QRect(120, 130, 251, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 130, 51, 16));
        lineEdit_Email = new QLineEdit(centralWidget);
        lineEdit_Email->setObjectName(QStringLiteral("lineEdit_Email"));
        lineEdit_Email->setGeometry(QRect(120, 160, 251, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 160, 51, 16));
        lineEdit_Telefone = new QLineEdit(centralWidget);
        lineEdit_Telefone->setObjectName(QStringLiteral("lineEdit_Telefone"));
        lineEdit_Telefone->setGeometry(QRect(120, 190, 251, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 190, 71, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 70, 171, 16));
        lineEdit_Editora = new QLineEdit(centralWidget);
        lineEdit_Editora->setObjectName(QStringLiteral("lineEdit_Editora"));
        lineEdit_Editora->setGeometry(QRect(120, 320, 251, 21));
        lineEdit_Titulo = new QLineEdit(centralWidget);
        lineEdit_Titulo->setObjectName(QStringLiteral("lineEdit_Titulo"));
        lineEdit_Titulo->setGeometry(QRect(120, 260, 251, 21));
        lineEdit_Autor = new QLineEdit(centralWidget);
        lineEdit_Autor->setObjectName(QStringLiteral("lineEdit_Autor"));
        lineEdit_Autor->setGeometry(QRect(120, 290, 251, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 290, 51, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(70, 260, 51, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(60, 320, 61, 16));
        lineEdit_ISBN = new QLineEdit(centralWidget);
        lineEdit_ISBN->setObjectName(QStringLiteral("lineEdit_ISBN"));
        lineEdit_ISBN->setGeometry(QRect(120, 350, 251, 21));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 350, 51, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(160, 230, 141, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 30, 121, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 30, 121, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 30, 121, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(470, 30, 111, 23));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(380, 100, 211, 241));
        textEdit->setReadOnly(true);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(380, 350, 211, 51));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 380, 91, 20));
        lineEdit_quantidade = new QLineEdit(centralWidget);
        lineEdit_quantidade->setObjectName(QStringLiteral("lineEdit_quantidade"));
        lineEdit_quantidade->setGeometry(QRect(120, 380, 251, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 614, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Livraria", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Nome:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Codigo:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "E-mail:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Telefone:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Informa\303\247\303\265es do usuario", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Autor:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Titulo:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Editora:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "ISBN:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Informa\303\247\303\265es do livro", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Cadastrar usuario", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Cadastrar livro", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Listar usuario", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Listar livro", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Confirmar", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Quantidade:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
