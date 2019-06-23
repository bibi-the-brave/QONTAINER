#include "dialogatleta.h"
#include <QtGlobal>
#include <QRegExp>
#include <QRegExpValidator>
#include <QHBoxLayout>
#include <memory>
#include <QMessageBox>

#include "modeltabellaatleti.h"
#include "persona.h"

//PRE: se modifica_ == true => rigaMod_ >= 0
DialogAtleta::DialogAtleta(Contenitore<std::shared_ptr<Persona>>& a,
                           bool modifica_,
                           int rigaMod_,
                           QWidget* parent)
    : QDialog(parent), atleti(a), modifica(modifica_), rigaMod(modifica_ ? rigaMod_ : 0)
{
    if(!modifica)
        lblTitolo = new QLabel("CREAZIONE ATLETA");
    else
        lblTitolo = new QLabel("MODIFICA ATLETA");
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
    layoutRadioButton->setAlignment(Qt::AlignLeft);

    bInserisci = new QPushButton("OK");
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

    if(modifica) {
        compilazioneFormModifica();
        connect(bInserisci, SIGNAL(clicked(bool)), this, SLOT(modificaAtleta(bool)));
    } else
        connect(bInserisci, SIGNAL(clicked(bool)), this, SLOT(inserimentoAtleta(bool)));

    connect(bAzzera, SIGNAL(clicked(bool)), this, SLOT(azzeramentoForm(bool)));
}

void DialogAtleta::compilazioneFormModifica() {
    auto a = atleti.At(rigaMod);
    leNome->setText(QString::fromStdString(a->getNome()));
    leCognome->setText(QString::fromStdString(a->getCognome()));
    if(!a->getSesso())
        rbUomo->setChecked(true);
    else
        rbDonna->setChecked(true);
}

void DialogAtleta::inserimentoAtleta(bool cliccato) {
    Q_UNUSED(cliccato);
    std::string nome = leNome->text().simplified().toStdString();
    std::string cognome = leCognome->text().simplified().toStdString();

    if( !verificaCampiNomeCognome(leNome->text().simplified(), leCognome->text().simplified()) )
        return;

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

bool DialogAtleta::verificaCampiNomeCognome(QString nome, QString cognome) const {
    if(nome == "" || cognome == "") {
        QMessageBox mes;
        mes.setIcon(QMessageBox::Information);
        mes.setText("Errore!");
        mes.setInformativeText("Compilare tutti i campi.");
        mes.setStandardButtons(QMessageBox::Ok);
        mes.exec();
        return false;
    }
    return true;
}

bool DialogAtleta::verificaAtletaPresente(std::shared_ptr<Persona>& persona) const {
    bool doppione = false;
    Contenitore<std::shared_ptr<Persona>>::iterator it = atleti.begin();
    for(; it != atleti.end() && !doppione; it++) {
        if( *(it->get()) == *(persona.get()) )
            return true;
    }
    return false;
}

void DialogAtleta::modificaAtleta(bool cliccato) {
    Q_UNUSED(cliccato);

    auto atletaSelezionato = atleti.At(static_cast<int>(rigaMod));

    std::string nome = leNome->text().simplified().toStdString();
    std::string cognome = leCognome->text().simplified().toStdString();
    if( !verificaCampiNomeCognome(leNome->text().simplified(), leCognome->text().simplified()) )
        return;
    bool sesso;
    if(rbUomo->isChecked())
        sesso = 0;
    else
        sesso = 1;

    auto persona = std::make_shared<Persona>(nome, cognome, sesso);

    if(*atletaSelezionato == *persona) { //l'utente ha lasciato l'atleta invariato
        QMessageBox mes;
        mes.setIcon(QMessageBox::Information);
        mes.setText("OK! Niente da modificare.");
        mes.setInformativeText("Non è stata effetuata alcuna modifica ai dati dell'atleta.");
        mes.setStandardButtons(QMessageBox::Ok);
        mes.exec();
        this->close();
        return; //lo metto perché è capitato che prima di eseguire close venga eseguita
        //la parte in cui si controlla doppione. Close penso perché close potrebbe essere multithread
    }

    // controlla che l'atleta creato non sia già presente nel contenitore
    bool doppione = verificaAtletaPresente(persona);

    if(doppione) {
        QMessageBox mes;
        mes.setIcon(QMessageBox::Information);
        mes.setText("Errore!");
        mes.setInformativeText("Impossibile modificare l'atleta perché identico ad uno già presente.");
        mes.setStandardButtons(QMessageBox::Ok);
        mes.exec();
    } else {
        //modifico l'atleta. Il model si aggiorna da solo
        atletaSelezionato->setNome(persona->getNome());
        atletaSelezionato->setCognome(persona->getCognome());
        atletaSelezionato->setSesso(persona->getSesso());
        this->close();
    }

}

void DialogAtleta::azzeramentoForm(bool cliccato) {
    Q_UNUSED(cliccato);
    leNome->setText("");
    leCognome->setText("");
}
