#pragma once
#include "Car.h"
class BMW : public Car
{
public:

	BMW();
	// Inherited via Car
	const char* brand = "BMW";

	virtual double getFuelCapacity() const override;

	virtual double getFuelConsumption() const override;

	virtual double getAverageSpeed(Weather weatherCondition) const override;

	virtual const char* getBrand() const override;
};

