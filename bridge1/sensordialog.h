#ifndef SENSORDIALOG_H
#define SENSORDIALOG_H

#include <QDialog>
#include<sensor.h>
#include<QButtonGroup>
namespace Ui {
class sensorDialog;
}

class sensorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sensorDialog(QWidget *parent = nullptr);
    ~sensorDialog();
    StrainSensor s;
    DeflectionSensor d;
    DisplacementSensor p;
    QButtonGroup *BG1;
    QButtonGroup *BG2;
    QButtonGroup *BG3;
signals:
    void sendstrain(StrainSensor);//应变传感器数据信号
    void sendDeflect(DeflectionSensor);//挠度传感器信号
    void sendDisplace(DisplacementSensor);//位移传感器信号
public slots:
    void slotstrain();//应变传感器槽函数
    void slotsdeflect();//挠度传感器槽函数
    void slotsdisplace();//位移传感器槽函数
private:
    Ui::sensorDialog *ui;
protected:
    void closeEvent(QCloseEvent *event); //窗口右上角关闭按钮重载
};

#endif // SENSORDIALOG_H
