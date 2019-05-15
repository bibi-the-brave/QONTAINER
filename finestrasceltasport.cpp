#include "finestrasceltasport.h"
#include <QLabel>

FinestraSceltaSport::FinestraSceltaSport(QWidget *parent) : QWidget(parent) {
    layoutFinestra = new QVBoxLayout();

    QLabel *labelInformativo = new QLabel("SCEGLIERE IL TIPO DI ALLENAMENTO:");
    layoutFinestra->addWidget(labelInformativo, Qt::AlignCenter);

    layoutSport = new QGridLayout();
    //layoutSport

    layoutFinestra->addLayout(layoutSport);
    setLayout(layoutFinestra);
}

FinestraSceltaSport::~FinestraSceltaSport() {
    delete layoutFinestra;
}
