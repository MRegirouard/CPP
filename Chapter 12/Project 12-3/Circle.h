#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <stdexcept>

#define PI 3.14159265358979323846

/**
 * @brief Represents a circle
 */
class Circle
{
public:
    Circle(double radius = 0);
    Circle(const Circle &circle);

    void setRadius(float radius);
    float getRadius() const;
    double getArea() const;

    bool operator==(const Circle &other) const;
    bool operator!=(const Circle &other) const;
    void operator=(const Circle &other);
    bool operator<(const Circle &other) const;
    bool operator>(const Circle &other) const;
    bool operator<=(const Circle &other) const;
    bool operator>=(const Circle &other) const;

private:

    /**
     * @brief The radius of this circle
     */
    float radius;
};

#endif // CIRCLE_H_