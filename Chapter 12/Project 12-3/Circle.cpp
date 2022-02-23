#include "Circle.h"

/**
 * @brief Construct a new Circle with the given radius
 * @param radius The radius for this Circle
 */
Circle::Circle(double radius)
{
    setRadius(radius);
}

/**
 * @brief Copy the given Circle into this new Circle
 * @param circle The Circle to copy
 */
Circle::Circle(const Circle &circle)
{
    setRadius(circle.radius);
}

/**
 * @brief Set the radius for this Circle
 * @param newRadius The new radius to set
 */
void Circle::setRadius(float newRadius)
{
    if (newRadius < 0)
        throw std::invalid_argument("A Circle's radius cannot be negative");
    else
        this->radius = newRadius;
}

/**
 * @brief Get the radius for this Circle
 * @return The radius of this Circle
 */
float Circle::getRadius() const
{
    return radius;
}

/**
 * @brief Get the area of this Circle
 * @return The area of this Circle
 */
double Circle::getArea() const
{
    return PI * radius * radius;
}

/**
 * @brief Determines if this Circle is equal to the given Circle
 * @param other The Circle to compare to
 * @return True if the Circles' radii are equal, false otherwise
 */
bool Circle::operator==(const Circle &other) const
{
    return radius == other.radius;
}

/**
 * @brief Determines if this Circle is not equal to the given Circle
 * @param other  The Circle to compare to
 * @return True if the Circles' radii are not equal, false otherwise
 */
bool Circle::operator!=(const Circle &other) const
{
    return radius != other.radius;
}

/**
 * @brief Assign the given Circle to this Circle
 * @param other The Circle to assign to this Circle
 */
void Circle::operator=(const Circle &other)
{
    setRadius(other.radius);
}

/**
 * @brief Determines if this Circle is less than the given Circle
 * @param other The Circle to compare to
 * @return True if this Circle's radius is less than the given Circle's radius, false otherwise
 */
bool Circle::operator<(const Circle &other) const
{
    return radius < other.radius;
}

/**
 * @brief Determines if this Circle is greater than the given Circle
 * @param other The Circle to compare to
 * @return True if this Circle's radius is greater than the given Circle's radius, false otherwise
 */
bool Circle::operator>(const Circle &other) const
{
    return radius > other.radius;
}

/**
 * @brief Determines if this Circle is less than or equal to the given Circle
 * @param other The Circle to compare to
 * @return True if this Circle's radius is less than or equal to the given Circle's radius, false otherwise
 */
bool Circle::operator<=(const Circle &other) const
{
    return radius <= other.radius;
}

/**
 * @brief Determines if this Circle is greater than or equal to the given Circle
 * @param other The Circle to compare to
 * @return True if this Circle's radius is greater than or equal to the given Circle's radius, false otherwise
 */
bool Circle::operator>=(const Circle &other) const
{
    return radius >= other.radius;
}