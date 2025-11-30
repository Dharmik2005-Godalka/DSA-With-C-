#include <iostream>
using namespace std;

class Employee {
private:
    int salary;

public:
    int empID;
    string name;
    string gender;

    void setSalary(int s) {
        salary = s;
    }

    int getSalary() {
        return salary;
    }
};

int main() {

    Employee emp[10];

    cout << "Enter Employee Details:\n";
    for(int i = 0; i < 10; i++) {

        cout << "\nEmployee " << i + 1 << endl;

        cout << "Enter ID: ";
        cin >> emp[i].empID;

        cout << "Enter Name: ";
        cin >> emp[i].name;

        cout << "Enter Gender: ";
        cin >> emp[i].gender;

        int s;
        cout << "Enter Salary: ";
        cin >> s;
        emp[i].setSalary(s);
    }

    cout << "\nUpdating Salaries:\n";
    for(int i = 0; i < 10; i++) {
        int newSal;
        cout << "Enter new salary for Employee " << emp[i].empID << ": ";
        cin >> newSal;
        emp[i].setSalary(newSal);
    }

    cout << "\nUpdated Employee Data:\n";
    for(int i = 0; i < 10; i++) {
        cout << "\nID: " << emp[i].empID;
        cout << "\nName: " << emp[i].name;
        cout << "\nGender: " << emp[i].gender;
        cout << "\nSalary: " << emp[i].getSalary() << endl;
    }

    return 0;
}


