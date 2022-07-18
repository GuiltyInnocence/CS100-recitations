#include <iostream>
#include <bits/stdc++.h>
class base{
public:
    virtual void f() {puts("base::f()");}
};
class d1: public base{
public:
    virtual void f() override {puts("d1::f()");}
    void f(int a) {puts("d1::f(int)");a++;}
    void f(double a) {puts("d1::f(double)");a*=a;}
};
class d2: public d1{
public:
    void f() override {puts("d2::f()");}
    void f(int a) {puts("d2::f(int)");a++;}
    void tryit(){d1::f(3.14);}
    void fail(){f(3.14);}
};

int main() {
    d2 d;
    d.f();
    d.f(233);
    d.f(3.14);
    d.tryit();
    d.fail();
    return 0;
}
