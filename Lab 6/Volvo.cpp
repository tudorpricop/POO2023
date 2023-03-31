#include "Volvo.h"

Volvo::Volvo()
{
    fuelCapacity = 60;
    fuelConsumption = 15;
}

double Volvo::getFuelCapacity() const
{
	return fuelCapacity;
}

double Volvo::getFuelConsumption() const
{
	return fuelConsumption;
}

double Volvo::getAverageSpeed(Weather weatherCondition) const
{
        double speed = 0;
        switch (weatherCondition) {
        case Weather::Sunny:
            speed = 130;
            break;
        case Weather::Rain:
            speed = 100;
            break;
        case Weather::Snow:
            speed = 60;
            break;
        }
        return speed;
}

const char* Volvo::getBrand() const
{
    return brand;
}
