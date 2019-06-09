#include "finestrasceltasport.h"
#include <QLabel>
#include <QStringList>
#include <QPushButton>
#include <QIcon>
#include <QSize>

FinestraSceltaSport::FinestraSceltaSport(QWidget *parent) : QWidget(parent) {
    layoutFinestra = new QVBoxLayout();

    QLabel *labelInformativo = new QLabel("SCEGLIERE IL TIPO DI ALLENAMENTO:");
    layoutFinestra->addWidget(labelInformativo, Qt::AlignCenter);

    layoutSport = new QGridLayout();
    QStringList sport;
    sport << "calcio" << "ciclismo" << "corsa" << "nuoto"  << "triathlon" << "palestra"
              << "pallavolo";
    for(int i = 0; i < sport.size(); i++) {
        int colonna = i % 3;//il layout ha 3 colonne //vedere se colonne o righe partono da 0 o da 1
        int riga = i / 3;
        layoutSport->addWidget(creaBottoneSport(sport[i]), riga, colonna);
    }

    layoutFinestra->addLayout(layoutSport);
    setLayout(layoutFinestra);

    layout()->setSizeConstraint( QLayout::SetFixedSize );
}
/*
FinestraSceltaSport::~FinestraSceltaSport() {
    if(inserimentoSport)
        delete inserimentoSport;
    delete layoutFinestra;
}*/

QPushButton* FinestraSceltaSport::creaBottoneSport(const QString& nomeSport) const {
    QPushButton *sport = new QPushButton();
    sport->setIcon(QIcon(":/immagini/" + nomeSport + ".svg"));
    sport->setIconSize(QSize(75,75));
    sport->setToolTip(nomeSport);
    /*connect(sport, &QPushButton::clicked, [this]() {
        this->creaOggettoInserimentoSport(nomeSport);
    });*/
    return sport;
}

/*
 * Crea un'oggetto che ha come tipo dinamico quello della view di inserimento dati
 * relatica allo sport selezionato
 */
void FinestraSceltaSport::creaOggettoInserimentoSport(QString sport) {
    if( sport == "" ) {
       //inserimentoSport = new
    } else if( sport == "" ) {
        //inserimentoSport = new
    }//...
}
