
#include <iostream>
enum TEST
    {
    ONE,
    TWO
    };

template<TEST A>
struct test { };


template<>
struct test<ONE>
    {
    void print();// { std::cout << " ONE " << "\n"; } 
    };

template<>
struct test<TWO>
    {
    void print();// { std::cout << " TWO " << "\n"; }
    };


