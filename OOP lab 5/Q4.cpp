#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice..." << endl;
        for (int i = 0; i < 4; ++i) {
            cout << "Blending... " << (i + 1) << " seconds" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        cout << "Juice blending complete!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice..." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        cout << "Juice grinding complete!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice() {
        cout << "Starting juice making process..." << endl;
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Juice is ready to serve!" << endl;
    }
};

int main() {
    JuiceMaker myJuiceMaker;
    myJuiceMaker.makeJuice();
    return 0;
}
