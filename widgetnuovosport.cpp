#include "widgetnuovosport.h"
#include <QLabel>
#include <QStringList>
#include <QPushButton>
#include <QIcon>
#include <QSize>

WidgetNuovoSport::WidgetNuovoSport(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout();
    layoutBottoni = new QHBoxLayout();
    layoutBottoni->addWidget( creaBottoneSport("ciclismo") );
    layoutBottoni->addWidget( creaBottoneSport("corsa") );
    layoutBottoni->addWidget( creaBottoneSport("nuoto") );
    layoutBottoni->addWidget( creaBottoneSport("triathlon") );
    lblCreazione = new QLabel("NUOVO ALLENAMENTO");
    layout->addWidget(lblCreazione);
    layout->setAlignment(lblCreazione, Qt::AlignHCenter);
    layout->addLayout(layoutBottoni);
    setLayout(layout);
}

QPushButton* WidgetNuovoSport::creaBottoneSport(const QString& nomeSport) const {
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
void WidgetNuovoSport::creaOggettoInserimentoSport(QString sport) {
    if( sport == "" ) {
       //inserimentoSport = new
    } else if( sport == "" ) {
        //inserimentoSport = new
    }//...
}
