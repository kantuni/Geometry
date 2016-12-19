//
// Created by Henrikh Kantuni on 12/19/16.
//

#include "Circle.h"

Circle::Circle(Point *center, double radius) {
  this->center = center;
  this->radius = radius;
}

Point Circle::get_center() {
//  return this->&center;
}

double Circle::get_radius() {
  return this->radius;
}

bool Circle::point_in_circle(Point p) {
//  double temp = pow(p.get_x() - (this->&center).get_x(), 2);
//  temp += pow(p.get_y() - (this->&center).get_y(), 2);
//  return temp < pow(this->radius, 2);
}

bool Circle::line_intersects_circle(Line l) {
//  Line perpendicular = l.perpendicular(this->&center);
//  bool condition = isnan(perpendicular.get_m());
//  condition = condition && isnan(perpendicular.get_b());
//  condition = condition && isnan(perpendicular.get_a());
//
//  if (condition) {
//    return true;
//  } else {
//    Point intersection = l.point_of_intersection(perpendicular);
//    return isnan(intersection.get_x()) && isnan(intersection.get_y()) && point_in_circle(intersection);
//  }
}
