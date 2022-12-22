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
    void sendstrain(StrainSensor);//Ӧ�䴫���������ź�
    void sendDeflect(DeflectionSensor);//�Ӷȴ������ź�
    void sendDisplace(DisplacementSensor);//λ�ƴ������ź�
public slots:
    void slotstrain();//Ӧ�䴫�����ۺ���
    void slotsdeflect();//�Ӷȴ������ۺ���
    void slotsdisplace();//λ�ƴ������ۺ���
private:
    Ui::sensorDialog *ui;
protected:
    void closeEvent(QCloseEvent *event); //�������Ͻǹرհ�ť����
};

#endif // SENSORDIALOG_H
