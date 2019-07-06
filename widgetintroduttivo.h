#ifndef WIDGETINTRODUTTIVO_H
#define WIDGETINTRODUTTIVO_H
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>


class WidgetIntroduttivo : public QWidget {
    Q_OBJECT
public:
    explicit  WidgetIntroduttivo(QWidget* = nullptr);
private:
    QVBoxLayout *layout;
    QPushButton *btnNuovoAtleta;
    QLabel *lblTitolo;
public slots:
};

#endif // WIDGETINTRODUTTIVO_H
