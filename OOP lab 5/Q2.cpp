#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Engine {
private:
    bool isRunning;

public:
    Engine() : isRunning(false) {
        cout << "Engine constructed" << endl;
    }

    ~Engine() {
        cout << "Engine destroyed" << endl;
    }

    void start() {
        if (isRunning==false) {
            isRunning = true;
            cout << "Engine started" << endl;
        } else {
            cout << "Engine is already running" << endl;
        }
    }

    void stop() {
        if (isRunning==true) {
            isRunning = false;
            cout << "Engine stopped" << endl;
        } else {
            cout << "Engine is already stopped" << endl;
        }
    }
};

class Car {
private:
    Engine engine;
    string name;
    int id;

public:
    Car(string name, int id) : name(name), id(id) {
        cout << "Car constructed: " << name << endl;
    }

    ~Car() {
        cout << "Car destroyed: " << name << endl;
    }

    void startCar() {
        engine.start();
    }

    void stopCar() {
        engine.stop();
    }

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }
};

class Garage {
private:
    vector<Car*> cars;

public:
    void parkCar(Car* car) {
        cars.push_back(car);
        cout << "Car parked: " << car->getName() << endl;
    }

    void listCars() {
        cout << "Cars in garage:" << endl;
        for (const auto& car : cars) {
            cout << "ID: " << car->getId() << ", Name: " << car->getName() << endl;
        }
    }
};

int main() {
    cout << "--- Composition Example ---" << endl;
    {
        Car myCar("Toyota", 1);
        myCar.startCar();
        myCar.stopCar();
    } // Car and Engine destoryed

    cout << "\n--- Aggregation Example ---" << endl;
    {
        Car car1("Honda", 2);
        Car car2("Ford", 3);
        
        Garage myGarage;
        myGarage.parkCar(&car1);
        myGarage.parkCar(&car2);

        myGarage.listCars();
    } // Cars destroyed

    return 0;
}
