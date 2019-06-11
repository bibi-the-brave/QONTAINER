#ifndef DIALOGCREAZIONEALLENAMENTO_H
#define DIALOGCREAZIONEALLENAMENTO_H

#include <QDialog>
#include <QPushButton>

#include "contenitore.h"
#include "persona.h"
#include "allenamento.h"
#include "deepptr.h"


class DialogCreazioneAllenamento : public QDialog {
    Q_OBJECT
public:
    explicit DialogCreazioneAllenamento(Contenitore<DeepPtr<Allenamento>>&,QWidget* = nullptr);
protected:
    Contenitore<DeepPtr<Allenamento>>& ca;
    QPushButton *bConferma, *bReset;
};

#endif // DIALOGCREAZIONEALLENAMENTO_H
