#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Phonebook {
private:
    vector<string> names;
    vector<string> numbers;

public:
    void getname() {
        string name;
        cout << "Enter the name: " << endl;
        cin >> name;
        names.push_back(name);
    }

    void getnumber() {
        string number;
        cout << "Enter the phone number (10 DIGITS): " << endl;
        cin >> number;
        numbers.push_back(number);
    }

    void addContact() {
        getname();
        getnumber();
    }

    void displayContacts() {
        for (size_t i = 0; i < names.size(); ++i) {
            cout << i + 1 << ". " << names[i] << " : " << numbers[i] << endl;
        }
    }

    void deleteContact() {
        string name;
        cout << "Enter the name of the contact to delete: " << endl;
        cin >> name;
        for (size_t i = 0; i < names.size(); ++i) {
            if (names[i] == name) {
                names.erase(names.begin() + i);
                numbers.erase(numbers.begin() + i);
                cout << "Contact deleted." << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }
};

int main() {
    Phonebook phonebook;
    int choice;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "***********WELCOME***************" << endl;
    while (true) {
        cout << "1. Add contact" << endl;
        cout << "2. Display contacts" << endl;
        cout << "3. Delete contact" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                phonebook.addContact();
                break;
            case 2:
                phonebook.displayContacts();
                break;
            case 3:
                phonebook.deleteContact();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
