#include "finestraprincipale.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FinestraPrincipale w;
    w.show();

    return a.exec();
}
