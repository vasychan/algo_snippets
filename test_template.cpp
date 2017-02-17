#include <iostream>

#include "test_template.hpp"
void test<ONE>::print()
    {
    std::cout << "SPEC ONE " <<"\n";
    };

void test<TWO>::print()
    {
    std::cout << " SPEC TWO"  <<"\n";
    }

//template<> test<ONE>::test();

int main()
    {
    test<ONE> test1;
    test1.print();
    test<TWO> test2;
    test2.print();
    return 0;
    }
