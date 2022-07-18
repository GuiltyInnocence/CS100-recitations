#include <bits/stdc++.h>
#include <iostream>
/*
class point {
public:
  point(double a, double b) : x(a), y(b) {}
  point() : point(0, 0) {}
//   point(point &p2) = delete;
//   explicit point(point& p2)=default;

//   point(point& p2)=default;
    point(const point& p2, int tag=0, bool flag=false){x=p2.x;y=tag/(flag?1.1:2.2);}
  void foo(){x++;y++;}
  double x, y;
};
*/
int main(){
    const int i=233;
    const int *const p=&i;
    const int* const &p2=p;
    std::cout<<*p2;
    return 0;
}