#include "dialoginserimentoatleta.h"
#include <QtGlobal>
#include <QRegExp>
#include <QRegExpValidator>
#include <QHBoxLayout>
#include <memory>
#include <QMessageBox>

#include "modeltabellaatleti.h"
#include "persona.h"

DialogInserimentoAtleta::DialogInserimentoAtleta(Contenitore<std::shared_ptr<Persona>>& a, QWidget* parent)
    : QDialog(parent), atleti(a)
{
    lblTitolo.setText("CREAZIONE ATLETA");
    lblNome.setText("Nome");
    lblCognome.setText("Cognome");
    lblSesso.setText("Sesso");

    rbUomo.setText("Uomo");
    rbDonna.setText("Donna");
    rbUomo.setChecked(true);
    QHBoxLayout *lGbSesso = new QHBoxLayout;
    lGbSesso->addWidget(&rbUomo);
    lGbSesso->addWidget(&rbDonna);
    //lGbSesso.stretch(2);
    gbSesso.setLayout(lGbSesso);

    bInserisci.setText("Inserisci");
    bAzzera.setText("Reset");

    layoutPrincipale.addWidget(&lblTitolo);
    layoutPrincipale.setAlignment(&lblTitolo, Qt::AlignHCenter);

    layoutForm.addRow(&lblNome, &leNome);
    layoutForm.addRow(&lblCognome, &leCognome);

    layoutForm.addRow(&lblSesso, &gbSesso);
    //lblSesso.setAlignment(Qt::AlignVCenter);

    layoutBottoniConferma.addWidget(&bInserisci);
    layoutBottoniConferma.addWidget(&bAzzera);

    layoutPrincipale.addLayout(&layoutForm);
    layoutPrincipale.addLayout(&layoutBottoniConferma);
    setLayout(&layoutPrincipale);

    //this->setFixedSize(QSize(this->width(),this->height()));

    connect(&bInserisci, SIGNAL(clicked(bool)), this, SLOT(inserimentoAtleta(bool)));
    connect(&bAzzera, SIGNAL(clicked(bool)), this, SLOT(azzeramentoForm(bool)));
}

void DialogInserimentoAtleta::inserimentoAtleta(bool cliccato) {
    Q_UNUSED(cliccato);
    std::string nome = leNome.text().toStdString();
    std::string cognome = leCognome.text().toStdString();
    bool sesso;

    if(rbUomo.isChecked())
        sesso = 0;
    else
        sesso = 1;

    // controlla che l'atleta non sia già presente nel contenitore
    auto persona = std::make_shared<Persona>(nome, cognome, sesso);
    bool doppione = false;
    Contenitore<std::shared_ptr<Persona>>::iterator it = atleti.begin();
    for(; it != atleti.end() && !doppione; it++) {
        if( *(it->get()) == *(persona.get()) )
            doppione = true;
    }

    if(doppione) {
        QMessageBox mes;
        mes.setIcon(QMessageBox::Information);
        mes.setText("Errore!");
        mes.setInformativeText("Impossibile inserire l'atleta perché già presente.");
        mes.setStandardButtons(QMessageBox::Ok);
        mes.exec();
    } else {
        atleti.pushBack(persona);
        emit reset();
        this->close();
    }
}

void DialogInserimentoAtleta::azzeramentoForm(bool cliccato) {
    Q_UNUSED(cliccato);
    leNome.setText("");
    leCognome.setText("");
}
