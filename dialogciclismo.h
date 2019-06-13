#ifndef DIALOGCICLISMO_H
#define DIALOGCICLISMO_H

#include "dialogallenamento.h"
#include <QGroupBox>
#include "widgetciclismo.h"

class DialogCiclismo : public DialogAllenamento {
    Q_OBJECT
public:
    DialogCiclismo(Contenitore<std::shared_ptr<Persona>>&,
                         Contenitore<DeepPtr<Allenamento>>&,
                         QWidget* = nullptr);
private:
    QGroupBox *gbCiclismo;
    WidgetCiclismo *wCiclismo;
protected:
    void setLabelTitolo() override;
};

#endif // DIALOGCICLISMO_H
