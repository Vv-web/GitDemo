#include "sensor.h"

Sensor::Sensor()
{
}

void Sensor::setNumber(const QString &s)
{
    this->number=s;
}
QString Sensor::getNumber()
{
    return number;
}
void StrainSensor::setCencterwl(const double c)
{
    this->cencterwl=c;
}
double StrainSensor::getCencterwl()
{
    return  cencterwl;
}
void monitroing::setDate(const QString &s)
{
    this->date=s;
}
void monitroing::setTime(const QString &s)
{
    this->time=s;
}
QString monitroing::getDate()
{
    return  date;
}
QString monitroing::getTime()
{
    return  time;
}
void monitroing::setMonitrNum(const double c)
{
    this->mointrNum=c;
}
double monitroing::getMonitruNum()
{
    return  this->mointrNum;
}
void monitroing::setUnit(const QString &s)
{
    unit=s;
}
QString monitroing::getUnit()
{
    return this->unit;
}
QString monitroing::getFinaldateUnit()
{
    return this->finaldateUnit;
}
void monitroing::setFinaldateUnit(const QString &s)
{
    this->finaldateUnit=s;
}
double monitroing::getFinalData()
{
    return this->finalData;
}
void monitroing::setFinalData(const double c)
{
    this->finalData=c;
}
void DisplacementSensor::setFirstmonit(const double c)
{
    this->firstmonit=c;
}
double DisplacementSensor::getFirstmonit()
{
    return  this->firstmonit;
}
void DisplacementSensor::setFirstunit(const QString &s)
{
    this->firstunit=s;
}
QString DisplacementSensor::getFirstunit()
{
    return  this->firstunit;
}
void Sensor::setSensorname(const QString s)
{
    this->sensorname=s;
}
QString Sensor::getSensorname()
{
    return this->sensorname;
}
void Sensor::setSpecification(const QString s)
{
    this->specification=s;
}
QString Sensor::getSpecification()
{
    return this->specification;
}
void Sensor::setModel(const QString s)
{
    this->model=s;
}
QString Sensor::getModel()
{
    return this->model;
}
void Sensor::setManufacture(const QString s)
{
    this->manufacture=s;
}
QString Sensor::getManufacture()
{
    return this->manufacture;
}
void Sensor::setManudate(const QString s)
{
    this->manudate=s;
}
QString Sensor::getManudate()
{
    return  this->manudate;
}
