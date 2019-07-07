#include "widgetricerca.h"
#include "deepptr.h"
#include "contenitore.h"
#include "delegatebottone.h"
#include "delegatemodifica.h"
#include "contenitore.h"
#include "allenamento.h"
#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"
#include "triathlon.h"
#include "dialogallenamento.h"
#include "dialognuoto.h"
#include "dialogciclismo.h"
#include "dialogcorsa.h"
#include "dialogtriathlon.h"
#include "modeltabellaallenamenti.h"
#include "sortfilterproxymodelallenamenti.h"
#include <memory>
#include <QGroupBox>
#include <QRadioButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QString>
#include <QStringList>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>

WidgetRicerca::WidgetRicerca(Contenitore<std::shared_ptr<Persona>>& cp_,
                             Contenitore<DeepPtr<Allenamento>>& ca_,
                             QWidget* parent)
    : QWidget (parent), cp(cp_), ca(ca_)
{
    layoutPrincipale = new QVBoxLayout;

    boxRicerca = new QGroupBox("RICERCA");
    layoutComponentiRicerca = new QVBoxLayout;

    rbAtleta = new QRadioButton("Atleta");
    rbNuoto = new QRadioButton("Nuoto");
    rbCorsa = new QRadioButton("Corsa");
    rbCiclismo = new QRadioButton("Ciclismo");
    rbTriathlon = new QRadioButton("Triathlon");
    layoutRadioSport = new QHBoxLayout();
    layoutRadioSport->addWidget(rbAtleta);
    layoutRadioSport->addWidget(rbNuoto);
    layoutRadioSport->addWidget(rbCorsa);
    layoutRadioSport->addWidget(rbCiclismo);
    layoutRadioSport->addWidget(rbTriathlon);
    layoutRadioSport->setAlignment(Qt::AlignLeft);
    rbAtleta->setChecked(true);
    layoutComponentiRicerca->addLayout(layoutRadioSport);

    layoutBoxFormRicerca = new QGridLayout;
    layoutBoxFormRicerca->addWidget(costruzioneFormPersona(),0,0);
    layoutBoxFormRicerca->addWidget(costruzioneFormNuoto(),0,1);
    layoutBoxFormRicerca->addWidget(costruzioneFormCiclismo(),1,0);
    layoutBoxFormRicerca->addWidget(costruzioneFormCorsa(),1,1);
    layoutBoxFormRicerca->setColumnStretch(0,1);
    layoutBoxFormRicerca->setColumnStretch(1,1);
    layoutBoxFormRicerca->setRowStretch(0,1);
    layoutBoxFormRicerca->setRowStretch(1,1);
    layoutComponentiRicerca->addLayout(layoutBoxFormRicerca);

    // di default è selezionato il radiobutton atleta quindi disabilito i groupBox relativi agli sport
    boxNuoto->setEnabled(false);
    boxCorsa->setEnabled(false);
    boxCiclismo->setEnabled(false);

    btnRicerca = new QPushButton("Cerca");
    layoutComponentiRicerca->addWidget(btnRicerca);
    layoutComponentiRicerca->setAlignment(btnRicerca, Qt::AlignHCenter);

    boxRicerca->setLayout(layoutComponentiRicerca);

    layoutPrincipale->addWidget(boxRicerca);
    tabellaRicerca = new QTableView();
    layoutPrincipale->addWidget(tabellaRicerca);

    setLayout(layoutPrincipale);

    modello = new ModelTabellaAllenamenti(ca);
    proxy = new SortFilterProxyModelAllenamenti(ca);
    proxy->setSourceModel(modello);
    tabellaRicerca->setModel(proxy);
    delegatoEl = new DelegateEliminazione;
    delegatoMod = new DelegateModifica;
    tabellaRicerca->setItemDelegateForColumn(8, delegatoEl);
    tabellaRicerca->setItemDelegateForColumn(9, delegatoMod);
    tabellaRicerca->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // segnali e slot relativi ai radioButton (gestione visualizzazione box allenamenti)
    connect(rbAtleta, SIGNAL(clicked()), this, SLOT(selezioneGroupBox()));
    connect(rbNuoto, SIGNAL(clicked()), this, SLOT(selezioneGroupBox()));
    connect(rbCiclismo, SIGNAL(clicked()), this, SLOT(selezioneGroupBox()));
    connect(rbCorsa, SIGNAL(clicked()), this, SLOT(selezioneGroupBox()));
    connect(rbTriathlon, SIGNAL(clicked()), this, SLOT(selezioneGroupBox()));

    // segnali e slot relativi agli spinBox (controllo disparità valori tra i min e i max)
    connect(spinMinMagnesio, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));
    connect(spinMinDurata, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));
    connect(spinMinStile, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));
    connect(spinMinRana, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));
    connect(spinMinDorso, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));
    connect(spinMinSalita, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));
    connect(spinMinDiscesa, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));
    connect(spinMinPianura, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));
    connect(spinMinStrada, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));
    connect(spinMinSterrato, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxOverflowMin(int)));

    connect(spinMaxMagnesio, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));
    connect(spinMaxDurata, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));
    connect(spinMaxStile, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));
    connect(spinMaxRana, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));
    connect(spinMaxDorso, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));
    connect(spinMaxSalita, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));
    connect(spinMaxDiscesa, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));
    connect(spinMaxPianura, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));
    connect(spinMaxStrada, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));
    connect(spinMaxSterrato, SIGNAL(valueChanged(int)), this, SLOT(gestioneSpinBoxUnderflowMax(int)));

    // segnali e slot relativi alla gestione delle date
    connect(deDataInizio, SIGNAL(dateChanged(const QDate&)), this, SLOT(gestioneDate(const QDate&)));
    connect(deDataFine, SIGNAL(dateChanged(const QDate&)), this, SLOT(gestioneDate(const QDate&)));

    // segnali e slot relativi alla ricera degli allenamenti
    connect(btnRicerca, SIGNAL(clicked()), this, SLOT(avvioRicerca()));
    connect(this, SIGNAL(allenamentoMin(Allenamento*)),
            proxy, SLOT(setAllenamentoMinore(Allenamento*)));
    connect(this, SIGNAL(allenamentoMax(Allenamento*)),
            proxy, SLOT(setAllenamentoMaggiore(Allenamento*)));
    connect(this, SIGNAL(selezioneTipo(int)), proxy, SLOT(setTipoSort(int)));

    // segnali e slot relativi alla modifica e all'eliminazione
    // di un elemento dalla tabella dei risulati

    // il delegate avverte che l'utente ha cliccato un bottone e vuole eliminare una riga
    connect(delegatoEl, SIGNAL(avvisoEliminazione(int)), this, SLOT(ricevutaNotificaEliminazioneRiga(int)));
    // se l'utente conferma l'eliminazione viene avertito il delegate
    connect(this, SIGNAL(rimuovereRiga(int)), delegatoEl, SLOT(slotEliminazione(int)));
    // il delegate avverte il model di rimuovere la riga desiderata
    connect(delegatoEl, SIGNAL(eliminaRiga(int)), modello, SLOT(eliminazioneAllenamento(int)));

    // 'Eventi' relativi alla modifica di un allenamento
    connect(delegatoMod, SIGNAL(avvisoModifica(int)), this, SLOT(avviaDialogModifica(int)));
}

ModelTabellaAllenamenti* WidgetRicerca::getModello() const {
    return modello;
}

SortFilterProxyModelAllenamenti* WidgetRicerca::getProxy() const {
    return proxy;
}

QGroupBox* WidgetRicerca::costruzioneFormPersona() {
    boxPersona = new QGroupBox("PERSONA");
    lPersona = new QFormLayout;

    cmbAtleti = new QComboBox;
    QStringList atleti;
    Contenitore<std::shared_ptr<Persona>>::iterator it = cp.begin();
    for(; it != cp.end(); it++)
        atleti << QString::fromStdString((*it)->getNome()) + " " +
                  QString::fromStdString((*it)->getCognome()) + " " +
                  QString::fromStdString((*it)->getSessoCarUtf8());
    cmbAtleti->addItems(atleti);
    lPersona->addRow("Atleta:", cmbAtleti);

    QFormLayout *lDataInizio = new QFormLayout, *lDataFine = new QFormLayout;
    deDataInizio = new QDateEdit(QDate(1990,1,1));
    deDataInizio->setCalendarPopup(true);
    lDataInizio->addRow("Dal:", deDataInizio);
    deDataFine = new QDateEdit(QDate::currentDate());
    deDataFine->setCalendarPopup(true);
    lDataFine->addRow("Al:", deDataFine);
    lDate= new QHBoxLayout;
    lDate->addLayout(lDataInizio);
    lDate->addLayout(lDataFine);
    lPersona->addRow(lDate);

    spinMinDurata = new QSpinBox();
    spinMinDurata->setRange(1, 1440);
    spinMaxDurata = new QSpinBox();
    spinMaxDurata->setRange(1, 1440);
    spinMaxDurata->setValue(1440);
    lDurata = new QHBoxLayout;
    QFormLayout *lMinDurata = new QFormLayout, *lMaxDurata = new QFormLayout;
    lMinDurata->addRow("Durata min:", spinMinDurata);
    lMaxDurata->addRow("Durata max:", spinMaxDurata);
    lDurata->addLayout(lMinDurata);
    lDurata->addLayout(lMaxDurata);
    lPersona->addRow(lDurata);

    lMagnesio =  new QHBoxLayout;
    spinMinMagnesio = new QSpinBox();
    spinMaxMagnesio = new QSpinBox();
    spinMinMagnesio->setRange(0, 350);
    spinMaxMagnesio->setRange(0, 350);
    spinMaxMagnesio->setValue(350);
    QFormLayout *lMinMgnesio = new QFormLayout, *lMaxMgnesio = new QFormLayout;
    lMinMgnesio->addRow("Min magnesio:", spinMinMagnesio);
    lMaxMgnesio->addRow("Max magnesio:", spinMaxMagnesio);
    lMagnesio->addLayout(lMinMgnesio);
    lMagnesio->addLayout(lMaxMgnesio);
    lPersona->addRow(lMagnesio);

    boxPersona->setLayout(lPersona);
    return  boxPersona;
}

QGroupBox* WidgetRicerca::costruzioneFormNuoto() {
    boxNuoto = new QGroupBox("NUOTO");
    lNuoto = new QHBoxLayout;

    QFormLayout *lMin = new QFormLayout, *lMax = new QFormLayout;
    spinMinStile = new QSpinBox;
    spinMinStile->setRange(0, 400);
    lMin->addRow("Vasche Stile (min):", spinMinStile);
    spinMinRana = new QSpinBox;
    spinMinRana->setRange(0, 400);
    lMin->addRow("Vasche Rana (min):", spinMinRana);
    spinMinDorso = new QSpinBox;
    spinMinDorso->setRange(0, 400);
    lMin->addRow("Vasche Dorso (min):", spinMinDorso);
    lNuoto->addLayout(lMin);

    spinMaxStile = new QSpinBox;
    spinMaxStile->setRange(0, 400);
    spinMaxStile->setValue(400);
    lMax->addRow("Vasche Stile (max):", spinMaxStile);
    spinMaxRana = new QSpinBox;
    spinMaxRana->setRange(0, 400);
    spinMaxRana->setValue(400);
    lMax->addRow("Vasche Rana (max):", spinMaxRana);
    spinMaxDorso = new QSpinBox;
    spinMaxDorso->setRange(0, 400);
    spinMaxDorso->setValue(400);
    lMax->addRow("Vasche Dorso (max):", spinMaxDorso);
    lNuoto->addLayout(lMax);

    boxNuoto->setLayout(lNuoto);
    return boxNuoto;
}

QGroupBox* WidgetRicerca::costruzioneFormCiclismo() {
    boxCiclismo = new QGroupBox("CICLISMO");
    lCiclismo = new QHBoxLayout;

    QFormLayout *lMin = new QFormLayout, *lMax = new QFormLayout;
    spinMinSalita = new QSpinBox;
    spinMinSalita->setRange(0, 400);
    lMin->addRow("Km salita (min):", spinMinSalita);
    spinMinDiscesa = new QSpinBox;
    spinMinDiscesa->setRange(0, 400);
    lMin->addRow("Km discesa (min):", spinMinDiscesa);
    spinMinPianura = new QSpinBox;
    spinMinPianura->setRange(0, 400);
    lMin->addRow("Km pianura (min):", spinMinPianura);
    lCiclismo->addLayout(lMin);

    spinMaxSalita = new QSpinBox;
    spinMaxSalita->setRange(0, 400);
    spinMaxSalita->setValue(400);
    lMax->addRow("Km salita (max):", spinMaxSalita);
    spinMaxDiscesa = new QSpinBox;
    spinMaxDiscesa->setRange(0, 400);
    spinMaxDiscesa->setValue(400);
    lMax->addRow("Km discesa (max):", spinMaxDiscesa);
    spinMaxPianura = new QSpinBox;
    spinMaxPianura->setRange(0, 400);
    spinMaxPianura->setValue(400);
    lMax->addRow("Km pianura (max):", spinMaxPianura);
    lCiclismo->addLayout(lMax);

    boxCiclismo->setLayout(lCiclismo);
    return boxCiclismo;
}

QGroupBox* WidgetRicerca::costruzioneFormCorsa() {
    boxCorsa = new QGroupBox("CORSA");
    lCorsa = new QHBoxLayout;

    QFormLayout *lMin = new QFormLayout, *lMax = new QFormLayout;
    spinMinStrada = new QSpinBox;
    spinMinStrada->setRange(0, 400);
    lMin->addRow("Km strada (min):", spinMinStrada);
    spinMinSterrato = new QSpinBox;
    spinMinSterrato->setRange(0, 400);
    lMin->addRow("Km sterrato (min):", spinMinSterrato);
    lCorsa->addLayout(lMin);

    spinMaxStrada = new QSpinBox;
    spinMaxStrada->setRange(0, 400);
    spinMaxStrada->setValue(400);
    lMax->addRow("Km strada (max):", spinMaxStrada);
    spinMaxSterrato = new QSpinBox;
    spinMaxSterrato->setRange(0, 400);
    spinMaxSterrato->setValue(400);
    lMax->addRow("Km sterrato (max):", spinMaxSterrato);
    lCorsa->addLayout(lMax);

    boxCorsa->setLayout(lCorsa);
    return boxCorsa;
}

void WidgetRicerca::stampaMessaggioErrore(QString messaggio) const {
    QMessageBox mes;
    mes.setIcon(QMessageBox::Information);
    mes.setText("Errore!");
    mes.setInformativeText(messaggio);
    mes.setStandardButtons(QMessageBox::Ok);
    mes.exec();
}

bool WidgetRicerca::verificaNuoto() const {
    if(spinMinRana->value() + spinMinStile->value() + spinMinDorso->value() == 0) {
        stampaMessaggioErrore(
                    QString("Ogni atleta deve aver portato a compimento almeno una vasca ") +
                    QString("in un qualsiasi stile."));
        return false;
    }
    return true;
}

bool WidgetRicerca::verificaCiclismo() const {
    if(spinMinSalita->value() + spinMinPianura->value() + spinMinDiscesa->value() == 0) {
        stampaMessaggioErrore(
                    QString("Ogni atleta deve aver portato a compimento almeno 1 km ") +
                    QString("in salita o in discesa oppure in pianura."));
        return false;
    }
    return true;
}

bool WidgetRicerca::verificaCorsa() const {
    if(spinMinSterrato->value() + spinMinStrada->value() == 0) {
        stampaMessaggioErrore(
                    QString("Ogni atleta deve aver portato a compimento almeno 1 km ") +
                    QString("su strada o sullo sterrato."));
        return false;
    }
    return true;
}

bool WidgetRicerca::verificaTriathlon() const {
    if( !verificaNuoto() )
        return  false;
    if( ! verificaCiclismo() )
        return false;
    if( !verificaCorsa() )
        return false;
    return  true;
}

void WidgetRicerca::selezioneGroupBox() {
    QObject *sender = QObject::sender();

    if(sender == rbAtleta){
        boxNuoto->setEnabled(false);
        boxCiclismo->setEnabled(false);
        boxCorsa->setEnabled(false);
    } else if( sender == rbNuoto ){
        boxNuoto->setEnabled(true);
        boxCiclismo->setEnabled(false);
        boxCorsa->setEnabled(false);
    } else if(sender == rbCorsa) {
        boxNuoto->setEnabled(false);
        boxCiclismo->setEnabled(false);
        boxCorsa->setEnabled(true);
    } else if( sender == rbCiclismo ) {
        boxNuoto->setEnabled(false);
        boxCiclismo->setEnabled(true);
        boxCorsa->setEnabled(false);
    } else if( sender == rbTriathlon ) {
        boxNuoto->setEnabled(true);
        boxCiclismo->setEnabled(true);
        boxCorsa->setEnabled(true);
    }
}

void WidgetRicerca::gestioneSpinBoxOverflowMin(int) {
    QObject *sender = QObject::sender();

    if(sender == spinMinMagnesio) {
        if(spinMinMagnesio->value() > spinMaxMagnesio->value())
            spinMaxMagnesio->setValue(spinMinMagnesio->value());
    } else if(sender == spinMinDurata) {
        if(spinMinDurata->value() > spinMaxDurata->value())
            spinMaxDurata->setValue(spinMinDurata->value());
    } else if(sender == spinMinStile) {
        if(spinMinStile->value() > spinMaxStile->value())
            spinMaxStile->setValue(spinMinStile->value());
    } else if(sender == spinMinRana) {
        if(spinMinRana->value() > spinMaxRana->value())
            spinMaxRana->setValue(spinMinRana->value());
    } else if(sender == spinMinDorso) {
        if(spinMinDorso->value() > spinMaxDorso->value())
            spinMaxDorso->setValue(spinMinDorso->value());
    } else if(sender == spinMinSalita) {
        if(spinMinSalita->value() > spinMaxSalita->value())
            spinMaxSalita->setValue(spinMinSalita->value());
    } else if(sender == spinMinDiscesa) {
        if(spinMinDiscesa->value() > spinMaxDiscesa->value())
            spinMaxDiscesa->setValue(spinMinDiscesa->value());
    } else if(sender == spinMinPianura) {
        if(spinMinPianura->value() > spinMaxPianura->value())
            spinMaxPianura->setValue(spinMinPianura->value());
    } else if(sender == spinMinStrada) {
        if(spinMinStrada->value() > spinMaxStrada->value())
            spinMaxStrada->setValue(spinMinStrada->value());
    } else if(sender == spinMinSterrato) {
        if(spinMinSterrato->value() > spinMaxSterrato->value())
            spinMaxSterrato->setValue(spinMinSterrato->value());
    }
}

void WidgetRicerca::gestioneSpinBoxUnderflowMax(int) {
    QObject *sender = QObject::sender();

    if(sender == spinMaxMagnesio) {
        if(spinMinMagnesio->value() > spinMaxMagnesio->value())
            spinMinMagnesio->setValue(spinMaxMagnesio->value());
    } else if(sender == spinMaxDurata) {
        if(spinMinDurata->value() > spinMaxDurata->value())
            spinMinDurata->setValue(spinMaxDurata->value());
    } else if(sender == spinMaxStile) {
        if(spinMinStile->value() > spinMaxStile->value())
            spinMinStile->setValue(spinMaxStile->value());
    } else if(sender == spinMaxRana) {
        if(spinMinRana->value() > spinMaxRana->value())
            spinMinRana->setValue(spinMaxRana->value());
    } else if(sender == spinMaxDorso) {
        if(spinMinDorso->value() > spinMaxDorso->value())
            spinMinDorso->setValue(spinMaxDorso->value());
    } else if(sender == spinMaxSalita) {
        if(spinMinSalita->value() > spinMaxSalita->value())
            spinMinSalita->setValue(spinMaxSalita->value());
    } else if(sender == spinMaxDiscesa) {
        if(spinMinDiscesa->value() > spinMaxDiscesa->value())
            spinMinDiscesa->setValue(spinMaxDiscesa->value());
    } else if(sender == spinMaxPianura) {
        if(spinMinPianura->value() > spinMaxPianura->value())
            spinMinPianura->setValue(spinMaxPianura->value());
    } else if(sender == spinMaxStrada) {
        if(spinMinStrada->value() > spinMaxStrada->value())
            spinMinStrada->setValue(spinMaxStrada->value());
    } else if(sender == spinMaxSterrato) {
        if(spinMinSterrato->value() > spinMaxSterrato->value())
            spinMinSterrato->setValue(spinMaxSterrato->value());
    }
}

void WidgetRicerca::gestioneDate(const QDate &date) {
    Q_UNUSED(date);
    QObject *sender = QObject::sender();
    if(sender == deDataInizio && deDataInizio->date() > deDataFine->date())
        deDataFine->setDate(deDataInizio->date());
    else if(sender == deDataFine && deDataInizio->date() > deDataFine->date())
        deDataInizio->setDate(deDataFine->date());
}


/*
 * Non necessita di fare alcuna delete. Ci pensano i metodi dell'oggetto
 * proxy a deallocare la memoria dei puntatori che la funzione
 * gli passa come come parametri.
 */
void WidgetRicerca::avvioRicerca() {
    Allenamento *alMin = nullptr, *alMax = nullptr;

    bool trovato = false;
    Contenitore<DeepPtr<Allenamento>>::iterator it = ca.begin();
    std::shared_ptr<Persona> p;
    for(int i = 0; it != ca.end() && !trovato;  ++i) {
        if( (*it)->getAtleta().toStringUtf8CarSesso() == cmbAtleti->currentText().toStdString() ) {
            p = (*it)->getSharedAtleta();
            trovato = true;
        } else
            ++it;
    }

    if(!trovato) {
        emit selezioneTipo(0);
        emit allenamentoMax(nullptr);
        emit allenamentoMin(nullptr);
        proxy->invalidate();
        return;
    }

    if(rbAtleta->isChecked()) {
        emit selezioneTipo(0);
        /*
         * Se l'utente ha selezionato il radiobutton rbAtleta
         * vuole ricercare tutti i tipi di allenamento relativi ad un qualsiasi
         * atleta. Posso passare un qualsiasi oggetto che abbia un tipo dinamico
         * che è sottotipo di Allenamento*, la funzione filterAcceptsRow() del
         * proxy userà solamente i metodi Allenamento::operator>=() e
         * Allenamento::operator<=(). Adesso viene passato un oggetto che ha
         * TD == Corsa* ma per ciò che è appena stato detto potrebbero andare
         * bene anche i tipi dinamici Nuoto*, Ciclismo*, Triathlon* ...
         */
        alMin = new Corsa(p,
                          static_cast<unsigned int>(spinMinDurata->value()),
                          Data(deDataInizio->date().year(),
                               deDataInizio->date().month(),
                               deDataInizio->date().day()),
                          static_cast<unsigned int>(spinMinMagnesio->value()),
                          static_cast<unsigned int>(1), // è di corsa, in questo caso è arbitrario
                          static_cast<unsigned int>(1));// arbitrario
        emit allenamentoMin(alMin);

        alMax = new Corsa(p,
                          static_cast<unsigned int>(spinMaxDurata->value()),
                          Data(deDataFine->date().year(),
                               deDataFine->date().month(),
                               deDataFine->date().day()),
                          static_cast<unsigned int>(spinMaxMagnesio->value()),
                          static_cast<unsigned int>(1),// arbitrario
                          static_cast<unsigned int>(1));// arbitrario
        emit allenamentoMax(alMax);
    } else if(rbNuoto->isChecked()) {
        if( !verificaNuoto())
            return;
        emit selezioneTipo(1);
        alMin = new Nuoto(p,
                          static_cast<unsigned int>(spinMinDurata->value()),
                          Data(deDataInizio->date().year(),
                               deDataInizio->date().month(),
                               deDataInizio->date().day()),
                          static_cast<unsigned int>(spinMinMagnesio->value()),
                          static_cast<unsigned int>(spinMinStile->value()),
                          static_cast<unsigned int>(spinMinRana->value()),
                          static_cast<unsigned int>(spinMinDorso->value()));
        emit allenamentoMin(alMin);

        alMax = new Nuoto(p,
                          static_cast<unsigned int>(spinMaxDurata->value()),
                          Data(deDataFine->date().year(),
                               deDataFine->date().month(),
                               deDataFine->date().day()),
                          static_cast<unsigned int>(spinMaxMagnesio->value()),
                          static_cast<unsigned int>(spinMaxStile->value()),
                          static_cast<unsigned int>(spinMaxRana->value()),
                          static_cast<unsigned int>(spinMaxDorso->value()));
        emit allenamentoMax(alMax);

    } else if(rbCiclismo->isChecked()) {
        if(!verificaCiclismo())
            return;
        emit selezioneTipo(2);
        alMin = new Ciclismo(p,
                             static_cast<unsigned int>(spinMinDurata->value()),
                             Data(deDataInizio->date().year(),
                                  deDataInizio->date().month(),
                                  deDataInizio->date().day()),
                             static_cast<unsigned int>(spinMinMagnesio->value()),
                             static_cast<unsigned int>(spinMinSalita->value()),
                             static_cast<unsigned int>(spinMinPianura->value()),
                             static_cast<unsigned int>(spinMinDiscesa->value()));
        emit allenamentoMin(alMin);

        alMax = new Ciclismo(p,
                             static_cast<unsigned int>(spinMaxDurata->value()),
                             Data(deDataFine->date().year(),
                                  deDataFine->date().month(),
                                  deDataFine->date().day()),
                             static_cast<unsigned int>(spinMaxMagnesio->value()),
                             static_cast<unsigned int>(spinMaxSalita->value()),
                             static_cast<unsigned int>(spinMaxPianura->value()),
                             static_cast<unsigned int>(spinMaxDiscesa->value()));
        emit allenamentoMax(alMax);
    } else if(rbCorsa->isChecked()) {
        if(!verificaCorsa())
            return;
        emit selezioneTipo(3);
        alMin = new Corsa(p,
                          static_cast<unsigned int>(spinMinDurata->value()),
                          Data(deDataInizio->date().year(),
                               deDataInizio->date().month(),
                               deDataInizio->date().day()),
                          static_cast<unsigned int>(spinMinMagnesio->value()),
                          static_cast<unsigned int>(spinMinSterrato->value()),
                          static_cast<unsigned int>(spinMinStrada->value()));
        emit allenamentoMin(alMin);

        alMax = new Corsa(p,
                          static_cast<unsigned int>(spinMaxDurata->value()),
                          Data(deDataFine->date().year(),
                               deDataFine->date().month(),
                               deDataFine->date().day()),
                          static_cast<unsigned int>(spinMaxMagnesio->value()),
                          static_cast<unsigned int>(spinMaxSterrato->value()),
                          static_cast<unsigned int>(spinMaxStrada->value()));
        emit allenamentoMax(alMax);
    } else if(rbTriathlon->isChecked()) {
        if( !verificaTriathlon() )
            return;
        emit selezioneTipo(4);
        alMin = new Triathlon(p,
                              static_cast<unsigned int>(spinMinDurata->value()),
                              Data(deDataInizio->date().year(),
                                   deDataInizio->date().month(),
                                   deDataInizio->date().day()),
                              static_cast<unsigned int>(spinMinMagnesio->value()),
                              static_cast<unsigned int>(spinMinStile->value()),
                              static_cast<unsigned int>(spinMinRana->value()),
                              static_cast<unsigned int>(spinMinDorso->value()),
                              static_cast<unsigned int>(spinMinSalita->value()),
                              static_cast<unsigned int>(spinMinPianura->value()),
                              static_cast<unsigned int>(spinMinDiscesa->value()),
                              static_cast<unsigned int>(spinMinSterrato->value()),
                              static_cast<unsigned int>(spinMinStrada->value()));
        emit allenamentoMin(alMin);

        alMax = new Triathlon(p,
                              static_cast<unsigned int>(spinMaxDurata->value()),
                              Data(deDataFine->date().year(),
                                   deDataFine->date().month(),
                                   deDataFine->date().day()),
                              static_cast<unsigned int>(spinMaxMagnesio->value()),
                              static_cast<unsigned int>(spinMaxStile->value()),
                              static_cast<unsigned int>(spinMaxRana->value()),
                              static_cast<unsigned int>(spinMaxDorso->value()),
                              static_cast<unsigned int>(spinMaxSalita->value()),
                              static_cast<unsigned int>(spinMaxPianura->value()),
                              static_cast<unsigned int>(spinMaxDiscesa->value()),
                              static_cast<unsigned int>(spinMaxSterrato->value()),
                              static_cast<unsigned int>(spinMaxStrada->value()));
        emit allenamentoMax(alMax);
    }

    proxy->invalidate();
}

void WidgetRicerca::ricevutaNotificaEliminazioneRiga(int riga) {
    QMessageBox boxConfermaEliminazione;
    boxConfermaEliminazione.setIcon(QMessageBox::Question);
    boxConfermaEliminazione.setText("ATTENZIONE:");
    boxConfermaEliminazione.setInformativeText("Vuoi davvero eliminare l'allenamento? L'operazione è definitiva");
    boxConfermaEliminazione.addButton("No", QMessageBox::NoRole);
    boxConfermaEliminazione.addButton("Sì", QMessageBox::YesRole);
    int scelta = boxConfermaEliminazione.exec();
    if(scelta) {
        // la riga che il delegate passa fa riferimento alla riga
        // del proxy, è necessario quindi convertire la riga
        // del proxy nella riga del modello sorgente
        riga = proxy->mapToSource(proxy->index(riga,0)).row();
        emit rimuovereRiga(riga);
    }
}

void WidgetRicerca::avviaDialogModifica(int riga) {
    DialogAllenamento* da;

    // la riga che il delegate passa fa riferimento alla riga
    // del proxy, è necessario quindi convertire la riga
    // del proxy nella riga del modello sorgente
    riga = proxy->mapToSource(proxy->index(riga,0)).row();
    Allenamento* a = ca.At(riga).get();

    if(dynamic_cast<Triathlon*>(a)) {
        da = new DialogTriathlon(cp, ca, true,riga);
    } else if(dynamic_cast<Nuoto*>(a)) {
        da = new DialogNuoto(cp, ca, true,riga);
    } else if(dynamic_cast<Ciclismo*>(a)) {
        da = new DialogCiclismo(cp, ca, true,riga);
    } else if(dynamic_cast<Corsa*>(a)) {
        da = new DialogCorsa(cp, ca, true,riga);
    } else {
        return;
    }

    da->exec();
    delete da;
    // nessuna delete su 'a' perché get ritorna un puntatore grezzo, non copia profonda
    // corrispondente a quello contenuto in DeepPtr<Allenamento>
}


void WidgetRicerca::rimozioneRigaEliminataModel(int p) {
    Q_UNUSED(p);
    proxy->invalidate();
}

void WidgetRicerca::aggiornamentoComboBoxAtleti(int riga) {
    cmbAtleti->removeItem(riga);
}

void WidgetRicerca::rimozioneRigheEliminateModel(std::shared_ptr<Persona> p) {
    Q_UNUSED(p);
    proxy->invalidate();
}
