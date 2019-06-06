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
    Contenitore<DeepPtr<Allenamento*>> ca;
    Contenitore<std::shared_ptr<Persona>> cp;

    //fittizie da togliere
    auto sp1 = std::make_shared<Persona>("Tullio", "Pietro Maria Vardanega", 0);
    auto sp2 = std::make_shared<Persona>("Francescopaolo", "Montefalcone", 0);
    auto sp3 = std::make_shared<Persona>("Francesco", "Ranzato", 0);
    cp.pushBack(sp1); cp.pushBack(sp3); cp.pushBack(sp2);

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/immagini/logo.svg"));
    FinestraPrincipale w(ca,cp);
    w.setAttribute(Qt::WA_DeleteOnClose);
    /*w.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            w.minimumSize(),//size(),
            qApp->desktop()->availableGeometry()
        )
    );*/
    w.show();
    return a.exec();
}
