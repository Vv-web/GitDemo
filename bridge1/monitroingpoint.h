#ifndef MONITROINGPOINT_H
#define MONITROINGPOINT_H
#include<QString>
#include<sensor.h>
class monitroingPoint
{
public:
    monitroingPoint();




};
class StrainPoint :public monitroingPoint //Ӧ�����
{
public:
    StrainSensor s;
};
class DisplacementPoint :public monitroingPoint //λ�Ƽ���
{
public:
    DisplacementSensor d;
};
class DeflectionPoint :public monitroingPoint//�Ӷȴ�����
{
public:
    DeflectionSensor de;
};

#endif // MONITROINGPOINT_H
