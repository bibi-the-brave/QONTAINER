#ifndef FINESTRAPRINCIPALE_H
#define FINESTRAPRINCIPALE_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>

class FinestraPrincipale : public QMainWindow {
    Q_OBJECT
private:
    QWidget* centrale;
    QHBoxLayout *layout;
    QPushButton *bInserAtleta, *bInserAllenamento, *bRicerca;
public:
    FinestraPrincipale(QWidget *parent = nullptr);
    ~FinestraPrincipale();
//private slots:

};

#endif // FINESTRAPRINCIPALE_H
