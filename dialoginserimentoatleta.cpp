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
    lblTitolo = new QLabel("CREAZIONE ATLETA");
    lblNome = new QLabel("Nome:");
    leNome = new QLineEdit();
    lblCognome = new QLabel("Cognome:");
    leCognome = new QLineEdit();
    lblSesso = new QLabel("Sesso:");

    rbUomo = new QRadioButton("Uomo");
    rbDonna = new QRadioButton("Donna");
    rbUomo->setChecked(true);
    layoutRadioButton = new QHBoxLayout();
    layoutRadioButton->addWidget(rbUomo);
    layoutRadioButton->addWidget(rbDonna);

    bInserisci = new QPushButton("Inserisci");
    bAzzera = new QPushButton("Reset");

    layoutPrincipale = new QVBoxLayout();
    layoutPrincipale->addWidget(lblTitolo);
    layoutPrincipale->setAlignment(lblTitolo, Qt::AlignHCenter);

    layoutForm = new QFormLayout();
    layoutForm->addRow(lblNome, leNome);
    layoutForm->addRow(lblCognome, leCognome);
    layoutForm->addRow(lblSesso, layoutRadioButton);
    layoutPrincipale->addLayout(layoutForm);

    layoutBottoniConferma = new QHBoxLayout;
    layoutBottoniConferma->addWidget(bInserisci);
    layoutBottoniConferma->addWidget(bAzzera);

    layoutPrincipale->addLayout(layoutBottoniConferma);
    setLayout(layoutPrincipale);

    QRegExp rx("^\\S+(\\s\\S+)+$");
    QValidator *validator = new QRegExpValidator(rx, this);

    leNome->setValidator(validator);
    leCognome->setValidator(validator);

    //this->setFixedSize(QSize(this->width(),this->height()));
    setWindowTitle("ATLETA");

    connect(bInserisci, SIGNAL(clicked(bool)), this, SLOT(inserimentoAtleta(bool)));
    connect(bAzzera, SIGNAL(clicked(bool)), this, SLOT(azzeramentoForm(bool)));
}

void DialogInserimentoAtleta::inserimentoAtleta(bool cliccato) {
    Q_UNUSED(cliccato);
    std::string nome = leNome->text().simplified().toStdString();
    std::string cognome = leCognome->text().simplified().toStdString();

    if(nome == "" || cognome == "") {
        QMessageBox mes;
        mes.setIcon(QMessageBox::Information);
        mes.setText("Errore!");
        mes.setInformativeText("Compilare tutti i campi.");
        mes.setStandardButtons(QMessageBox::Ok);
        mes.exec();
        return;
    }

    bool sesso;

    if(rbUomo->isChecked())
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
    leNome->setText("");
    leCognome->setText("");
}
