#include "Circle.h"

// center.x, center.y, radius
Circle::Circle(long double x, long double y, long double r) {
  this->x = x;
  this->y = y;
  this->r = r;
}

// check if a point is inside the circle
bool Circle::point_in_circle(Point p) {
  long double temp = powl(p.x - this->x, 2);
  temp += powl(p.y - this->y, 2);
  return temp < powl(this->r, 2);
}

// check if a line intersects the circle
bool Circle::line_intersects_circle(Line l) {
  Line perpendicular = l.perpendicular(Point(this->x, this->y));
  // line through the center of the circle
  bool ltc = isnan(perpendicular.m) && isnan(perpendicular.b) && isnan(perpendicular.a);
  if (ltc) {
    return true;
  } else {
    Point intersection = l.point_of_intersection(perpendicular);
    return !isnan(intersection.x) && !isnan(intersection.y) && point_in_circle(intersection);
  }
}
