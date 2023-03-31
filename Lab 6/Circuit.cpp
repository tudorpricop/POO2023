#include "Circuit.h"
#include <algorithm>
#include <iostream>

void Circuit::SetLength(int length) {
    this->length = length;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
}

void Circuit::AddCar(Car* car) {
    cars.push_back(car);
}

void sortFinishedCars(std::vector<Car*>& finishedCars, const int& length, const Weather& weather)
{
    int n = finishedCars.size();
    for (int i = 0; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            double time1 = length / finishedCars[i]->getAverageSpeed(weather);
            double time2 = length / finishedCars[j]->getAverageSpeed(weather);
            if (time1 > time2) {
                Car* temp = finishedCars[i];
                finishedCars[i] = finishedCars[j];
                finishedCars[j] = temp;
            }
        }
    }
}

void Circuit::Race()
{
    // Iterate through all cars in the race
    for (auto car : cars)
    {
        // Calculate how many km can a car go until it has no more fuel
        double currentCarDistance = car->getFuelCapacity() / car->getFuelConsumption() * 100;

        // Check if the car can finish the race before running out of fuel
        if (currentCarDistance >= length)
        {
            // If the car can finish the race, add it to the finishedCars vector
            finishedCars.push_back(car);
        }
        else
        {
            // If the car cannot finish the race, add it to the unfinishedCars vector
            unfinishedCars.push_back(car);
        }
    }

    sortFinishedCars(finishedCars, length, weather);
}


void Circuit::ShowFinalRanks() {


    std::cout << "Final ranks:\n";
    for (int i = 0; i < finishedCars.size(); ++i) {
        double currentCarTime = length / finishedCars[i]->getAverageSpeed(weather);
        std::cout << i + 1 << ": " << finishedCars[i]->getBrand() << " - " << currentCarTime * 60<< " minutes\n";
    }
}

void Circuit::ShowWhoDidNotFinish() {
    if (unfinishedCars.empty()) {
        std::cout << "\nAll cars finished the race!\n";
    }
    else {
        std::cout << "\nCars that did not finish the race:\n";
        for (auto car : unfinishedCars) {
            std::cout << "- " << car->getBrand() << std::endl;
        }
    }
}

Circuit::~Circuit()
{
    for (int i = 0; i < cars.size(); i++) {
        delete cars[i];
    }
}
