//
//  Line
//  Geometry
//
//  Created by Henrikh Kantuni on 12/17/16.
//  Copyright © 2016 Henrikh Kantuni. All rights reserved.
//

#include <iostream>
using namespace std;

class Line {
  private:
    double m;
    double b;
    double a;
  
  public:
    Line(double m, double b, double a) {
      this->m = m;
      this->b = b;
      this->a = a;
    }
  
    friend ostream &operator << (ostream &output, const Point &p) {
      return output << "(" << p.x << ", " << p.y << ")";
    }
};
