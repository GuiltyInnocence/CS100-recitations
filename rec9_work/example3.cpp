#include <bits/stdc++.h>

class base{
public:
    virtual void f() {puts("base::f()");}
};
class d1: public base{
public:
    void f() override{puts("d1::f()");}
    void f(int a) {puts("d1::f(int)");a*=a;}
    void f(double a) {puts("d1::f(double)");a*=a;}
};
class d2: public d1{
public:
    using d1::f;
};
class d3: public d2{
    void f() override{puts("d3::f()");}
};
int main(){
    d2 d;
    d.f();
    d.f(3);
    d.f(3.14);
    return 0;
}