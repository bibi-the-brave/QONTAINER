#ifndef INSERIMENTOSPORTVIEW_H
#define INSERIMENTOSPORTVIEW_H

#include <QWidget>
#include <QLabel>

class InserimentoSportView : public QWidget {
    Q_OBJECT
private:
    //QLabel *titolo;
public:
    InserimentoSportView(const QString&, QWidget*);
    virtual void visualizzaFormInserimento() const = 0;
    //virtual void setNomeAllenamento();
};

#endif // INSERIMENTOSPORTVIEW_H
