#include "finestraprincipale.h"
#include <QIcon>
#include <QPixmap>

FinestraPrincipale::FinestraPrincipale(QWidget *parent)
    : QMainWindow(parent)
{
    layout = new QHBoxLayout();

    bInserAtleta = new QPushButton(/*"nuovo atleta"*/);
    bInserAtleta->setIcon(QIcon(QPixmap(":/immagini/atleti.svg")));
    bInserAtleta->setIconSize(QSize(340,340));
    bInserAtleta->setToolTip("Creazione di un nuovo atleta");
    bInserAtleta->setFixedSize(QSize(350,350));

    bInserAllenamento = new QPushButton(/*"nuovo allenamento"*/);
    bInserAllenamento->setIcon(QIcon( ":/immagini/allenamento.svg"));
    bInserAllenamento->setIconSize(QSize(325,325));
    bInserAllenamento->setToolTip("Inserirmento di un nuovo allenamento");
    bInserAllenamento->setFixedSize(QSize(350,350));

    bRicerca = new QPushButton(/*"ricerca"*/);
    bRicerca->setIcon(QIcon(":/immagini/ricerca.svg"));
    bRicerca->setIconSize(QSize(325,325));
    bRicerca->setToolTip("Ricerca allenamenti relativi ad uno sport o ad un atleta");
    bRicerca->setFixedSize(QSize(350,350));


    layout->addWidget(bInserAtleta);
    layout->addWidget(bInserAllenamento);
    layout->addWidget(bRicerca);

    centrale = new QWidget(this);
    centrale->setLayout(layout);

    setCentralWidget(centrale);
}
/*
 * Inserimento Atleta
 * Inserimento allenamento
 * ??? Classifica allenamenti ???
 * Ricerca
 */
FinestraPrincipale::~FinestraPrincipale()
{
    delete centrale;
}
