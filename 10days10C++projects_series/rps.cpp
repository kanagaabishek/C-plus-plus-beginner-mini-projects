#include <iostream>
#include <ctime>
using namespace std;

char getuserinput() {
    char b;
    cout << "'r' for rock\n";
    cout << "'p' for paper\n";
    cout << "'s' for scissors\n";
    cin >> b;
    return b;
}

char getcomputerinput() {
    srand(time(0));
    int c = rand() % 3 + 1;
    switch (c) {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
        default: return 'r'; // default case to avoid warnings
    }
}

void showchoice(char choice) {
    switch (choice) {
        case 'r': cout << "Rock\n"; break;
        case 'p': cout << "Paper\n"; break;
        case 's': cout << "Scissors\n"; break;
    }
}

int main() {
    char a, person, computer;
    cout << "******Welcome to RPS game******\n";
    cout << "*******************************\n";
    cout << "TYPE 's' TO START THE GAME\n";
    cin >> a;
    while (a == 's') {
        person = getuserinput();
        cout << "Your input: ";
        showchoice(person);
        computer = getcomputerinput();
        cout << "Computer input: ";
        showchoice(computer);
        if(person == computer){
            cout << "It's a tie\n";
        }
        else if((person == 'p' && computer == 'r') || (person == 's' && computer == 'p') || (person == 'r' && computer == 's')){
            cout << "You won! Great job!\n";
        }
        else {
            cout << "You lost! Better luck next time!\n";
        }
        cout << "TYPE 's' TO PLAY AGAIN OR ANY OTHER KEY TO EXIT\n";
        cin >> a;
    }
    cout << "******THANK YOU FOR PLAYING******\n";
    return 0;
}



