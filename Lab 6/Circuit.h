#pragma once
#include "Weather.h"
#include <vector>
#include "car.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"

class Circuit {
public:
    ~Circuit();
    void SetLength(int length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
private:
    int length;
    Weather weather;

    std::vector<Car*> cars;
    std::vector<Car*> finishedCars;
    std::vector<Car*> unfinishedCars;
};