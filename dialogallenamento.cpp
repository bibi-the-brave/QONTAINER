#include "dialogallenamento.h"
#include <QStringList>
#include <QMessageBox>
#include "contenitore.h"
#include <memory>
#include "persona.h"
#include <QDate>
#include <QDateEdit>
#include "allenamento.h"

DialogAllenamento::DialogAllenamento(
        Contenitore<std::shared_ptr<Persona>>& cp_,
        Contenitore<DeepPtr<Allenamento>>& ca_,
        bool modifica_,
        int rigaMod_,
        QWidget* parent)
    : QDialog(parent), cp(cp_), ca(ca_), modifica(modifica_), rigaMod(rigaMod_)
{
    layoutPrincipale = new QVBoxLayout;

    lblTitolo = new QLabel; //il testo viene settato dalle sottoclassi che derivano DialogAllenamento
    layoutPrincipale->addWidget(lblTitolo);
    layoutPrincipale->setAlignment(lblTitolo, Qt::AlignHCenter);

    lFormAllenamento = new QFormLayout;

    lblAtleta = new QLabel("Atleta:");
    cmbAtleti = new QComboBox();
    QStringList atleti;
    Contenitore<std::shared_ptr<Persona>>::iterator it = cp.begin();
    for(; it != cp.end(); it++)
        atleti << QString::fromStdString((*it)->getNome()) + " " +
                  QString::fromStdString((*it)->getCognome()) + " " +
                  QString::fromStdString((*it)->getSessoCarUtf8());
    cmbAtleti->addItems(atleti);
    lFormAllenamento->addRow(lblAtleta, cmbAtleti);

    lblData = new QLabel("Data:");
    deData = new QDateEdit(QDate::currentDate());
    deData->setCalendarPopup(true);
    deData->setMaximumDate(QDate::currentDate());
    lFormAllenamento->addRow(lblData, deData);

    lblDurata = new QLabel("Durata (in min.):");
    spinDurata = new QSpinBox();
    spinDurata->setRange(1, 1440);
    lFormAllenamento->addRow(lblDurata, spinDurata);

    lblMagnesio =  new QLabel("Mg magnesio assunti:");
    spinMagnesio = new QSpinBox();
    spinMagnesio->setRange(0, 350);
    lFormAllenamento->addRow(lblMagnesio, spinMagnesio);

    layoutPrincipale->addLayout(lFormAllenamento);

    setLayout(layoutPrincipale);

    if(modifica)
        compilazioneFormModifica();
}

void DialogAllenamento::aggiungiBottoni() {
    lBottoni = new QHBoxLayout;
    bConferma = new QPushButton("OK");
    bReset = new QPushButton("Reset");
    lBottoni->addWidget(bConferma);
    lBottoni->addWidget(bReset);
    layoutPrincipale->addLayout(lBottoni);
}

void DialogAllenamento::dialogErroreForm() const {
    QMessageBox mes;
    mes.setIcon(QMessageBox::Information);
    mes.setText("Errore!");
    mes.setInformativeText("L'allenamento deve durare almeno un minuto.");
    mes.setStandardButtons(QMessageBox::Ok);
    mes.exec();
}

void DialogAllenamento::compilazioneFormModifica() {
    Allenamento* a = ca.At(rigaMod).get();
    int i = cmbAtleti->findText(
                QString::fromStdString(a->getAtleta().getNome() + " "
                                       + a->getAtleta().getCognome() + " "
                                       + a->getAtleta().getSessoCarUtf8())
    );
    cmbAtleti->setCurrentIndex(i);
    cmbAtleti->setEnabled(false);//non lascio modificare gli atleti ma solo i loro campi dati

    QDate data(a->getData().getY(), a->getData().getM(), a->getData().getD());
    deData->setDate(data);

    spinDurata->setValue(static_cast<int>(a->getDurata()));
    spinMagnesio->setValue(static_cast<int>(a->getMgMagnesioAssunti()));
}

void DialogAllenamento::reset() {
    cmbAtleti->setCurrentIndex(0);
    deData->setDate(QDate::currentDate());
    spinDurata->setValue(0);
    spinMagnesio->setValue(0);
}

void DialogAllenamento::controlloForm(bool& controllo) const {
    if( !spinDurata->value() )
        controllo = true;
    else
        controllo = false;
}

void DialogAllenamento::dialogErroreDoppione() const {
    QMessageBox mes;
    mes.setIcon(QMessageBox::Information);
    mes.setText("Errore!");
    mes.setInformativeText("Allenamento già presente.");
    mes.setStandardButtons(QMessageBox::Ok);
    mes.exec();
}

void DialogAllenamento::visualizzaMessaggioAllenamentoNonModificato() const {
    //l'utente ha lasciato l'atleta invariato
    QMessageBox mes;
    mes.setIcon(QMessageBox::Information);
    mes.setText("OK! Niente da modificare.");
    mes.setInformativeText("Non è stata effetuata alcuna modifica all'allenamento.");
    mes.setStandardButtons(QMessageBox::Ok);
    mes.exec();
}
