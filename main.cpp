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

//da togliere, fittizi
#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"
#include "triathlon.h"
#include "data.h"

int main(int argc, char *argv[])
{
    Contenitore<std::shared_ptr<Persona>> cp;
    Contenitore<DeepPtr<Allenamento>> ca;

    //fittizie da togliere
    auto sp1 = std::make_shared<Persona>("Tullio", "Pietro Maria Vardanega", 0);
    auto sp2 = std::make_shared<Persona>("Francescopaolo", "Montefalcone", 0);
    auto sp3 = std::make_shared<Persona>("Francesco", "Ranzato", 0);
    cp.pushBack(sp1); cp.pushBack(sp3); cp.pushBack(sp2);
    DeepPtr<Allenamento> a1(new Ciclismo(sp1, 52, Data("01/01/2019"),12.0, 15,20,6));
    DeepPtr<Allenamento> a2(new Nuoto(sp1, 55, Data("01/01/2019"), 12.0, 35,50,29));
    ca.pushBack(a1); ca.pushBack(a2);

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/immagini/logo.svg"));
    FinestraPrincipale p(ca,cp);
    p.show();
    return a.exec();
}

/*
    Contenitore<std::shared_ptr<Persona>>::iterator it = atleti.begin();
    for(; it != atleti.end(); it++)
        qDebug() << QString::fromStdString((*it)->getNome());
*/
