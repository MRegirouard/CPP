/**
 * Project 10-5
 * Geometry
 * 
 * Write a program that accepts to points as input.
 * Have the program calculate a third point that, with
 * the other two points in a plane, form a right triangle. 
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

    static double calcSlope(Point p1, Point p2)
    {
        return (p2.y - p1.y) / (p2.x - p1.x);
    }

    static Point calcRight(Point p1, Point p2, double xCoord)
    {
        double slope = calcSlope(p1, p2);
        double slope90 = -1/slope;
        double newY = slope90 * (xCoord - p1.x) + p1.y;
        
        return {xCoord, newY};
    }

    // https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
    friend ostream &operator<< (ostream &output, Point &p)
    {
        output << "(" << p.x << ", " << p.y << ")";
        return output;
    }
};

int main(int argc, char const *argv[])
{
    if (argc != 6)
    {
        cout << "Error: Exactly five arguments are required: P1 X, P1 Y, P2 X, P2 Y, X Coordinate" << endl;
        return 1;
    }

    // https://stackoverflow.com/questions/4951952/integer-arguments-for-c
    
    Point p1 = {atoi(argv[1]), atoi(argv[2])};
    Point p2 = {atoi(argv[3]), atoi(argv[4])};
    Point p3 = Point::calcRight(p1, p2, atol(argv[5]));

    cout << p3 << endl;

    return 0;
}