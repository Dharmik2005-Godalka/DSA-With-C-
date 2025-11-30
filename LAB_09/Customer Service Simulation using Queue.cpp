#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> customers;
    int choice;
    string name;

    while (true){
        cout << "\n1. Customer Arrives\n2. Serve Customer\n3. Show Queue\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1){
            cout << "Enter Customer Name: ";
            cin >> name;
            customers.push(name);
            cout << name << " added to queue.\n";
        }
        else if (choice == 2){
            if (customers.empty())
                cout << "No customers to serve!\n";
            else{
                cout << customers.front() << " served and removed.\n";
                customers.pop();
            }
        }
        else if (choice == 3){
            if (customers.empty())
                cout << "Queue Empty.\n";
            else{
                cout << "Current Queue: ";
                queue<string> temp = customers;
                while (!temp.empty()){
                    cout << temp.front() << " ";
                    temp.pop();
                }
                cout << endl;
            }
        }
        else if (choice == 4){
            cout << "Exiting...";
            break;
        }
        else{
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}

