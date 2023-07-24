#include <iostream>
#include <string.h>

using namespace std;
typedef char str[500];

class person
{
    private: 
        str name, address;
        
    public:
        person (str name1, str address1)
        {
            strcpy(name, name1);
            strcpy(address, address1);
        }
        //getter fns
        char* getname()
        {
            return name;
        }
        char* getaddress()
        {
            return address;
        }
};

//single inheritance
class student: public person
{
    private:
        int numcourses;
        str courses[5]={"MAT161", "CCC704", "ECE101", "CSD102", "PHY102"};
        int grades[5];
        const int maxcourses=5;
    
    public:
        student(str name1, str address1):person(name1, address1)
        {
            numcourses=0;
        }
        void addgrades(int grade1)
        {
            grades[numcourses]=grade1;
            ++numcourses;
        }
        void display()
        {
            cout<<"Name: "<< getname() <<"\nAddress: " << getaddress();
            for(int i=0; i<5; i++)
            {
                cout<< "\nCourses: "<< courses[i];
                cout<< "\nGrades: "<< grades[i];
            }
        }
        double getaverage()
        {
            int sum=0;
            for (int i=0; i<5; i++)
            {
                sum+=grades[i];
            }
            cout<<"\nAverage grades: "<< sum/5;
        }
        
};

int main()
{
    student s1("Diva", "Dwarka\n");
    s1.addgrades(10);
    s1.addgrades(8);
    s1.addgrades(7);
    s1.addgrades(6);
    s1.addgrades(9);
    s1.display();
    s1.getaverage();

    return 0;
}
//teacher class
