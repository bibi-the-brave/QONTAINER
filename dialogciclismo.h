/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
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
                   bool = false,
                   int = 0,
                   QWidget* = nullptr);
private:
    QGroupBox *gbCiclismo;
    WidgetCiclismo *wCiclismo;
protected:
    void setLabelTitolo() override;
    void compilazioneFormModifica();
public slots:
    void inserimentoAllenamento();
    void modificaAllenamento();
};

#endif // DIALOGCICLISMO_H
