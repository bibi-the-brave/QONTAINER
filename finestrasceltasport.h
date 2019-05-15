#ifndef FINESTRASCELTASPORT_H
#define FINESTRASCELTASPORT_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>

class FinestraSceltaSport : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *layoutFinestra;
    QGridLayout *layoutSport;
public:
    FinestraSceltaSport(QWidget* = nullptr);
    ~FinestraSceltaSport();
};

#endif // FINESTRASCELTASPORT_H
