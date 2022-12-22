#ifndef SUBWIDGET1_H
#define SUBWIDGET1_H

#include <QWidget>
#include<monitroingpoint.h>
#include<sensordialog.h>
#include<QButtonGroup>
#include<deletedialog.h>
#include<deflectionpointdialog.h>
namespace Ui {
class subwidget1;
}

class subwidget1 : public QWidget
{
    Q_OBJECT

public:
    explicit subwidget1(QWidget *parent = nullptr);
    ~subwidget1();
    QButtonGroup BGyb1;
    int a=-1;//����Ӧ�䴫�����޸���radiobutton checkid������
    QButtonGroup BGnd1;
    int q=-1;//�����Ӷȴ������޸���radiobutton checkid������
    QButtonGroup BGwy1;
    int w=-1;//����λ�ƴ������޸���radiobutton checkid������
    QButtonGroup BGyb2;
    int e=-1;//����Ӧ�䴫������ѯ��radiobutton checkid��
    QButtonGroup BGnd2;
    int f=-1;//�����Ӷȴ�������ѯ��radiobutton checkid��
    QButtonGroup BGwy2;
    int r=-1;//����λ�ƴ�������ѯ��radiobutton checkid��
    void getStrainfileDate();//��ȡ�������ļ��е�����
    void getDeflectionfileDate();//��ȡ�������ļ��е�����
    void getDisplacementfileDate();//��ȡ�������ļ��е�����
protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *event); //�������Ͻǹرհ�ť����
public slots:

      void getStrainFromFile();//Ӧ������ļ����ݶ�ȡ�ۺ���
      void getDisplacementFromFile();//λ�Ƽ����ļ����ݶ�ȡ�ۺ���
      void getDeflectionFromFile();//�Ӷȼ����ļ����ݶ�ȡ�ۺ���
      void getStrainsensor(StrainSensor);//����Ӧ�䴫�������ӹ��ܲۺ���
      void getDeflectionsensor(DeflectionSensor);//�����Ӷȴ��������ӹ��ܲۺ���
      void getDisplacesensor(DisplacementSensor);//����λ�ƴ��������ӹ��ܲۺ���
      void getDeletestrain(int );//����Ӧ�䴫����ɾ�����ܲۺ���
      void getDeletedeflection(int);//�����Ӷȴ�����ɾ�����ܲۺ���
      void getDeletedisplace(int );//����λ�ƴ�����ɾ�����ܲۺ���
      void getDeflectiondialog(int );//���ջ�׼��ۺ���
private:
    Ui::subwidget1 *ui;
    QList<StrainPoint> stra;
    QList<DisplacementPoint> disp;
    QList<DeflectionPoint> defl;
    int l=0;  //�����жϹر�ϵͳʱ�Ƿ񱣴�������
    sensorDialog sensdialog;   // ���������ӹ��ܶԻ���
    deletedialog deletesensor; //������ɾ�����ܶԻ���
    deflectionpointdialog deflectionDlg;
};

#endif // SUBWIDGET1_H
