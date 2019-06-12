#include "widgetnuoto.h"

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

void WidgetNuoto::reset() {
    spinLibero->setValue(0);
    spinRana->setValue(0);
    spineDorso->setValue(0);
}
