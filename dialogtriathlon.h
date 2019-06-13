#ifndef DIALOGTRIATHLON_H
#define DIALOGTRIATHLON_H

#include "dialogallenamento.h"
#include <QGroupBox>
#include "widgetcorsa.h"
#include "widgetnuoto.h"
#include "widgetciclismo.h"

class DialogTriathlon : public DialogAllenamento {
    Q_OBJECT
public:
    DialogTriathlon(Contenitore<std::shared_ptr<Persona>>&,
                         Contenitore<DeepPtr<Allenamento>>&,
                         QWidget* = nullptr);
private:
    QGroupBox *gbCorsa, *gbCiclismo, *gbNuoto;
    WidgetNuoto *wNuoto;
    WidgetCiclismo *wCiclismo;
    WidgetCorsa *wCorsa;
protected:
    void setLabelTitolo() override;
};

#endif // DIALOGTRIATHLON_H
