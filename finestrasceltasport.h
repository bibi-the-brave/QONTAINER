#ifndef FINESTRASCELTASPORT_H
#define FINESTRASCELTASPORT_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
//#include "inserimentosportview.h"

class FinestraSceltaSport : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *layoutFinestra;
    QGridLayout *layoutSport;

    //InserimentoSportView *inserimentoSport;


    QPushButton* creaBottoneSport(const QString&) const;
public:
    FinestraSceltaSport(QWidget* = nullptr);
signals:
    void sportSelezionato(QString);

private slots:
    void creaOggettoInserimentoSport(QString);
};

#endif // FINESTRASCELTASPORT_H
