//
//  Point
//  Geometry
//
//  Created by Henrikh Kantuni on 12/17/16.
//  Copyright © 2016 Henrikh Kantuni. All rights reserved.
//

#include <iostream>
using namespace std;

class Point {
  private:
    double x;
    double y;
  
  public:
    Point(double x, double y) {
      this->x = x;
      this->y = y;
    }
  
    friend ostream &operator << (ostream &output, const Point &p) {
      return output << "(" << p.x << ", " << p.y << ")";
    }
};
