#ifndef DIALOGTRIATHLON_H
#define DIALOGTRIATHLON_H

#include "dialogallenamento.h"

class DialogTriathlon : public DialogAllenamento {
    Q_OBJECT
public:
    DialogTriathlon(Contenitore<std::shared_ptr<Persona>>&,
                         Contenitore<DeepPtr<Allenamento>>&,
                         QWidget* = nullptr);
};

#endif // DIALOGTRIATHLON_H
