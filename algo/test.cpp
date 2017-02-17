#include <iostream>

class A {
public:
    A() {}
    ~A() {
        throw 42;
    }
};

int main() {
int a = 5;
auto&& b = a++;
auto&& c = ++a;
++a;
printf("%d %d %d", a, b, c);
}
