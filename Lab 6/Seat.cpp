#include "Seat.h"

Seat::Seat()
{
    fuelCapacity = 5;
    fuelConsumption = 15;
}

double Seat::getFuelCapacity() const
{
    return fuelCapacity;
}

double Seat::getFuelConsumption() const
{
    return fuelConsumption;
}

double Seat::getAverageSpeed(Weather weatherCondition) const
{
    double speed = 0;
    switch (weatherCondition) {
    case Weather::Sunny:
        speed = 110;
        break;
    case Weather::Rain:
        speed = 80;
        break;
    case Weather::Snow:
        speed = 50;
        break;
    }
    return speed;
}

const char* Seat::getBrand() const
{
    return brand;
}
