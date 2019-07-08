/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#include <QApplication>
#include <QIcon>
#include <QStyle>
#include <QDesktopWidget>
#include <memory>

#include "finestraprincipale.h"
#include "contenitore.h"
#include "persona.h"
#include "allenamento.h"
#include "deepptr.h"

int main(int argc, char *argv[])
{
    Contenitore<std::shared_ptr<Persona>> cp;
    Contenitore<DeepPtr<Allenamento>> ca;

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/immagini/logo.svg"));
    FinestraPrincipale p(ca,cp);
    p.show();
    return a.exec();
}

