/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#ifndef WIDGETCORSA_H
#define WIDGETCORSA_H

#include <QWidget>
#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QFormLayout>
#include <QSpinBox>
#include <QGridLayout>

class WidgetCorsa  : public QWidget {
    Q_OBJECT
public:
    WidgetCorsa();
    int kmStrada() const;
    int kmSterrato() const;
    void setKmStrada(int);
    void setKmSterrato(int);
    void dialogErroreForm() const;
    void controlloForm(bool& controllo);
private:
    QGroupBox *gbCorsa;
    QGridLayout *layoutWidget;
    QFormLayout *layout;
    QLayout *lBase;
    QLabel *lblStrada, *lblSterrato;
    QSpinBox *spinStrada, *spinSterrato;
public slots:
    void reset();
};
#endif // WIDGETCORSA_H
