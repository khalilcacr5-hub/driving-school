#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test = c.connect();
    if (test ) {
        w.show();
        QMessageBox:: information(nullptr,QObject::tr("base de donnees ouverte"),
                                 QObject::tr("felicitation vous etes connectes a la base de donne \n" "cliquer ok pour quitter") , QMessageBox::Ok);

    }
    else QMessageBox::critical(nullptr,QObject::tr("echec"),QObject::tr("echec de connexion a la base de donnees \n" "cliquer ok pour quitter"),QMessageBox::Cancel);



    return a.exec();
}
