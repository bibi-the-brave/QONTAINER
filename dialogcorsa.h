/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
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
                bool = false,
                int = 0,
                QWidget* = nullptr);
private:
    QGroupBox *gbCorsa;
    WidgetCorsa *wCorsa;
protected:
    void setLabelTitolo() override;
    void compilazioneFormModifica();
public slots:
    void inserimentoAllenamento();
    void modificaAllenamento();
};

#endif // DIALOGCORSA_H
