#ifndef SENSOR_H
#define SENSOR_H
#include<QString>
#include<QList>
class monitroing  //监测数据类（监测时间和监测值）
{
private:
    QString date;//监测年月日
    QString time;//监测时间
    QString unit;//单位
    double mointrNum; //传感器监测值
    double finalData;//监测点数据经计算后的最终数值
    QString finaldateUnit; //最终数据单位
public:
        void setDate(const QString &);
        void setTime(const QString &);
        QString getDate();
        QString getTime();
        void setMonitrNum(const double c);
        double getMonitruNum();
        void setUnit(const QString &);
        QString getUnit();
        void setFinalData(const double c);
        double getFinalData();
        void setFinaldateUnit(const QString &);
        QString getFinaldateUnit();
};

class Sensor  //父类传感器
{
public:
    Sensor();
    void setNumber(const QString &);
    QString getNumber();
    void setSensorname(const QString s);
    QString getSensorname();
    void setSpecification(const QString s);
    QString getSpecification();
    void setModel(const QString s);
    QString getModel();
    void setManufacture(const QString s);
    QString getManufacture();
    void setManudate(const QString s);
    QString getManudate();

private:
    QString sensorname;//传感器名称
    QString specification;//传感器规格
    QString model;//传感器型号
    QString manufacture;//传感器生产厂家
    QString manudate;//生产日期
    QString number;//传感器编号
};
class StrainSensor:public Sensor//应变传感器
{
private:
    double cencterwl;//中心波长

public:
    void setCencterwl(const double c);
    double getCencterwl();
    QList<monitroing> monitr;
};
class DeflectionSensor:public Sensor//挠度传感器
{
public:
    QList<monitroing> monitr;
};
class DisplacementSensor:public Sensor//位移传感器
{
private:
    double  firstmonit;//伸缩缝初始值
    QString  firstunit;//伸缩缝初始值的单位
public:
    QList<monitroing> monitr;
    void setFirstmonit(const double c);
    double getFirstmonit();
    void setFirstunit(const QString &);
    QString getFirstunit();

};
#endif // SENSOR_H
