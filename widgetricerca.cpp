#include "widgetricerca.h"
#include "deepptr.h"
#include "contenitore.h"
#include "delegatebottone.h"
#include "contenitore.h"
#include "allenamento.h"
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

WidgetRicerca::WidgetRicerca(Contenitore<DeepPtr<Allenamento>>& ca_, QWidget* parent)
    : QWidget (parent), ca(ca_)
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
    tabellaRicerca->setModel(modello);
    delegato = new DelegateEliminazione;
    tabellaRicerca->setItemDelegateForColumn(8, delegato);
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
}


QGroupBox* WidgetRicerca::costruzioneFormPersona() {
    boxPersona = new QGroupBox("PERSONA");
    lPersona = new QFormLayout;

    cmbAtleti = new QComboBox;
    QStringList atletiDup/*potrebbe contenere duplicati*/, atleti;
    Contenitore<DeepPtr<Allenamento>>::iterator it = ca.begin();
    for(; it != ca.end(); it++)
        atletiDup << QString::fromStdString((*it)->getAtleta().getNome()) + " " +
                  QString::fromStdString((*it)->getAtleta().getCognome()) + " " +
                     QString::fromStdString((*it)->getAtleta().getSessoCarUtf8());
    atleti = atletiDup.toSet().toList();
    cmbAtleti->addItems(atleti);
    lPersona->addRow("Atleta:", cmbAtleti);

    QFormLayout *lDataInizio = new QFormLayout, *lDataFine = new QFormLayout;
    deDataInizio = new QDateEdit(QDate::currentDate());
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
    lMin->addRow("Vasche Stile (min):", spinMinStile);
    spinMinRana = new QSpinBox;
    lMin->addRow("Vasche Rana (min):", spinMinRana);
    spinMinDorso = new QSpinBox;
    lMin->addRow("Vasche Dorso (min):", spinMinDorso);
    lNuoto->addLayout(lMin);

    spinMaxStile = new QSpinBox;
    lMax->addRow("Vasche Stile (max):", spinMaxStile);
    spinMaxRana = new QSpinBox;
    lMax->addRow("Vasche Rana (max):", spinMaxRana);
    spinMaxDorso = new QSpinBox;
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
    lMin->addRow("Km salita (min):", spinMinSalita);
    spinMinDiscesa = new QSpinBox;
    lMin->addRow("Km discesa (min):", spinMinDiscesa);
    spinMinPianura = new QSpinBox;
    lMin->addRow("Km pianura (min):", spinMinPianura);
    lCiclismo->addLayout(lMin);

    spinMaxSalita = new QSpinBox;
    lMax->addRow("Km salita (max):", spinMaxSalita);
    spinMaxDiscesa = new QSpinBox;
    lMax->addRow("Km discesa (max):", spinMaxDiscesa);
    spinMaxPianura = new QSpinBox;
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
    lMin->addRow("Km strada (min):", spinMinStrada);
    spinMinSterrato = new QSpinBox;
    lMin->addRow("Km sterrato (min):", spinMinSterrato);
    lCorsa->addLayout(lMin);

    spinMaxStrada = new QSpinBox;
    lMax->addRow("Km strada (max):", spinMaxStrada);
    spinMaxSterrato = new QSpinBox;
    lMax->addRow("Km sterrato (max):", spinMaxSterrato);
    lCorsa->addLayout(lMax);

    boxCorsa->setLayout(lCorsa);
    return boxCorsa;
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
#include <QDebug>
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
            spinMaxStile->setValue(spinMaxStile->value());
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
