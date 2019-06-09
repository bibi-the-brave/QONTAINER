#ifndef WIDGETALLENAMENTI_H
#define WIDGETALLENAMENTI_H

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "contenitore.h"
#include "allenamento.h"
#include "deepptr.h"
#include "modeltabellaallenamenti.h"
#include "delegateeliminazione.h"

class WidgetAllenamenti : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetAllenamenti(Contenitore<DeepPtr<Allenamento*>>&, QWidget* = nullptr);
private:
    QVBoxLayout* layout;
    QPushButton* btnNuovoAtleta;
    QLabel* lblTitolo;
    QTableView* tabAtleti;

    Contenitore<DeepPtr<Allenamento*>>& ca;
    ModelTabellaAllenamenti* modello;
    DelegateEliminazione* delegato;
};

#endif // WIDGETALLENAMENTI_H
