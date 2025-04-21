/*
Write a C++ program that implements a class hierarchy having a base class named Employee and a derived class named Adhoc_employee.
The base class has data members of Name, Id, Number of working hours and Per hour salary. The derived class implements two methods
named salary and display_info. The salary method calculates the salary of employee by multiplying “Number of working hours” by “Per hour salary”. The display_info method displays
the complete information of employee. Create an object of Adhoc_employee and display the information and salary against that instance.
*/

#include <iostream>
using namespace std;

class Employee
{
protected:
    string name;
    int id;
    int workingHours;
    int perHourSalary;

public:
    void setValues(){
        cout<<"Enter employee name : "<<endl;
        cin>>name;
        cout<<"Enter employee ID : "<<endl;
        cin>>id;
        cout<<"Enter working hours of employee "<<name << " is "<<endl;
        cin>>workingHours;
        cout<<"Enter per hour salary of "<<name<<" is "<<endl;
        cin>>perHourSalary;
    }

    int calcSalary()
    {
        int totalSalary = perHourSalary * workingHours;
        return totalSalary;
    }
    void display_info()
    {
        cout << "The employee name is :" << name << endl;
        cout << "The employee ID is :" << id << endl;
        cout << "The working hours of " << name << " is :" << workingHours << endl;
        cout << "The salary of " << name << " is :" << calcSalary() << endl;
    }
};

class Adhoc_employee : public Employee
{
public:
    void setDetails(string empName, int empId, int hours, int salaryPerHour)
    {
        name = empName;
        id = empId;
        workingHours = hours;
        perHourSalary = salaryPerHour;
    }

    void display_info()
    {
        cout << "New Employee Details are :" << endl;
        Employee::display_info();
    }
};

int main()
{
    Adhoc_employee newEmp;
    newEmp.setValues();
    newEmp.calcSalary();
    newEmp.display_info();
    return 0;
}