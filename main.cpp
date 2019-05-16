#include "finestraprincipale.h"
#include <QApplication>
#include "finestrasceltasport.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FinestraPrincipale w;
    w.show();
//FinestraSceltaSport f ; f.show();
    return a.exec();
}
