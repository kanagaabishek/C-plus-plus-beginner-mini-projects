#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

// Function to get user input (number)
int getuserinput() {
    int a;
    cout << "Enter a value between 1-10: ";
    cin >> a;
    return a;
}

// Function to get computer input (number)
int computerinput() {
    srand(time(0));
    return rand() % 10 + 1;
}

// Function to get user input (letter)
char getletterinput() {
    char d;
    cout << "Enter a letter between A-Z: ";
    cin >> d;
    return d;
}

// Function to get computer input (letter)
char computerletterinput() {
    srand(time(0));
    return 'A' + rand() % 26;
}

int main() {
    char s;
    int c;
    cout << "*******************************" << endl;
    cout << "***********WELCOME*************" << endl;
    cout << "*****GUESSING GAME 2024********" << endl;
    cout << "*******************************" << endl;
    cout << "Enter 's' to begin: ";
    cin >> s;

    while (s == 's') {
        cout << "1. NUMBER GUESSING GAME" << endl;
        cout << "2. LETTER GUESSING GAME" << endl;
        cin >> c;

        if (c == 1) {
            int a = getuserinput();
            int b = computerinput();
            while (a != b) {
                if (a > b) {
                    cout << "Too high!" << endl;
                } else if (a < b) {
                    cout << "Too low!" << endl;
                }
                a = getuserinput();
            }
            cout << "YOU WON BUDDY! Press 's' to replay or any other key to exit: ";
            cin >> s;
        } else if (c == 2) {
            char e = getletterinput();
            char f = computerletterinput();
            while (e != f) {
                cout << "You lost! Try again." << endl;
                e = getletterinput();
            }
            cout << "YOU WON BUDDY! Press 's' to replay or any other key to exit: ";
            cin >> s;
        }
    }
    cout<<"***********thank you for playing... see you again*********************"<<endl;

    return 0;
}
