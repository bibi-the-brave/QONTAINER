#include "widgetnuovosport.h"
#include <QLabel>
#include <QStringList>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include "dialogallenamento.h"
#include "dialognuoto.h"
#include "dialogciclismo.h"
#include "dialogcorsa.h"
#include "dialogtriathlon.h"

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
}

QPushButton* WidgetNuovoSport::creaBottoneSport(const QString& nomeSport) {
    QPushButton *sport = new QPushButton();
    sport->setIcon(QIcon(":/immagini/" + nomeSport + ".svg"));
    sport->setIconSize(QSize(75,75));
    sport->setToolTip(nomeSport);
    connect(sport, &QPushButton::clicked, [=]() {
        creaDialogInserimentoSport(nomeSport);
    });
    return sport;
}

/*
 * Crea un'oggetto che ha il tipo dinamico corrispondente al dialog che permette
 * di inserire un allenamento dello sport selezionato
 */
void WidgetNuovoSport::creaDialogInserimentoSport(QString sport) {
    DialogAllenamento* dialog;
    if( sport == "ciclismo" ) {
        dialog = new DialogCiclismo(cp, ca);
    } else if( sport == "nuoto" ) {
        dialog = new DialogNuoto(cp, ca);
    } else if( sport == "corsa" ) {
        dialog = new DialogCorsa(cp, ca);
    } else if( sport == "triathlon" ) {
        dialog = new DialogTriathlon(cp, ca);
    } else {
        return;
    }

    dialog->exec();
    dialog->disconnect();
    delete dialog;
}
