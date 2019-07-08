/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#include "widgetnuoto.h"
#include <QMessageBox>

WidgetNuoto::WidgetNuoto()
{
    layoutWidget = new QGridLayout;
    gbNuoto = new QGroupBox("NUOTO");
    layout = new QFormLayout;

    lblLibero = new QLabel("Vasche stile:");
    spinLibero = new QSpinBox();
    spinLibero->setRange(0, 400);
    layout->addRow(lblLibero, spinLibero);

    lblRana = new QLabel("Vasche rana:");
    spinRana = new QSpinBox();
    spinRana->setRange(0, 400);
    layout->addRow(lblRana, spinRana);

    lblDorso = new QLabel("Vasche dorso:");
    spineDorso = new QSpinBox();
    spineDorso->setRange(0, 400);
    layout->addRow(lblDorso, spineDorso);

    gbNuoto->setLayout(layout);
    layoutWidget->addWidget(gbNuoto);

    setLayout(layoutWidget);

    //setFixedSize();
}

int WidgetNuoto::vascheLibero() const {
    return spinLibero->value();
}

int WidgetNuoto::vascheRana() const {
    return  spinRana->value();
}

int WidgetNuoto::vascheDorso() const {
    return  spineDorso->value();
}

void WidgetNuoto::setVascheLibero(int v) {
    spinLibero->setValue(v);
}

void WidgetNuoto::setVascheRana(int v) {
    spinRana->setValue(v);
}

void WidgetNuoto::setVascheDorso(int v) {
    spineDorso->setValue(v);
}

void WidgetNuoto::reset() {
    spinLibero->setValue(0);
    spinRana->setValue(0);
    spineDorso->setValue(0);
}

void WidgetNuoto::dialogErroreForm() const {
    QMessageBox mes;
    mes.setIcon(QMessageBox::Information);
    mes.setText("Errore!");
    mes.setInformativeText("È necessario aver fatto almeno una vasca in uno dei tre stili.");
    mes.setStandardButtons(QMessageBox::Ok);
    mes.exec();
}

void WidgetNuoto::controlloForm(bool& controllo) {
    if( !spinRana->value() && !spinLibero->value() && !spineDorso->value() )
        controllo = true;
    else
        controllo = false;
}
