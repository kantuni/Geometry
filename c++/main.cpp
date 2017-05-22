#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"
using namespace std;

int main() {
  cout << "DEBUG: Point\n";
  Point p1 = Point(0, 0);
  Point q1 = Point(1, 1);
  Point p2 = Point(200, 100);
  Point q2 = Point(1000, 300);
  cout << p1.x << ", " << p1.y << "\n";
  cout << q1.x << ", " << q1.y << "\n";
  cout << p2.x << ", " << p2.y << "\n";
  cout << q2.x << ", " << q2.y << "\n";

  cout << "\nDEBUG: Line\n";
  Line l1 = Line(p1, q1);
  Line l2 = Line(p2, q2);
  cout << "l1 slope: " << l1.m << "\n";
  cout << "l1 y-intercept: " << l1.b << "\n";
  cout << "l1 x-intercept: " << l1.a << "\n";
  cout << "l2 slope: " << l2.m << "\n";
  cout << "l2 y-intercept: " << l2.b << "\n";
  cout << "l2 x-intercept: " << l2.a << "\n";
  cout << "Is l1 parallel to l2: " << l1.is_parallel(l2) << "\n";

  Point intersection = l1.point_of_intersection(l2);
  cout << "Point of intersection of l1 and l2: " << intersection.x << ", " << intersection.y << "\n";

  Line perpendicular = l1.perpendicular(p2);
  cout << "perpendicular slope: " << perpendicular.m << "\n";
  cout << "perpendicular y-intercept: " << perpendicular.b << "\n";
  cout << "perpendicular x-intercept: " << perpendicular.a << "\n";

  cout << "\nDEBUG: Circle\n";
  Circle c = Circle(p1.x, p1.y, 10);
  cout << "Point in circle: " << c.point_in_circle(q1) << "\n";
  cout << "Line intersects circle: " << c.line_intersects_circle(l2) << "\n";

  return 0;
}
