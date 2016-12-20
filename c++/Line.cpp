//
// Created by Henrikh Kantuni on 12/19/16.
//

#include "Line.h"

// create a line from 2 points
Line::Line(Point p, Point q) {
  this->m = (p.x == q.x) ? NAN : (p.y - q.y) / (p.x - q.x);
  this->b = (isnan(this->m)) ? NAN : p.y - this->m * p.x;
  this->a = (isnan(this->m)) ? p.x : ((this->m == 0) ? NAN : -this->b / this->m);
}

// create a line from a point and a slope
Line::Line(Point p, long double m) {
  this->m = m;
  this->b = (isnan(this->m)) ? NAN : p.y - this->m * p.x;
  this->a = (isnan(this->m)) ? p.x : ((isnan(this->m)) ? NAN : -this->b / this->m);
}

// create a line from a slope, a y-intercept, and an x-intercept
Line::Line(long double m, long double b, long double a) {
  this->m = m;
  this->b = b;
  this->a = a;
}

// check if 2 lines are parallel
bool Line::is_parallel(Line l) {
  return this->m == l.m;
}

// return a point of intersection of 2 lines
Point Line::point_of_intersection(Line l) {
  if (is_parallel(l)) {
    return Point(NAN, NAN);
  }

  long double x, y;
  if (!isnan(this->m) && !isnan(l.m)) {
    x = (l.b - this->b) / (this->m - l.m);
    y = this->m * x + this->b;
  } else if (isnan(this->m)) {
    x = this->a;
    y = l.m * x + l.b;
  } else {
    x = l.a;
    y = this->m * x + this->b;
  }

  return Point(x, y);
}

// drop a perpendicular from a point to a line
Line Line::perpendicular(Point p) {
  if (!isnan(this->m)) {
    // if the point is on the line
    if (p.y == this->m * p.x + this->b) {
      return Line(NAN, NAN, NAN);
    }

    if (this->m == 0) {
      // vertical line
      return Line(NAN, 0, p.x);
    } else {
      // line with a "negative reciprocal" slope
      return Line(p, -1. / this->m);
    }
  } else {
    // if the point is on the line
    if (p.x == this->a) {
      return Line(NAN, NAN, NAN);
    }
    // horizontal line
    return Line(0, p.y, 0);
  }
}
