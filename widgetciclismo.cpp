#include "widgetciclismo.h"

WidgetCiclismo::WidgetCiclismo()
{
    layoutWidget = new QGridLayout;
    gbCiclismo = new QGroupBox("CICLISMO");
    layout = new QFormLayout;

    lblSalita = new QLabel("Km in salita:");
    spinSalita = new QSpinBox();
    spinSalita->setRange(0, 400);
    layout->addRow(lblSalita, spinSalita);

    lblDiscesa = new QLabel("Km in discesa:");
    spinDiscesa = new QSpinBox();
    spinDiscesa->setRange(0, 400);
    layout->addRow(lblDiscesa, spinDiscesa);

    lblPianura = new QLabel("Km in pianura:");
    spinePianura = new QSpinBox();
    spinePianura ->setRange(0, 400);
    layout->addRow(lblPianura , spinePianura);

    gbCiclismo->setLayout(layout);
    layoutWidget->addWidget(gbCiclismo);

    setLayout(layoutWidget);

    //setFixedSize();

}

int WidgetCiclismo::kmSalita() const {
    return spinSalita->value();
}

int WidgetCiclismo::kmDiscesa() const {
    return spinDiscesa->value();
}

int WidgetCiclismo::kmPianura() const {
    return spinePianura->value();
}

void WidgetCiclismo::reset() {
    spinSalita->setValue(0);
    spinDiscesa->setValue(0);
    spinePianura->setValue(0);
}
