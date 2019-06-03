#include <QApplication>
#include <QIcon>
#include "finestraprincipale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/immagini/logo.svg"));
    FinestraPrincipale w;
    w.show();
    return a.exec();
}
