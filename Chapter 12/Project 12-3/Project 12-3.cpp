/**
 * Project 12-3
 * 
 * 
 * Add a method to the circle class that returns the circumference
 * of the circle. Modify OOP.CPP to report the circumference.
 */

#include "Circle.cpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Circle circle1(0);
    Circle circle2(circle1);
    Circle circle3(10);

    std::cout << "Circle 1 Radius: " << circle1.getRadius() << std::endl;
    std::cout << "Circle 1 Area: " << circle1.getArea() << std::endl;
    std::cout << "Circle 2 Radius: " << circle2.getRadius() << std::endl;
    std::cout << "Circle 2 Area: " << circle2.getArea() << std::endl;
    std::cout << "Circle 3 Radius: " << circle3.getRadius() << std::endl;
    std::cout << "Circle 3 Area: " << circle3.getArea() << std::endl;

    if (circle1 == circle2)
        std::cout << "Circle 1 and Circle 2 are equal" << std::endl;
    else
        std::cout << "Circle 1 and Circle 2 are not equal" << std::endl;

    if (circle1 != circle3)
        std::cout << "Circle 1 and Circle 3 are not equal" << std::endl;
    else
        std::cout << "Circle 1 and Circle 3 are equal" << std::endl;

    if (circle1 < circle3)
        std::cout << "Circle 1 is less than Circle 3" << std::endl;
    else
        std::cout << "Circle 1 is not less than Circle 3" << std::endl;


    circle1.setRadius(5);

    return 0;
}