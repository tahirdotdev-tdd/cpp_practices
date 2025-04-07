#include <iostream>
using namespace std;

class Student
{
private:
    string name;

public:
    Student()
    {
        cout << "Welcome to student portal!" << endl;
    }
    ~Student()
    {
        cout << "Thank you for using our student portal!" << endl;
    }

    void getData()
    {
        cout << "Enter Student name : " << endl;
        cin >> name;
    }
    void showData()
    {
        cout << "The student name is " << name << endl;
    }
};

int main()
{

    string who = "It's Tahir !";
    cout << who;

    Student s1;
    s1.getData();
    s1.showData();

    Student s2;
    s2.getData();
    s2.showData();

    Student s3;
    s3.getData();   
    s3.showData();

    Student s4;
    s4.getData();
    s4.showData();
}