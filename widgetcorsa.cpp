#include "widgetcorsa.h"

WidgetCorsa::WidgetCorsa()
{
    layoutWidget = new QGridLayout;
    gbCorsa = new QGroupBox("CORSA  ");
    layout = new QFormLayout;

    lblStrada = new QLabel("Km su strada:");
    spinStrada = new QSpinBox();
    spinStrada->setRange(0, 400);
    layout->addRow(lblStrada, spinStrada);

    lblSterrato = new QLabel("Km su sterrato:");
    spinSterrato = new QSpinBox();
    spinSterrato->setRange(0, 400);
    layout->addRow(lblSterrato, spinSterrato);

    gbCorsa->setLayout(layout);
    layoutWidget->addWidget(gbCorsa);

    setLayout(layoutWidget);

    //setFixedSize();

}

int WidgetCorsa::kmStrada() const {
    return spinStrada->value();
}

int WidgetCorsa::kmSterrato() const {
    return spinSterrato->value();
}

void WidgetCorsa::reset() {
    spinStrada->setValue(0);
    spinSterrato->setValue(0);
}
