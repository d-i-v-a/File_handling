#include <iostream>
#include <fstream>
using namespace std;

class stay
{
public:
    string name;
    int duration;
    string type;
    
    stay(const string name1, int duration1, const string type1)
        : name(name1), duration(duration1), type(type1)
    {
    }
};

class restaurant
{
public:
    string name2;
    string date;
    int billno;

    restaurant(const string name3, const string date1, int billno1)
        : name2(name3), date(date1), billno(billno1)
    {
    }
};

class hotelbill : public stay, public restaurant
{
public:
    double totalBill = 0;

    hotelbill(const string name, int duration, const string type, const string date, int billno)
        : stay(name, duration, type), restaurant(name, date, billno)
    {
    }

    void calculateTotalBill()
    {
        if (type == "single")
        {
            totalBill = duration * 20000;
        }
        else if (type == "double")
        {
            totalBill = duration * 50000;
        }
        totalBill += billno * 1000;
    }

    void display()
    {
        cout << "Guest Name: " << name << endl;
        cout << "Duration of Stay: " << duration << " days" << endl;
        cout << "Type of Stay: " << type << " room" << endl;
        cout << "Guest Name: " << name2 << endl;
        cout << "Date: " << date << endl;
        cout << "Bill Number: " << billno << endl;
        cout << "Total Bill: Rs. " << totalBill << endl;
    }
};

int main()
{
    string guestName, stayType, date;
    int stayDuration, billNumber = 0;
    int choice = 0;

    while (choice != 3)
    {
        int ch;
        cout << "\nEnter choice: \n1.New customer\n2.Restaurant\n3.Exit ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "\nEnter Guest Name: ";
            cin >> guestName;
            cout << "\nEnter Stay Duration (in days): ";
            cin >> stayDuration;
            cout << "\nEnter Stay Type (Single/Double): ";
            cin >> stayType;
            billNumber = 0;
            break;
        }
        case 2:
        {
            cout << "\nEnter Guest Name: ";
            cin >> guestName;
            cout << "Enter Date: ";
            cin.ignore();
            getline(cin, date);
            cout << "Enter Bill Number: ";
            cin >> billNumber;
            break;
        }
        case 3:
        {
            cout << "\nThank you !!";
            return 0;
        }
        }

        hotelbill bill(guestName, stayDuration, stayType, date, billNumber);
        cout << endl
             << "\n~Guest Details~\n";
        bill.calculateTotalBill();
        bill.display();

        ofstream myfile;
        myfile.open("guest.txt", ios::out);
        if (myfile.is_open())
        {
            myfile << "Guest Name: " << bill.name << endl;
            myfile << "Duration of Stay: " << bill.duration << " days" << endl;
            myfile << "Type of Stay: " << bill.type << " room" << endl;
            myfile << "Guest Name: " << bill.name2 << endl;
            myfile << "Date: " << bill.date << endl;
            myfile << "Bill Number: " << bill.billno << endl;
            myfile << "Total Bill: Rs. " << bill.totalBill << endl;
            myfile << "--------------------------" << endl;
            myfile.close();
            cout << "Guest details written to file." << endl;
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }

    return 0;
}
