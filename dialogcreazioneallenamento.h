#ifndef DIALOGCREAZIONEALLENAMENTO_H
#define DIALOGCREAZIONEALLENAMENTO_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>

#include "contenitore.h"
#include "persona.h"
#include "allenamento.h"
#include "deepptr.h"


class DialogCreazioneAllenamento : public QDialog {
    Q_OBJECT
public:
    explicit DialogCreazioneAllenamento(Contenitore<std::shared_ptr<Persona>>&,
                                        Contenitore<DeepPtr<Allenamento>>&,
                                        QWidget* = nullptr);
protected:
    Contenitore<std::shared_ptr<Persona>>& cp;
    Contenitore<DeepPtr<Allenamento>>& ca;
    QPushButton *bConferma, *bReset;
    QVBoxLayout *layoutPrincipale;
    QHBoxLayout *lBottoni;
    QFormLayout *lFormAllenamento;
    QComboBox *cmbAtleti;
    QLabel *lblTitolo, *lblAtleta, *lblDurata, *lblMagnesio;
    QSpinBox *spinDurata, *spinMagnesio;

    void aggiungiBottoni();
    virtual void setLabelTitolo() = 0;
};

#endif // DIALOGCREAZIONEALLENAMENTO_H
