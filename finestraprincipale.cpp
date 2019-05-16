#include "finestraprincipale.h"
#include <QIcon>
#include <QPixmap>

FinestraPrincipale::FinestraPrincipale(QWidget *parent)
    : QMainWindow(parent)
{
    layout = new QHBoxLayout();

    QSize grandezzaIcona(172,172);
    QSize grandezzaBottone(175,175);

    bInserAtleta = new QPushButton(/*"nuovo atleta"*/);
    bInserAtleta->setIcon(QIcon(QPixmap(":/immagini/atleti.svg")));
    bInserAtleta->setIconSize(grandezzaIcona);
    bInserAtleta->setToolTip("Creazione di un nuovo atleta");
    bInserAtleta->setIconSize(grandezzaBottone);

    bInserAllenamento = new QPushButton(/*"nuovo allenamento"*/);
    bInserAllenamento->setIcon(QIcon( ":/immagini/allenamento.svg"));
    bInserAllenamento->setIconSize(grandezzaIcona);
    bInserAllenamento->setToolTip("Inserirmento di un nuovo allenamento");
    bInserAllenamento->setIconSize(grandezzaBottone);

    bRicerca = new QPushButton(/*"ricerca"*/);
    bRicerca->setIcon(QIcon(":/immagini/ricerca.svg"));
    bRicerca->setIconSize(grandezzaIcona);
    bRicerca->setToolTip("Ricerca allenamenti relativi ad uno sport o ad un atleta");
    bRicerca->setIconSize(grandezzaBottone);


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
