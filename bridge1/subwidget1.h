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
    int a=-1;//用于应变传感器修改中radiobutton checkid索引用
    QButtonGroup BGnd1;
    int q=-1;//用于挠度传感器修改中radiobutton checkid索引用
    QButtonGroup BGwy1;
    int w=-1;//用于位移传感器修改中radiobutton checkid索引用
    QButtonGroup BGyb2;
    int e=-1;//用于应变传感器查询中radiobutton checkid用
    QButtonGroup BGnd2;
    int f=-1;//用于挠度传感器查询中radiobutton checkid用
    QButtonGroup BGwy2;
    int r=-1;//用于位移传感器查询中radiobutton checkid用
    void getStrainfileDate();//读取保存在文件中的数据
    void getDeflectionfileDate();//读取保存在文件中的数据
    void getDisplacementfileDate();//读取保存在文件中的数据
protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *event); //窗口右上角关闭按钮重载
public slots:

      void getStrainFromFile();//应变监测点文件数据读取槽函数
      void getDisplacementFromFile();//位移监测点文件数据读取槽函数
      void getDeflectionFromFile();//挠度监测点文件数据读取槽函数
      void getStrainsensor(StrainSensor);//接收应变传感器增加功能槽函数
      void getDeflectionsensor(DeflectionSensor);//接收挠度传感器增加功能槽函数
      void getDisplacesensor(DisplacementSensor);//接收位移传感器增加功能槽函数
      void getDeletestrain(int );//接收应变传感器删除功能槽函数
      void getDeletedeflection(int);//接收挠度传感器删除功能槽函数
      void getDeletedisplace(int );//接收位移传感器删除功能槽函数
      void getDeflectiondialog(int );//接收基准点槽函数
private:
    Ui::subwidget1 *ui;
    QList<StrainPoint> stra;
    QList<DisplacementPoint> disp;
    QList<DeflectionPoint> defl;
    int l=0;  //用于判断关闭系统时是否保存了数据
    sensorDialog sensdialog;   // 传感器增加功能对话框
    deletedialog deletesensor; //传感器删除功能对话框
    deflectionpointdialog deflectionDlg;
};

#endif // SUBWIDGET1_H
