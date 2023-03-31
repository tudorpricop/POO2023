#pragma once
#include "Car.h"

class Volvo : public Car
{
public:

	Volvo();
	// Inherited via Car
	const char* brand = "Volvo";

	virtual double getFuelCapacity() const override;

	virtual double getFuelConsumption() const override;

	virtual double getAverageSpeed(Weather weatherCondition) const override;

	virtual const char* getBrand() const override;

};

