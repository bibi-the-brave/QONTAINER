#include "dialogallenamento.h"
#include <QStringList>
#include "contenitore.h"
#include <memory>
#include "persona.h"

DialogAllenamento::DialogAllenamento(
        Contenitore<std::shared_ptr<Persona>>& cp_,
        Contenitore<DeepPtr<Allenamento>>& ca_,
        QWidget* parent)
    : QDialog(parent), cp(cp_), ca(ca_)
{
    layoutPrincipale = new QVBoxLayout;

    lblTitolo = new QLabel;
    layoutPrincipale->addWidget(lblTitolo);
    layoutPrincipale->setAlignment(lblTitolo, Qt::AlignHCenter);

    lFormAllenamento = new QFormLayout;

    lblAtleta = new QLabel("Atleta:");
    cmbAtleti = new QComboBox();
    QStringList atleti;
    Contenitore<std::shared_ptr<Persona>>::iterator it = cp.begin();
    for(; it != cp.end(); it++)
        atleti << QString::fromStdString((*it)->getNome()) +
                  QString::fromStdString((*it)->getCognome());
    cmbAtleti->addItems(atleti);
    lFormAllenamento->addRow(lblAtleta, cmbAtleti);

    lblDurata = new QLabel("Durata (in min.):");
    spinDurata = new QSpinBox();
    spinDurata->setRange(0, 24);
    lFormAllenamento->addRow(lblDurata, spinDurata);

    lblMagnesio =  new QLabel("Mg magnesio assunti:");
    spinMagnesio = new QSpinBox();
    spinMagnesio->setRange(0, 350);
    lFormAllenamento->addRow(lblMagnesio, spinMagnesio);

    layoutPrincipale->addLayout(lFormAllenamento);

    setLayout(layoutPrincipale);
}

void DialogAllenamento::aggiungiBottoni() {
    lBottoni = new QHBoxLayout;
    bConferma = new QPushButton("OK");
    bReset = new QPushButton("Reset");
    lBottoni->addWidget(bConferma);
    lBottoni->addWidget(bReset);
    layoutPrincipale->addLayout(lBottoni);
}

void DialogAllenamento::reset() {
    cmbAtleti->setCurrentIndex(0);
    spinDurata->setValue(0);
    spinMagnesio->setValue(0);
}
