#include "finestraprincipale.h"
#include <QDir>

FinestraPrincipale::FinestraPrincipale(QWidget *parent)
    : QMainWindow(parent)
{
    layout = new QHBoxLayout();

    bInserAtleta = new QPushButton("nuovo atleta");
    bInserAtleta->setIcon(QIcon(QDir::currentPath() + "/immagini/atleti.svg"));
    bInserAtleta->setToolTip("Creazione di un nuovo atleta");
    bInserAtleta->setFixedSize(QSize(350,350));

    bInserAllenamento = new QPushButton("nuovo allenamento");
    bInserAllenamento->setIcon(QIcon(QDir::currentPath()
                                     + "/immagini/allenamento.svg"));
    bInserAllenamento->setToolTip("Inserirmento di un nuovo allenamento");
    bInserAllenamento->setFixedSize(QSize(350,350));

    bRicerca = new QPushButton("ricerca");
    bRicerca->setIcon(QIcon(QDir::currentPath() + "/immagini/ricerca.svg"));
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
