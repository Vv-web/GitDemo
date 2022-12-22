#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<subwidget1.h>
namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::mainWidget *ui;
    subwidget1 sub1;
};

#endif // MAINWIDGET_H
