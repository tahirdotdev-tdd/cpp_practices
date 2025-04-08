/* Write a C++ program that creates a class named Computer. It has an object of a user-defined type called Processor.

The Processor class has a data member called processor_model, which is set using its constructor.

The class Computer also has an aggregation relationship with another user-defined class called User, which has a data member user_name.

Create an object of class Computer that displays the processor model and the user's name on the screen.

*/

#include <iostream>
using namespace std;

class Processor
{
private:
    string processor_model;

public:
    Processor()
    {
        // Default constructor initializes processor model
        processor_model = "Intel Core i5";
    }
    Processor(string model)
    {
        // Parameterized constructor to set processor model
        processor_model = model;
    }
    void showProcModel()
    {
        // Display processor model
        cout << "Processor model is: " << processor_model << endl;
    }
};

class User
{
private:
    string user_name; // User name

public:
    void setUserName(string name)
    {
        user_name = name; // Set user name
    }
    void showUserName()
    {
        cout << "User name is: " << user_name << endl; // Display user name
    }
};

class Computer
{
private:
    Processor processor; // Processor object
    User user;           // User object
public:
    Computer(Processor p, User u)
    {
        // Initialize processor and user objects
        processor = p; // Assign the passed Processor object
        user = u;     // Assign the passed User object
    }
    void showDetails()
    {
        // Display processor model and user name
        processor.showProcModel(); // Show processor model
        user.showUserName();       // Show user name
    }

};

int main()
{
    // Create a Processor object with a specific model
    Processor proc("AMD Ryzen 7");
    // Create a User object and set the user name   
    User usr;
    usr.setUserName("Tahir Hassan");
    // Create a Computer object with the Processor and User objects
    Computer comp(proc, usr);
    // Show the details of the Computer object
    comp.showDetails(); // Display processor model and user name
    return 0;
}