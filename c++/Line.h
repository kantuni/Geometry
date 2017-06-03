#ifndef GEOMETRY_LINE_H
#define GEOMETRY_LINE_H

#include <cmath>
#include "Point.h"

class Line {
  public:
    long double m; // slope
    long double b; // y-intercept
    long double a; // x-intercept

    // create a line from 2 points
    Line(Point, Point);

    // create a line from a point and a slope
    Line(Point, long double);

    // create a line from a slope, a y-intercept, and an x-intercept
    Line(long double, long double, long double);

    // check if 2 lines are parallel
    bool is_parallel(Line);

    // return a point of intersection of 2 lines
    Point point_of_intersection(Line);

    // drop a perpendicular from a point to a line
    Line perpendicular(Point);
};


#endif // GEOMETRY_LINE_H

