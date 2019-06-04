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

private:
    QVBoxLayout layout;
    QPushButton btnNuovoAtleta;
    QLabel lblTitolo;
    QTableView tabAtleti;

public slots:
    void avviaDialogInserimento(bool);
};

#endif // FINESTRAATLETI_H
