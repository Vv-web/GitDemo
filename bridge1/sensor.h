#ifndef SENSOR_H
#define SENSOR_H
#include<QString>
#include<QList>
class monitroing  //��������ࣨ���ʱ��ͼ��ֵ��
{
private:
    QString date;//���������
    QString time;//���ʱ��
    QString unit;//��λ
    double mointrNum; //���������ֵ
    double finalData;//�������ݾ�������������ֵ
    QString finaldateUnit; //�������ݵ�λ
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

class Sensor  //���ഫ����
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
    QString sensorname;//����������
    QString specification;//���������
    QString model;//�������ͺ�
    QString manufacture;//��������������
    QString manudate;//��������
    QString number;//���������
};
class StrainSensor:public Sensor//Ӧ�䴫����
{
private:
    double cencterwl;//���Ĳ���

public:
    void setCencterwl(const double c);
    double getCencterwl();
    QList<monitroing> monitr;
};
class DeflectionSensor:public Sensor//�Ӷȴ�����
{
public:
    QList<monitroing> monitr;
};
class DisplacementSensor:public Sensor//λ�ƴ�����
{
private:
    double  firstmonit;//�������ʼֵ
    QString  firstunit;//�������ʼֵ�ĵ�λ
public:
    QList<monitroing> monitr;
    void setFirstmonit(const double c);
    double getFirstmonit();
    void setFirstunit(const QString &);
    QString getFirstunit();

};
#endif // SENSOR_H
