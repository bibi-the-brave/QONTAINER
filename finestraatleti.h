#ifndef FINESTRAATLETI_H
#define FINESTRAATLETI_H

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class FinestraAtleti : public QWidget {
    Q_OBJECT
public:
    explicit FinestraAtleti(QWidget *parent = nullptr);

signals:

public slots:

private:
    QVBoxLayout layout;
    QPushButton btnNuovoAtleta;
    QLabel lblTitolo;
    QTableView tabAtleti;
};

#endif // FINESTRAATLETI_H
