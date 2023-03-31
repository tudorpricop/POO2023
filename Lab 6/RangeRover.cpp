#include "RangeRover.h"
RangeRover::RangeRover()
{
    fuelCapacity = 100;
    fuelConsumption = 20;
}

double RangeRover::getFuelCapacity() const
{
    return fuelCapacity;
}

double RangeRover::getFuelConsumption() const
{
    return fuelConsumption;
}

double RangeRover::getAverageSpeed(Weather weatherCondition) const
{
    double speed = 0;
    switch (weatherCondition) {
    case Weather::Sunny:
        speed = 140;
        break;
    case Weather::Rain:
        speed = 110;
        break;
    case Weather::Snow:
        speed = 70;
        break;
    }
    return speed;
}

const char* RangeRover::getBrand() const
{
    return brand;
}
