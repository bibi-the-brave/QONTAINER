#ifndef DIALOGCORSA_H
#define DIALOGCORSA_H

#include "dialogallenamento.h"
#include <QGroupBox>
#include "widgetcorsa.h"

class DialogCorsa : public DialogAllenamento {
    Q_OBJECT
public:
    DialogCorsa(Contenitore<std::shared_ptr<Persona>>&,
                         Contenitore<DeepPtr<Allenamento>>&,
                         QWidget* = nullptr);
private:
    QGroupBox *gbCorsa;
    WidgetCorsa *wCorsa;
protected:
    void setLabelTitolo() override;
public slots:
    void inserimentoAllenamento();
};

#endif // DIALOGCORSA_H
