#ifndef DIALOGCREAZIONENUOTO_H
#define DIALOGCREAZIONENUOTO_H

#include "dialogallenamento.h"
#include <QGroupBox>
#include "widgetnuoto.h"

class DialogNuoto : public DialogAllenamento {
    Q_OBJECT
public:
    DialogNuoto(Contenitore<std::shared_ptr<Persona>>&,
                Contenitore<DeepPtr<Allenamento>>&,
                bool = false,
                int = 0,
                QWidget* = nullptr);
private:
    QGroupBox *gbNuoto;
    WidgetNuoto *wNuoto;
protected:
    void setLabelTitolo() override;
    void compilazioneFormModifica();
public slots:
    void inserimentoAllenamento();
};

#endif // DIALOGCREAZIONENUOTO_H
