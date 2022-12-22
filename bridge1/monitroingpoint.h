#ifndef MONITROINGPOINT_H
#define MONITROINGPOINT_H
#include<QString>
#include<sensor.h>
class monitroingPoint
{
public:
    monitroingPoint();




};
class StrainPoint :public monitroingPoint //应变监测点
{
public:
    StrainSensor s;
};
class DisplacementPoint :public monitroingPoint //位移监测点
{
public:
    DisplacementSensor d;
};
class DeflectionPoint :public monitroingPoint//挠度传感器
{
public:
    DeflectionSensor de;
};

#endif // MONITROINGPOINT_H
