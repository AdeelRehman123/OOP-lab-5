#include <iostream>
using namespace std;

class Engine {
private:
	bool isRunning;

public:
	Engine() : isRunning(false) {}

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

public:
	void startCar() {
		engine.start();
	}

	void stopCar() {
		engine.stop();
	}
};

int main() {
	Car myCar;
	myCar.startCar();
	myCar.startCar();
	myCar.stopCar();
	myCar.stopCar();

	return 0;
}
