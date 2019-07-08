/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
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
#include <QDateEdit>

#include "contenitore.h"
#include "persona.h"
#include "allenamento.h"
#include "deepptr.h"


class DialogAllenamento : public QDialog {
    Q_OBJECT
public:
    explicit DialogAllenamento(Contenitore<std::shared_ptr<Persona>>&,
                                        Contenitore<DeepPtr<Allenamento>>&,
                                        bool mod = false,
                                        int rMod = 0, //se mod == 0 non uso rigaMod
                                        QWidget* = nullptr);
protected:
    Contenitore<std::shared_ptr<Persona>>& cp;
    Contenitore<DeepPtr<Allenamento>>& ca;
    bool modifica;
    int rigaMod;
    QPushButton *bConferma, *bReset;
    QVBoxLayout *layoutPrincipale;
    QHBoxLayout *lBottoni;
    QFormLayout *lFormAllenamento;
    QComboBox *cmbAtleti;
    QLabel *lblTitolo, *lblAtleta, *lblDurata, *lblMagnesio, *lblData;
    QSpinBox *spinDurata, *spinMagnesio;
    QDateEdit *deData;

    void aggiungiBottoni();
    virtual void setLabelTitolo() = 0;
    void dialogErroreForm() const;
    void controlloForm(bool& controllo) const;
    void dialogErroreDoppione() const;
    void compilazioneFormModifica();
    void visualizzaMessaggioAllenamentoNonModificato() const;
public slots:
    void reset();
    //void slotModificaAllenamento(bool);
signals:
    void aggiungereAllenamento();
};

#endif // DIALOGCREAZIONEALLENAMENTO_H
