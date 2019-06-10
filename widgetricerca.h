#ifndef _H
#define _H

#include <QWidget>
#include "contenitore.h"
#include "allenamento.h"
#include "deepptr.h"

class WidgetRicerca : public QWidget {
    Q_OBJECT
public:
    WidgetRicerca(Contenitore<DeepPtr<Allenamento>>&, QWidget* = nullptr);
private:
    Contenitore<DeepPtr<Allenamento>>& ca;
};

#endif // _H
