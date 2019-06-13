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
