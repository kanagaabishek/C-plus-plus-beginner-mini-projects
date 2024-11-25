#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

enum directions { STOP = 0, LEFT, RIGHT, UP, DOWN };
directions dir;
const int height = 20;
const int width = 20;

class snake_game {
private:
    int headX, headY;
    int foodX, foodY;
    int score;
    int tailX[100], tailY[100];
    int tail_len;
    bool gameOver;

public:
    snake_game();
    ~snake_game();
    void game(char s);
    void setup();
    void draw();
    void control();
    void logic();
    bool isGameOver() { return gameOver; } // Public method to access gameOver
};

snake_game::snake_game() {
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
    tail_len = 0;
}

snake_game::~snake_game() {}

void snake_game::game(char s) {
    if (s == 's') {
        gameOver = false;
        setup();
    } else {
        gameOver = true;
    }
}

void snake_game::setup() {
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
    tail_len = 0;
}

void snake_game::draw() {
    system("cls");
    // Upper border
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    // Left and right borders, snake, and food
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout << "#";
            } else if (i == headY && j == headX) {
                cout << "O";
            } else if (i == foodY && j == foodX) {
                cout << "*";
            } else {
                bool print = false;
                for (int k = 0; k < tail_len; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    // Lower border
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    cout << "Score: " << score << endl;
}

void snake_game::control() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        }
    }
}

void snake_game::logic() {
    // Tail logic
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = headX;
    tailY[0] = headY;
    for (int i = 1; i < tail_len; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Direction logic
    switch (dir) {
    case LEFT:
        headX--;
        break;
    case RIGHT:
        headX++;
        break;
    case UP:
        headY--;
        break;
    case DOWN:
        headY++;
        break;
    default:
        break;
    }

    // Touch walls
    if (headX >= width) {
        headX = 0;
    } else if (headX < 0) {
        headX = width - 1;
    }
    if (headY >= height) {
        headY = 0;
    } else if (headY < 0) {
        headY = height - 1;
    }

    // Snake bites itself
    for (int i = 0; i < tail_len; i++) {
        if (tailX[i] == headX && tailY[i] == headY) {
            gameOver = true;
        }
    }

    // Snake eats food
    if (headX == foodX && headY == foodY) {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        tail_len++;
    }
}

int main() {
    cout << "***************************************" << endl;
    cout << "*************WELCOME*******************" << endl;
    cout << "***********Snake___Game****************" << endl;
    cout << "***************************************" << endl;
    char s;
    cout << "Enter 's' to start the game" << endl;
    cin >> s;
    snake_game o;
    o.game(s);
    while (!o.isGameOver()) { // Use the public method to check gameOver
        o.draw();
        o.control();
        o.logic();
        Sleep(100); // Adjust speed
    }
    cout << "Game Over!" << endl;
    return 0;
}


