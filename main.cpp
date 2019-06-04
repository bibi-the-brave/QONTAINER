#include <QApplication>
#include <QIcon>
#include "finestraprincipale.h"
#include <QStyle>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/immagini/logo.svg"));
    FinestraPrincipale w;
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
