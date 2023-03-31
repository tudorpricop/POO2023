#pragma once
#include "Car.h"
class Seat : public Car
{
public:

	Seat();
	// Inherited via Car
	const char* brand = "Seat";

	virtual double getFuelCapacity() const override;

	virtual double getFuelConsumption() const override;

	virtual double getAverageSpeed(Weather weatherCondition) const override;

	virtual const char* getBrand() const override;

};
