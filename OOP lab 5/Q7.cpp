#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    const int roll_no;
    string name;

public:
    Student(int rollNumber, const string &studentName)
        : roll_no(rollNumber), name(studentName) {}

    void displayInfo() const
    {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << roll_no << endl;
    }
};

int main()
{
    string name;
    int rollNumber;

    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> rollNumber;

    Student student(rollNumber, name);

    cout << "\nStudent Details:\n";
    student.displayInfo();

    return 0;
}
