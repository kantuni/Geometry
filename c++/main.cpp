#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"

using namespace std;

int main() {
  cout << "Debug: Point" << endl;
  Point p1(0, 0);
  Point q1(1, 1);
  Point p2(-1, 1);
  Point q2(1, 3);
  cout << p1.x << ", " << p1.y << endl;
  cout << q1.x << ", " << q1.y << endl;
  cout << p2.x << ", " << p2.y << endl;
  cout << q2.x << ", " << q2.y << endl;

  cout << endl << "Debug: Line" << endl;
  Line l1(p1, q1);
  Line l2(p2, q2);
  cout << "l1 slope: " << l1.m << endl;
  cout << "l1 y-intercept: " << l1.b << endl;
  cout << "l1 x-intercept: " << l1.a << endl;
  cout << "l2 slope: " << l2.m << endl;
  cout << "l2 y-intercept: " << l2.b << endl;
  cout << "l2 x-intercept: " << l2.a << endl;
  cout << "Is l1 parallel to l2: " << l1.is_parallel(l2) << endl;

  return 0;
}
