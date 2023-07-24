/*#include <iostream>
#include <fstream>

using namespace std;

class employee {
private:
    int eid;
    char name[10];
    char dept[10];
    float gsalary;

public:
    int getid() {
        return eid;
    }

    void inputdata() //member function
    {
        cout << "Enter Employee ID: ";
        cin >> eid;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter department: ";
        cin >> dept;
        cout << "Enter gross salary: ";
        cin >> gsalary;
    }

    void display() //member function
    {
        cout << "\nEmployee ID: " << eid;
        cout << "\nName: " << name;
        cout << "\nDepartment: " << dept;
        cout << "\nGross Salary: " << gsalary;
    }
};

void search(int id1) {
    employee e;
    int found = 0;
    ifstream fin("emp.dat", ios::in);
    while (fin.read((char*)&e, sizeof(e))) {
        if (e.getid() == id1) {
            e.display();
            found = 1;
        }
    }
    if (found == 0) {
        cout << "\nEmployee data not found!\n";
    }

    fin.close();
}

void deleteData(int recordToDelete) {
    employee e;
    ifstream fin("emp.dat", ios::in);
    ofstream temp("temp.dat", ios::out);

    if (!fin || !temp) {
        cout << "Error opening file." << endl;
        return;
    }

    // Read and transfer the data from the original file to the temporary file
    while (fin.read((char*)&e, sizeof(e))) {
        if (e.getid() != recordToDelete) {
            temp.write((char*)&e, sizeof(e));
        }
    }

    // Close the files
    fin.close();
    temp.close();

    // Remove the original file
    remove("emp.dat");

    // Rename the temporary file to the original filename
    rename("temp.dat", "emp.dat");

    cout << "\nRecord " << recordToDelete << " deleted successfully." << endl;
}

int main() {
    employee e;
    ifstream yourfile;
    yourfile.open("emp.dat", ios::in);

    while (yourfile.read((char*)&e, sizeof(e))) {
        e.display();
    }

    yourfile.close();
    return 0;
}*/