#include"vehicle_factory.hpp"
#include <iostream>
using namespace std;

Vehicle* VehicleFactory::getVehicle(string vehicleType) {
    Vehicle* vehicle;
    if (vehicleType == "car") {
        vehicle = new Car();
    }
    else if (vehicleType == "bike") {
        vehicle = new Bike();
    }
    else {
        cout << "Invalid Input." << endl;
        return nullptr;
    }
    return vehicle;
}