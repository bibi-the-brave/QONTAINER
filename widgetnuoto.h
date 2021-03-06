/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#ifndef WIDGETNUOTO_H
#define WIDGETNUOTO_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QFormLayout>
#include <QSpinBox>
#include <QGridLayout>

class WidgetNuoto : public QWidget {
    Q_OBJECT
public:
    WidgetNuoto();
    int vascheLibero() const;
    int vascheRana() const;
    int vascheDorso() const;
    void dialogErroreForm() const;
    void controlloForm(bool& controllo);
    void setVascheLibero(int);
    void setVascheRana(int);
    void setVascheDorso(int);
private:
    QGroupBox *gbNuoto;
    QGridLayout *layoutWidget;
    QFormLayout *layout;
    QLayout *lBase;
    QLabel *lblLibero, *lblRana, *lblDorso;
    QSpinBox *spinLibero, *spinRana, *spineDorso;

public slots:
    void reset();
};

#endif // WIDGETNUOTO_H
