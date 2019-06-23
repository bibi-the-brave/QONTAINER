#include "widgetricerca.h"
#include "contenitore.h"
#include "allenamento.h"
#include "deepptr.h"
#include <QGroupBox>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QSpinBox>
#include "widgetnuoto.h"
#include "widgetciclismo.h"
#include "widgetcorsa.h"
#include "modeltabellaallenamenti.h"
#include "delegatebottone.h"
#include <QHeaderView>

WidgetRicerca::WidgetRicerca(Contenitore<DeepPtr<Allenamento>>& ca_, QWidget* parent)
    : QWidget (parent), ca(ca_)
{
    layoutPrincipale = new QVBoxLayout;

    // box relativo alla ricerca
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
    layoutBoxFormRicerca->addWidget(wNuoto = new WidgetNuoto(),0,1);
    layoutBoxFormRicerca->addWidget(wCiclismo = new WidgetCiclismo(),1,0);
    layoutBoxFormRicerca->addWidget(wCorsa = new WidgetCorsa(),1,1);
    layoutBoxFormRicerca->setColumnStretch(0,1);
    layoutBoxFormRicerca->setColumnStretch(1,1);
    layoutBoxFormRicerca->setRowStretch(0,1);
    layoutBoxFormRicerca->setRowStretch(1,1);
    layoutComponentiRicerca->addLayout(layoutBoxFormRicerca);

    // di default è selezionato il radiobutton atleta quindi li disabilito
    wNuoto->setEnabled(false);
    wCorsa->setEnabled(false);
    wCiclismo->setEnabled(false);

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
}


QGroupBox* WidgetRicerca::costruzioneFormPersona() {
    boxPersona = new QGroupBox("PERSONA");
    lPersona = new QFormLayout;
    lblNome = new QLabel("Nome");
    leNome = new QLineEdit;
    lPersona->addRow(lblNome, leNome);
    lblCognome = new QLabel("Cognome");
    leCognome = new QLineEdit;
    lPersona->addRow(lblCognome, leCognome);
    lblSesso = new QLabel("Sesso");
    lSesso = new QHBoxLayout;
    rbUomo = new QRadioButton("Uomo");
    rbDonna = new QRadioButton("Donna");
    rbUomo->setChecked(true);
    lSesso->addWidget(rbUomo);
    lSesso->addWidget(rbDonna);
    lSesso->setAlignment(Qt::AlignLeft);
    lPersona->addRow(lblSesso, lSesso);
    boxPersona->setLayout(lPersona);
    return  boxPersona;
}
