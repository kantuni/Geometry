#ifndef GEOMETRY_CIRCLE_H
#define GEOMETRY_CIRCLE_H
#include "Point.h"
#include "Line.h"

class Circle {
  public:
    long double x;
    long double y;
    long double r;

    // center.x, center.y, radius
    Circle(long double, long double, long double);

    // check if a point is inside the circle
    bool point_in_circle(Point);

    // check if a line intersects the circle
    bool line_intersects_circle(Line);
};

#endif // GEOMETRY_CIRCLE_H
