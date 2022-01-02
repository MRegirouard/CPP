/**
 * Project 9-4
 * Traffic Control
 * 
 * Write a program that simulates the operation of
 * traffic lights at an intersection. Use a for loop
 * to create a delay or refer to your compiler's manual
 * for a function such as sleep() to create a delay.
 * The program should display information about the traffic
 * lights in all four directions. Include a left-turn
 * arrow, and don't forget the yellow lights.
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

// Terminal Colors
#define TSTD     "\x1B[0m"
#define TRED     "\x1B[31m"
#define TGREEN   "\x1B[32m"
#define TYELLOW  "\x1B[33m"

#define CLEART   "\x1b[2J\x1b[H"

using namespace std;
// Sleep: https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program

enum class LIGHT
{
    RED = 'R',
    YELLOW = 'Y',
    GREEN = 'G'
};

LIGHT lights[4][3]; // [Road][Position] (0 = left, 1 = straight, 2 = right)
int roadCars[4][4][7]; // [Road][Lane][Position]
// Road: 0-3, road leading up to traffic light
// Lane: 0: going away, 1: turning left, 2: straight, 3: turning right
// Position: 0: farthest from light, 6: right underneath light
// Integer represents position car is heading towards, -1 indicates a car doesn't exist

int middleCars[4][4]; // 4 by 4 area inside the intersection

int runCount = 0;

void addNewRandomCar()
{
    return;

    int toDir = rand() % 4, fromDir = rand() % 4;

    while (toDir == fromDir)
        toDir = rand() % 4;
    
    cout << "Adding new car from " << fromDir << " to " << toDir << endl;

    const int turnDiff = toDir - fromDir;

    int turnDir;

    if (abs(turnDiff) == 2)
        turnDir = 0;
    else if (turnDiff == -1 || turnDiff == 3)
        turnDir = 1;
    else
        turnDir = -1;

    roadCars[fromDir][turnDir + 2][0] = toDir;
}

void printSpace(int spaceCount)
{
    for (int i = 0; i < spaceCount; i++)
        cout << ' ';
}

void printBoard()
{
    //cout << CLEART;
    cout << endl << endl;

    char printGrid[18][36];

    for (int x = 0; x < 18; x++)
        for (int y = 0; y < 36; y++)
            printGrid[x][y] = ' ';

    for (int i = 0; i < 18; i++)
    {
        if (i >= 7 && i <= 10)
            continue;

        printGrid[i][12] = '#';
        printGrid[i][13] = '#';
        printGrid[i][22] = '#';
        printGrid[i][23] = '#';
    }

    for (int i = 0; i < 36; i++)
    {
        if (i >= 14 && i <= 21)
            continue;

        printGrid[6][i] = '#';
        printGrid[11][i] = '#';
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (roadCars[3][j][i] != -1)
            {
                printGrid[j + 7][i * 2] = (char) 48 + roadCars[3][j][i];
                printGrid[j + 7][i * 2 + 1] = (char) 48 + roadCars[3][j][i];
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (roadCars[1][6 - i][3 - j] != -1)
            {
                printGrid[j][i * 2 + 14] = (char) 48 + roadCars[1][6 - i][3 - j];
                printGrid[j][i * 2 + 15] = (char) 48 + roadCars[1][6 - i][3 - j];
            }
        }
    }

    for (int j = 0; j < 3; j++)
    {
        printGrid[j + 8][12] = (char) lights[3][j];
        printGrid[j + 8][13] = (char) lights[3][j];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (middleCars[i][j] != -1)
            {
                printGrid[i + 7][j * 2 + 14] = (char) middleCars[i][j] + 48;
                printGrid[i + 7][j * 2 + 15] = (char) middleCars[i][j] + 48;
            }
        }
    }


    for (int x = 0; x < 18; x++)
    {
        for (int y = 0; y < 36; y++)
        {
            const char printChar = printGrid[x][y];

            if (printChar == 'G')
                cout << TGREEN << printChar << TSTD;
            else if (printChar == 'Y')
                cout << TYELLOW << printChar << TSTD;
            else if (printChar == 'R')
                cout << TRED << printChar << TSTD;
            else
                cout << printChar;
        }

        cout << endl;
    }

    cout << endl << runCount++ << endl;
}

int main()
{
    srand(time(0));

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 7; k++)
                roadCars[i][j][k] = -1;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            lights[i][j] = LIGHT::GREEN;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            middleCars[i][j] = -1;

    for (int i = 1; i < 4; i++)
    {
        roadCars[3][i][0] = i - 1;
    }

    roadCars[3][0][6] = 3;

    while (true)
    {
        // _______________________________________ HANDLE ROAD CARS _______________________________________
        for (int r = 0; r < 4; r++)
        {
            roadCars[r][0][0] = -1; // Clear the last car

            for (int c = 1; c < 7; c++)
            {
                cout << "Moving car";
                roadCars[r][0][c - 1] = roadCars[r][0][c]; // Move cars away from the intersection
                roadCars[r][0][c] = -1;
            }

            for (int l = 1; l < 4; l++) // Handle lanes 1 - 3, lane 0 is a special case (see above)
            {
                for (int c = 6; c >= 0; c--)
                {
                    if (c == 6) // Advancing from the last square is a special case
                    {
                        if (lights[r][l - 1] != LIGHT::RED) // Don't run a red from the last square
                        {
                                int middleX, middleY;

                                switch(r)
                                {
                                    case 0:
                                        middleX = 3 - l;
                                        middleY = 0;
                                        break;
                                    case 1:
                                        middleX = 3;
                                        middleY = 3 - l;
                                        break;
                                    case 2:
                                        middleX = l;
                                        middleY = 3;
                                        break;
                                    case 3:
                                        middleX = 0;
                                        middleY = l;
                                        break;
                                }
                                
                                cout << "Car " << roadCars[r][l][c] << " from " << r << " to " << middleY << ", " << middleX << endl;

                                middleCars[middleY][middleX] = roadCars[r][l][c];
                                roadCars[r][l][c] = -1;
                        }
                    }
                    else
                    {
                        bool shouldAdvance = true;

                        shouldAdvance &= roadCars[r][l][c + 1] == -1; // Don't crash into the next car

                        if (c == 5)
                            shouldAdvance &= lights[r][l - 1] != LIGHT::RED; // If we're on the fifth square, don't run a red light

                        if (c == 5)
                            shouldAdvance &= lights[r][l - 1] != LIGHT::YELLOW; // If a yellow hits while we're on the fifth square, stop

                         // Cars at spot 5 and under will advance no matter what color the light is

                        if (shouldAdvance)
                        {
                            roadCars[r][l][c + 1] = roadCars[r][l][c]; // Move cars towards the intersection
                            roadCars[r][l][c] = -1;
                        }
                    }
                }
            }
        }

        // _______________________________________ HANDLE MIDDLE CARS _______________________________________

        // Handle cars on the corners, only one direction to go in
        for (int x = 0; x < 4; x += 3)
        {
            for (int y = 0; y < 4; y += 3)
            {
                if (middleCars[y][x] != -1)
                {
                    roadCars[middleCars[y][x]][0][6] = middleCars[y][x];
                    middleCars[y][x] = -1;
                }
            }
        }

        int straitVals[4][2] = {{1, 0}, {1, 1}, {0, 2}, {0, 3}};
        int turnVals[4][2]   = {{2, 0}, {2, 1}, {2, 2}, {3, 3}};

        // Handle each road
        for (int road = 0; road < 3; road++)
        {
            for (int i = 0; i < 4; i++) // Rotate the turning and strait values
            {
                int tmp = straitVals[i][0];
                straitVals[i][0] = -(straitVals[i][1] - 2) + 1;
                straitVals[i][1] = tmp;

                tmp = turnVals[i][0];
                straitVals[i][0] = -(turnVals[i][1] - 2) + 1;
                straitVals[i][1] = tmp;
            }

            int straightOnTo = (road + 2) % 4;
            int turningOnTo = (road + 1) % 4;

            // Bump the last position to the other array
            int lastX = straitVals[3][0];
            int lastY = straitVals[3][1];

            if (middleCars[lastY][lastX] != -1)
            {
                roadCars[middleCars[lastY][lastX]][0][6] = middleCars[lastY][lastX];
                middleCars[lastY][lastX] = -1;
            }

            for (int i = 2; i >= 0; i--) // Straight
            {
                int checkX = straitVals[i][0];
                int checkY = straitVals[i][1];
                int nextX = straitVals[i + 1][0];
                int nextY = straitVals[i + 1][1];

                if (middleCars[checkY][checkX] == straightOnTo)
                {
                    middleCars[nextY][nextX] = middleCars[checkY][checkX];
                    middleCars[checkY][checkX] = -1;
                }
            }

            for (int i = 2; i >= 0; i--) // Left turns
            {
                int checkX = turnVals[i][0];
                int checkY = turnVals[i][1];
                int nextX = turnVals[i + 1][0];
                int nextY = turnVals[i + 1][1];

                if (middleCars[checkY][checkX] == turningOnTo)
                {
                    middleCars[nextY][nextX] = middleCars[checkY][checkX];
                    middleCars[checkY][checkX] = -1;
                }
            }
        }

        if (rand() % 2 == 0)
            addNewRandomCar();

        printBoard();

        cout << endl;

        //this_thread::sleep_for(1s);
    }

    return 0;
}