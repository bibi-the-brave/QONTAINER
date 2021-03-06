/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#ifndef WIDGETCICLISMO_H
#define WIDGETCICLISMO_H

#include <QWidget>
#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QFormLayout>
#include <QSpinBox>
#include <QGridLayout>

class WidgetCiclismo : public QWidget {
    Q_OBJECT
public:
    WidgetCiclismo();
    int kmSalita() const;
    int kmDiscesa() const;
    int kmPianura() const;
    void setKmSalita(int);
    void setKmDiscesa(int);
    void setKmPianura(int);
    void dialogErroreForm() const;
    void controlloForm(bool& controllo);
private:
    QGroupBox *gbCiclismo;
    QGridLayout *layoutWidget;
    QFormLayout *layout;
    QLayout *lBase;
    QLabel *lblSalita, *lblDiscesa, *lblPianura;
    QSpinBox *spinSalita, *spinDiscesa, *spinePianura;
public slots:
    void reset();
};

#endif // WIDGETCICLISMO_H
