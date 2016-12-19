//
// Created by Henrikh Kantuni on 12/19/16.
//

#include "Line.h"

Line::Line(Point p, Point q) {
  this->m = (p.x == q.x) ? NAN : (p.y - q.y) / (p.x - q.x);
  this->b = (isnan(this->m)) ? NAN : p.y - this->m * p.x;
  this->a = (isnan(this->m)) ? p.x : ((this->m == 0) ? NAN : -this->b / this->m);
}

Line::Line(Point p, double m) {
  this->m = m;
  this->b = (isnan(this->m)) ? NAN : p.y - this->m * p.x;
  this->a = (isnan(this->m)) ? p.x : ((isnan(this->m)) ? NAN : -this->b / this->m);
}

Line::Line(double m, double b, double a) {
  this->m = m;
  this->b = b;
  this->a = a;
}

bool Line::is_parallel(Line l) {
  return this->m == l.m;
}

Point Line::point_of_intersection(Line l) {
  if (is_parallel(l)) {
    return Point(NAN, NAN);
  }

  double x, y;
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

Line Line::perpendicular(Point p) {
  if (!isnan(this->m)) {
    if (p.y == this->m * p.x + this->b) {
      return Line(NAN, NAN, NAN);
    }

    if (this->m == 0) {
      return Line(NAN, 0, p.x);
    } else {
      return Line(p, -1. / this->m);
    }
  } else {
    if (p.x == this->a) {
      return Line(NAN, NAN, NAN);
    }

    return Line(0, p.y, 0);
  }
}
