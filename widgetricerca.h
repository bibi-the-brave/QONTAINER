#ifndef WIDGETRICERCA_H
#define WIDGETRICERCA_H

#include <QWidget>
#include "contenitore.h"
#include "allenamento.h"
#include "deepptr.h"

class WidgetRIcerca : public QWidget {
    Q_OBJECT
public:
    WidgetRIcerca(Contenitore<DeepPtr<Allenamento*>>&, QWidget* = nullptr);
private:
    Contenitore<DeepPtr<Allenamento*>>& ca;
};

#endif // WIDGETRICERCA_H
