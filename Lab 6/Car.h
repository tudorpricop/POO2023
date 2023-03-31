#pragma once
#include "Weather.h"
class Car
{
protected:
    double fuelCapacity;
    double fuelConsumption;

public:

    virtual double getFuelCapacity() const = 0;
    virtual double getFuelConsumption() const = 0;
    virtual double getAverageSpeed(Weather weatherCondition) const = 0;
    virtual const char* getBrand() const = 0;

};
