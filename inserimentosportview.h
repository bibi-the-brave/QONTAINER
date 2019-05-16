#ifndef INSERIMENTOSPORTVIEW_H
#define INSERIMENTOSPORTVIEW_H

#include <QWidget>

class InserimentoSportView : public QWidget {
    Q_OBJECT
public:
    InserimentoSportView(QWidget*);
    virtual void visualizzaFormInserimento() const = 0;
};

#endif // INSERIMENTOSPORTVIEW_H
