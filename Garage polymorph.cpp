#include <iostream>
#include <string.h>

using namespace std;

class vehicle
{
    protected:
        char regnum[10];
        static int vcount;
        char vehicle_type[10];
        char brand[10];
        
    public:
        vehicle();
        ~vehicle();
        
        void setregnumber(char* vnum);
        char* getregnum();
        void askVehicleInfo();
        void showdetails();
        
        static int getvcount();
};

int vehicle::vcount=0;

vehicle::vehicle()
{
    vcount++;
}
vehicle::~vehicle()
{
    vcount--;
}
void vehicle::setregnumber(char* vnum)
{
    strcpy(regnum, vnum);
}
char* vehicle::getregnum()
{
    return regnum;
}

void vehicle::askVehicleInfo()
{
    cout<<"Enter registration number: ";
    cin.getline(regnum, 10);
    cin.ignore();
    cout << "Enter the vehicle type: ";
    cin >> vehicle_type;
    cout << "Enter the brand: ";
    cin >> brand;
}

void vehicle::showdetails()
{
    cout << "Registration Number: " << regnum << endl;
    cout << "Vehicle Type: " << vehicle_type << endl;
    cout << "Brand: " << brand << endl;
}
//class car
class car: public vehicle
{
    protected:
        int capacity;
        int num_people;

    public:
        car()
        {}
        
        car(char* vnum, char* vtype, char* vbrand, int cap, int nump);
        void showdetails();
};
car::car(char* vnum, char* vtype, char* vbrand, int cap, int nump)
{
    setregnumber(vnum);
    strcpy(vehicle_type, vtype);
    strcpy(brand, vbrand);
    capacity = cap;
    num_people = nump;
}

void car::showdetails()
{
    vehicle::showdetails();
    cout << "Capacity: " << capacity << endl;
    cout << "Number of people: " << num_people << endl;
}

//class lorryy
class lorry: public vehicle
{
    protected:
        int load;
        char* loadtype;

    public:
    lorry(){}
        lorry(char* vnum1, char* vtype1, char* vbrand1, int load1, char* loadtype1);
        void showdetails();
};
lorry::lorry(char* vnum1, char* vtype1, char* vbrand1, int load1, char* loadtype1)
{
    setregnumber(vnum1);
    strcpy(vehicle_type, vtype1);
    strcpy(brand, vbrand1);
    load = load1;
    strcpy(loadtype, loadtype1);
}

void lorry::showdetails()
{
    vehicle::showdetails();
    cout << "Load in kgs: " << load << endl;
    cout << "Load type: " << loadtype << endl;
}

int vehicle::getvcount()
{
    return vcount;
}

int main()
{
    vehicle* queue[10];
    car car1;
    lorry lorry1;
    queue[0]=&car1;
    queue[0]->askVehicleInfo();
    queue[0]->showdetails();
    queue[1]=&lorry1;
    queue[1]->askVehicleInfo();
    queue[1]->showdetails();

    return 0;
}
