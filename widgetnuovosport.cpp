#include "widgetnuovosport.h"
#include <QLabel>
#include <QStringList>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include "dialogcreazioneallenamento.h"
#include "dialogcreazionenuoto.h"

WidgetNuovoSport::WidgetNuovoSport(Contenitore<std::shared_ptr<Persona>>& cp_,
                                   Contenitore<DeepPtr<Allenamento>>& ca_,
                                   QWidget *parent)
    : QWidget(parent), cp(cp_), ca(ca_)
{
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
    creaOggettoInserimentoSport("nuoto");
}

QPushButton* WidgetNuovoSport::creaBottoneSport(const QString& nomeSport) const {
    QPushButton *sport = new QPushButton();
    sport->setIcon(QIcon(":/immagini/" + nomeSport + ".svg"));
    sport->setIconSize(QSize(75,75));
    sport->setToolTip(nomeSport);/*
    connect(sport, &QPushButton::clicked, [nomeSport, ]() {
        this->creaOggettoInserimentoSport(nomeSport);
    });*/
    return sport;
}

/*
 * Crea un'oggetto che ha il tipo dinamico corrispondente al dialog che permette
 * di inserire un allenamento dello sport selezionato
 */
void WidgetNuovoSport::creaOggettoInserimentoSport(QString sport) {
    DialogCreazioneAllenamento* dialog;
    dialog = new DialogCreazioneNuoto(cp, ca);
    if( sport == "ciclismo" ) {

    } else if( sport == "nuoto" ) {
        dialog = new DialogCreazioneNuoto(cp, ca);
    } else if( sport == "corsa" ) {

    } else if( sport == "triathlon" ) {

    }

    dialog->exec();
    dialog->disconnect();
    delete dialog;
}
