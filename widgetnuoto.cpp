#include "widgetnuoto.h"

WidgetNuoto::WidgetNuoto()
{
    layoutWidget = new QGridLayout;
    gbNuoto = new QGroupBox("Nuoto");
    layout = new QFormLayout;

    lblLibero = new QLabel("Vasche stile:");
    spinLibero = new QSpinBox();
    layout->addRow(lblLibero, spinLibero);

    lblRana = new QLabel("Vasche rana:");
    spinRana = new QSpinBox();
    layout->addRow(lblRana, spinRana);

    lblDorso = new QLabel("Vasche dorso:");
    spineDorso = new QSpinBox();
    layout->addRow(lblDorso, spineDorso);

    gbNuoto->setLayout(layout);
    layoutWidget->addWidget(gbNuoto);

    setLayout(layoutWidget);

    //setFixedSize();
}
