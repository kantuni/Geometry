//
// Created by Henrikh Kantuni on 12/19/16.
//

#ifndef GEOMETRY_LINE_H
#define GEOMETRY_LINE_H

#include <cmath>
#include "Point.h"

class Line {
  public:
    double m; // slope
    double b; // y-intercept
    double a; // x-intercept

    Line(Point, Point);

    Line(Point, double);

    Line(double, double, double);

    bool is_parallel(Line);

    Point point_of_intersection(Line);

    Line perpendicular(Point);
};


#endif // GEOMETRY_LINE_H
