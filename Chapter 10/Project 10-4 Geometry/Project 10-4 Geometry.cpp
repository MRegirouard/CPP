/**
 * Project 10-4
 * Geometry
 * 
 * On a coordinate plane, the length of a line connecting
 * two points can be found using the formula below:
 * sqrt((x2 - x1)^2 + (y2 - y1)^2)
 * Extend the program from exercise 10-9 to calculate
 * the length of the line using the formula above.
 */

#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
    double x, y;
    
    Point(double x, double y) : x(x), y(y) {};
    
    double distance(Point p)
    {
        double xDiff = x - p.x;
        double yDiff = y - p.y;

        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }
};


int main(int argc, char const *argv[])
{
    if (argc != 5)
    {
        cout << "Error: Exactly four arguments are required: P1 X, P1 Y, P2 X, P2 Y" << endl;
        return 1;
    }

    // https://stackoverflow.com/questions/4951952/integer-arguments-for-c

    Point p1 = {atoi(argv[1]), atoi(argv[2])};
    Point p2 = {atoi(argv[3]), atoi(argv[4])};

    cout << "Distance from point (" << p1.x << ", " << p1.y << ") to (" << p2.x << ", " << p2.y << ") is ";
    cout << p1.distance(p2) << endl;

    return 0;
}