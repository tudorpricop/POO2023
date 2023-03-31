#pragma once
#include "Car.h"
class Fiat : public Car
{
public:

	Fiat();
	// Inherited via Car
	const char* brand = "Fiat";

	virtual double getFuelCapacity() const override;

	virtual double getFuelConsumption() const override;

	virtual double getAverageSpeed(Weather weatherCondition) const override;

	virtual const char* getBrand() const override;
};

