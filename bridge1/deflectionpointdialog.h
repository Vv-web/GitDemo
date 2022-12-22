#ifndef DEFLECTIONPOINTDIALOG_H
#define DEFLECTIONPOINTDIALOG_H

#include <QDialog>
#include<QButtonGroup>
namespace Ui {
class deflectionpointdialog;
}

class deflectionpointdialog : public QDialog
{
    Q_OBJECT

public:
    explicit deflectionpointdialog(QWidget *parent = nullptr);
    ~deflectionpointdialog();
    QButtonGroup BG;

signals:
    void sendsingals(int);
private:
    Ui::deflectionpointdialog *ui;
};

#endif // DEFLECTIONPOINTDIALOG_H
