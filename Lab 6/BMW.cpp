#include "BMW.h"

BMW::BMW()
{
    fuelCapacity = 100;
    fuelConsumption = 20;
}

double BMW::getFuelCapacity() const
{
    return fuelCapacity;
}

double BMW::getFuelConsumption() const
{
    return fuelConsumption;
}

double BMW::getAverageSpeed(Weather weatherCondition) const
{
    double speed = 0;
    switch (weatherCondition) {
    case Weather::Sunny:
        speed = 120;
        break;
    case Weather::Rain:
        speed = 90;
        break;
    case Weather::Snow:
        speed = 50;
        break;
    }
    return speed;
}

const char* BMW::getBrand() const
{
    return brand;
}
