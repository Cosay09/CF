#include <iostream>
#include <random>
#include <conio.h>
using namespace std;

bool gameover;

const int width = 50;
const int height = 20;

int scoreA, scoreB;

int ballX, ballY;
int ballDirX = -1, ballDirY = -1;

int padAx = height / 2;
int padAy = 2;
int padBx = height / 2;
int padBy = width - 3;
const int paddlesize = 3;

string player1, player2;

enum edirection
{
    stop = 0,
    up,
    down,
    upB,
    downB
};
edirection dirA = stop;
edirection dirB = stop;

void setup();
void draw();
void input();
void logic();
void result();

int main()
{
    srand(time(0));
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
        _sleep(50);
    }
    result();
    return 0;
}

void setup()
{
    gameover = false;
    ballX = width / 2;
    ballY = height / 2;
    scoreA = 0, scoreB = 0;

    cout << "Enter contestant 1's name: ";
    getline(cin, player1);
    cout << "Enter contestant 2's name: ";
    getline(cin, player2);
}
void result()
{
    system("cls");
    cout << "Game Over!" << endl;
    cout << player1 << "'s Score: " << scoreA << endl;
    cout << player2 << "'s Score: " << scoreB << endl;

    if (scoreA > scoreB)
        cout << player1 << " wins! Congratulations!" << endl;
    else if (scoreB > scoreA)
        cout << player2 << " wins! Congratulations!" << endl;
    else
        cout << "It's a draw! Well played both!" << endl;
}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dirA = up;
            break;
        case 's':
            dirA = down;
            break;
        case 'i':
            dirB = upB;
            break;
        case 'k':
            dirB = downB;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}
void logic()
{
    if (dirA == up && padAx - paddlesize / 2 > 0) //If reaches top then doesn't go up anymore
        padAx--;
    else if (dirA == down && padAx + paddlesize / 2 < height - 1)
        padAx++;

    if (dirB == upB && padBx - paddlesize / 2 > 0) //If teaches bottom then doesn't go down anymore
        padBx--;
    else if (dirB == downB && padBx + paddlesize / 2 < height - 1)
        padBx++;

    ballX += ballDirX;
    ballY += ballDirY;
    if (ballY == 0 || ballY == height - 1)
        ballDirY *= -1;
    if (ballX == padAy + 1 && 
        (ballY == padAx || ballY  == padAx - 1 || ballY == padAx + 1))
        ballDirX *= -1;
    if (ballX == padBy - 1 && 
        (ballY == padBx || ballY == padBx - 1 || ballY == padBx + 1))
        ballDirX *= -1;
    if (ballX <= 0)
    {
        scoreB++;
        ballX = width / 2;
        ballY = height / 2;
        ballDirX = 1;
        ballDirY = (rand() % 2 == 0) ? 1 : -1;
    }
    if (ballX >= width)
    {
        scoreA++;
        ballX = width / 2;
        ballY = height / 2;
        ballDirX = 1;
        ballDirY = (rand() % 2 == 0) ? 1 : -1;
    }
}
void draw()
{
    system("cls");
    int leftPaddingA = (width / 2 - player1.size()) / 2; // Padding for Player A
    int leftPaddingB = (width / 2 - player2.size()) / 2; // Padding for Player B

    // Display player names at the top
    cout << string(leftPaddingA - 1, ' ') << player1 << "-" << scoreA // Center Player A
         << string((width / 2) - leftPaddingA - player1.size(), ' ') << "|"
         << string(leftPaddingB, ' ') << player2 << "-" << scoreB // Center Player B
         << string((width / 2) - leftPaddingB - player2.size(), ' ') << endl;

    for (int i = 0; i < width + 2; i++)
        cout << "#"; // top floor
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#"; // left wall
            if ((j == padAy && i >= padAx - paddlesize / 2 && i <= padAx + paddlesize / 2) ||
                (j == padBy && i >= padBx - paddlesize / 2 && i <= padBx + paddlesize / 2))
                cout << "|";
            else if (j == width / 2)
                cout << "|";
            else if (j == ballX && i == ballY)
                cout << "O";
            else
                cout << " ";
            if (j == width - 1)
            {
                cout << "#"; // right wall
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
        cout << "#"; // bottom floor
    cout << endl;
}