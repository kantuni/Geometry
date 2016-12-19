//
// Created by Henrikh Kantuni on 12/19/16.
//

#ifndef GEOMETRY_CIRCLE_H
#define GEOMETRY_CIRCLE_H

#include "Point.h"
#include "Line.h"

class Circle {
  private:
    Point *center;
    double radius;

  public:
    Circle(Point *, double);

    Point get_center();

    double get_radius();

    bool point_in_circle(Point);

    bool line_intersects_circle(Line);
};


#endif // GEOMETRY_CIRCLE_H
