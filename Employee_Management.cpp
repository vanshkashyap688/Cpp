#include <iostream>
#include <fstream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void showData() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nSalary: " << salary << endl;
    }

    int getID() {
        return id;
    }

  
    void writeToFile(ofstream &out) {
        out << id << " " << name << " " << salary << endl;
    }

  
    bool readFromFile(ifstream &in) {
        return (in >> id >> name >> salary) ? true : false;
    }
};


void addEmployee() {
    Employee e;
    ofstream file("employees.txt", ios::app);

    e.getData();
    e.writeToFile(file);

    file.close();
    cout << "\nEmployee Added Successfully!\n";
}

void displayAll() {
    Employee e;
    ifstream file("employees.txt");

    if (!file) {
        cout << "\nNo Records Found!\n";
        return;
    }

    while (e.readFromFile(file)) {
        e.showData();
        cout << "-------------------";
    }

    file.close();
}


void searchEmployee() {
    Employee e;
    int searchID, found = 0;

    cout << "Enter Employee ID to search: ";
    cin >> searchID;

    ifstream file("employees.txt");

    while (e.readFromFile(file)) {
        if (e.getID() == searchID) {
            cout << "\nEmployee Found:\n";
            e.showData();
            found = 1;
            break;
        }
    }

    if (!found)
        cout << "\nEmployee Not Found!\n";

    file.close();
}

void updateEmployee() {
    Employee e;
    int updateID, found = 0;

    cout << "Enter Employee ID to update: ";
    cin >> updateID;

    ifstream file("employees.txt");
    ofstream temp("temp.txt");

    if (!file) {
        cout << "\nFile not found!\n";
        return;
    }

    while (e.readFromFile(file)) {
        if (e.getID() == updateID) {
            cout << "\nEnter New Details:\n";
            e.getData();   
            found = 1;
        }
        e.writeToFile(temp);
    }

    file.close();
    temp.close();

    remove("employees.txt");
    rename("temp.txt", "employees.txt");

    if (found)
        cout << "\nEmployee Updated Successfully!\n";
    else
        cout << "\nEmployee Not Found!\n";
}

void deleteEmployee() {
    Employee e;
    int deleteID, found = 0;

    cout << "Enter Employee ID to delete: ";
    cin >> deleteID;

    ifstream file("employees.txt");
    ofstream temp("temp.txt");

    while (e.readFromFile(file)) {
        if (e.getID() != deleteID) {
            e.writeToFile(temp);
        } else {
            found = 1;
        }
    }

    file.close();
    temp.close();

    remove("employees.txt");
    rename("temp.txt", "employees.txt");

    if (found)
        cout << "\nEmployee Deleted Successfully!\n";
    else
        cout << "\nEmployee Not Found!\n";
}


int main() {
    int choice;

    do {
        cout << "\n===== Employee Management System =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Update Employee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
    case 1: addEmployee(); break;
    case 2: displayAll(); break;
    case 3: searchEmployee(); break;
    case 4: deleteEmployee(); break;
    case 5: updateEmployee(); break;
    case 6: cout << "Exiting...\n"; break;
    default: cout << "Invalid Choice!\n";
}

    } while (choice != 6);

    return 0;
}