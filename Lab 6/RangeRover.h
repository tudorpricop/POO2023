#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:

	RangeRover();
	// Inherited via Car
	const char* brand = "RangeRover";

	virtual double getFuelCapacity() const override;

	virtual double getFuelConsumption() const override;

	virtual double getAverageSpeed(Weather weatherCondition) const override;

	virtual const char* getBrand() const override;
};

