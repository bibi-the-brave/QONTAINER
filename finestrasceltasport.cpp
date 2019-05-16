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
    sport << "calcio" << "ciclismo" << "corsa" << "nuoto"  << "thriatlon" << "palestra"
              << "pallavolo";
    for(int i = 0; i < sport.size(); i++)
        layoutSport->addWidget(creaBottoneSport(sport[i]));

    layoutFinestra->addLayout(layoutSport);
    setLayout(layoutFinestra);
}

FinestraSceltaSport::~FinestraSceltaSport() {
    delete layoutFinestra;
}


QPushButton* FinestraSceltaSport::creaBottoneSport(const QString& nomeSport) const {
    QPushButton *sport = new QPushButton();
    sport->setIcon(QIcon(":/immagini/" + nomeSport + ".svg"));
    sport->setIconSize(QSize(75,75));
    //connect(sport, SIGNAL(clicked()), this, member);
    return sport;
}
