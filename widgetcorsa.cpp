#include "widgetcorsa.h"
#include <QMessageBox>

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

void WidgetCorsa::dialogErroreForm() const {
    QMessageBox mes;
    mes.setIcon(QMessageBox::Information);
    mes.setText("Errore!");
    mes.setInformativeText("È necessario aver fatto almeno un km di corsa su strada o su sterrato.");
    mes.setStandardButtons(QMessageBox::Ok);
    mes.exec();
}


void WidgetCorsa::controlloForm(bool& controllo) {
    if( !spinStrada->value() && !spinSterrato->value() )
        controllo = true;
    controllo = false;
}
