#ifndef WIDGETNUOVOSPORT_H
#define WIDGETNUOVOSPORT_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

class WidgetNuovoSport : public QWidget {
    Q_OBJECT
private:
    QLabel* lblCreazione;
    QVBoxLayout *layout;
    QHBoxLayout *layoutBottoni;

    QPushButton* creaBottoneSport(const QString&) const;
public:
    WidgetNuovoSport(QWidget* = nullptr);
signals:
    void sportSelezionato(QString);

private slots:
    void creaOggettoInserimentoSport(QString);
};

#endif // WIDGETNUOVOSPORT_H
