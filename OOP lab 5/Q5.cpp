#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    mutable int engine_horsepower;
    mutable int seating_capacity;
    mutable int no_of_speakers;

    Car(int hp, int seats, int speakers) 
        : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}


    void updateCarDetails(int hp, int seats, int speakers) const {
        engine_horsepower = hp;
        seating_capacity = seats;
        no_of_speakers = speakers;
        cout << "Car details updated\n";
    }

    void displayDetails() const {
        cout << "Engine Horsepower: " << engine_horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }
};

int main() {
    Car myCar(352, 23, 7);

    cout << "Car Details:\n";
    myCar.displayDetails();

    
    myCar.updateCarDetails(463, 54, 16);

    cout << "\nUpdated Car:\n";
    myCar.displayDetails();

    return 0;
}
