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
    Contenitore<std::shared_ptr<Persona*>> cp;

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
