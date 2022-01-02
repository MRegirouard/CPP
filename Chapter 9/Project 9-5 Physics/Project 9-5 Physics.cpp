/**
 * Project 9-5
 * Physics
 * 
 * Einstein predicted that the length of an object gets smaller as the
 * object moves more quickly. Use the formula
 * length = (length_at_zero * sqrt(1 - ((velocity * velocity)/(c * c)))),
 * where C equals the speed of light (3.00 * 10^8 m/sec), to calculate
 * the new length when given the velocity and length at zero speed.
 * Declare C as a constant. Lengths should be entered in meters.
 */

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    const double c = 3.00 * pow(10, 8);

    double length_at_zero, velocity, length;

    std::cout << "Enter the length at zero speed: ";
    std::cin >> length_at_zero;
    std::cout << "Enter the velocity: ";
    std::cin >> velocity;

    length = (length_at_zero * sqrt(1 - ((velocity * velocity)/(c * c))));

    std::cout << "The length is " << length << " meters." << std::endl;

    std::cout << "Enter a length to calculate the velocity for: ";
    std::cin >> length;

    velocity = sqrt(-c * c * ((length / length_at_zero) * (length / length_at_zero) - 1));

    std::cout << "The velocity is " << velocity << " meters per second." << std::endl;

    return 0;
}