#include <iostream>
using namespace std;

class Engine
{
private:
    int eng_num;

public:
    Engine() { eng_num = 0; }
    Engine(int num) { eng_num = num; }
    void showEngNum() { cout << "Engine number is: " << eng_num << endl; }
};

class Passenger
{
private:
    string pass_name;

public:
    void set_pass_name(string name) { pass_name = name; }
    void get_pass_name() { cout << "Passenger name is: " << pass_name << endl; }
};

class Car
{
private:
    int car_num;
    Passenger *passenger;
    Engine engine;

public:
    Car(Passenger p1)
    {
        engine = Engine(22);
        passenger = &p1;
        passenger->set_pass_name("Tahir Hassan");
        passenger->get_pass_name();
        engine.showEngNum();
    }
};

int main()
{
    Passenger p2;
    Car c1(p2);

    return 0;
}
