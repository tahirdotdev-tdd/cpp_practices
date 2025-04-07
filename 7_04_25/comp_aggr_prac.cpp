//composition and aggregation practice

#include <iostream>
using namespace std;

// Engine class to represent the engine of a car
class Engine
{
private:
    int eng_num; // Engine number

public:
    Engine()
    {
        eng_num = 0; // Default constructor initializes engine number to 0
    }
    Engine(int num)
    {
        eng_num = num; // Parameterized constructor to set engine number
    }
    void showEngNum()
    {
        cout << "Engine number is: " << eng_num << endl; // Display engine number
    }
};

// Passenger class to represent a passenger
class Passenger
{
private:
    string pass_name; // Passenger name

public:
    void set_pass_name(string name)
    {
        pass_name = name; // Set passenger name
    }
    void get_pass_name()
    {
        cout << "Passenger name is: " << pass_name << endl; // Display passenger name
    }
};

// Car class to represent a car
class Car
{
private:
    int car_num; // Car number
    Passenger *passenger; // Pointer to a Passenger object
    Engine engine; // Engine object

public:
    Car(Passenger p1)
    {
        // Initialize engine with 22
        engine = Engine(22); // Create an Engine object with engine number 22
        
        passenger = &p1; // Assign the passenger pointer to the passed Passenger object
        passenger->set_pass_name("Tahir Hassan"); // Set passenger name
        passenger->get_pass_name(); // Display passenger name
        engine.showEngNum(); // Display engine number
    }
};

int main()
{
    Passenger p2; // Create a Passenger object
    Car c1(p2); // Create a Car object and pass the Passenger object to it

    return 0; // End of program
}
