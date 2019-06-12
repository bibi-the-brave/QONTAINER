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
