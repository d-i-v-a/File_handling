#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class employee{
    private: 
        int eid;
        char name[10];
        char dept[10];
        float gsalary;
        
    public:
        employee()//default function
        {
            
        }//instructor function
        employee(int id, char name1[10], char dept1[10], float gsalary1)
        {
        	eid=id;
        	strcpy(name, name1);
        	strcpy(dept, dept1);
        	gsalary=gsalary1;
        }
        void display()//member function
        {
            cout<<"\nEmployee ID: "<< eid;
            cout<<"\nName: "<<name;
            cout<<"\nDepartment: "<<dept;
            cout<<"\nGross Salary: "<<gsalary;
        }
};

int main()
{
    employee e1;//constructor gets invoked
    
    employee e2(102, "Rakesh", "Sales", 25000);
    ofstream myfile;
    myfile.open("emp.dat", ios::out);
    //cout<<&e1
    //myfile.write((char *)&e1, sizeof(e1));
    myfile.write((char *)&e2, sizeof(e2));
    //myfile.write((char *)&e3, sizeof(e3));
    //cout<<sizeof(e1); 28 bytes transferred in 1 run 
    //(::)scope resolution operator
    
    myfile.close();
    return 0;
}