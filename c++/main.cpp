#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"

using namespace std;

int main() {
  cout << "Debug: Point" << endl;
  Point p1 = Point(0, 0);
  Point q1 = Point(1, 1);
  Point p2 = Point(200, 100);
  Point q2 = Point(1000, 300);
  cout << p1.x << ", " << p1.y << endl;
  cout << q1.x << ", " << q1.y << endl;
  cout << p2.x << ", " << p2.y << endl;
  cout << q2.x << ", " << q2.y << endl;


  cout << endl << "Debug: Line" << endl;
  Line l1 = Line(p1, q1);
  Line l2 = Line(p2, q2);
  cout << "l1 slope: " << l1.m << endl;
  cout << "l1 y-intercept: " << l1.b << endl;
  cout << "l1 x-intercept: " << l1.a << endl;
  cout << "l2 slope: " << l2.m << endl;
  cout << "l2 y-intercept: " << l2.b << endl;
  cout << "l2 x-intercept: " << l2.a << endl;
  cout << "Is l1 parallel to l2: " << l1.is_parallel(l2) << endl;

  Point intersection = l1.point_of_intersection(l2);
  cout << "Point of intersection of l1 and l2: " << intersection.x << ", " << intersection.y << endl;

  Line perpendicular = l1.perpendicular(p2);
  cout << "perpendicular slope: " << perpendicular.m << endl;
  cout << "perpendicular y-intercept: " << perpendicular.b << endl;
  cout << "perpendicular x-intercept: " << perpendicular.a << endl;


  cout << endl << "Debug: Circle" << endl;
  Circle c = Circle(p1.x, p1.y, 10);
  cout << "Point in circle: " << c.point_in_circle(q1) << endl;
  cout << "Line intersects circle: " << c.line_intersects_circle(l2) << endl;

  return 0;
}
