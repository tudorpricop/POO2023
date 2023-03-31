#include "Fiat.h"

Fiat::Fiat()
{
    fuelCapacity = 40;
    fuelConsumption = 5;
}

double Fiat::getFuelCapacity() const
{
    return fuelCapacity;
}

double Fiat::getFuelConsumption() const
{
    return fuelConsumption;
}

double Fiat::getAverageSpeed(Weather weatherCondition) const
{
    double speed = 0;
    switch (weatherCondition) {
    case Weather::Sunny:
        speed = 100;
        break;
    case Weather::Rain:
        speed = 70;
        break;
    case Weather::Snow:
        speed = 40;
        break;
    }
    return speed;
}

const char* Fiat::getBrand() const
{
    return brand;
}
