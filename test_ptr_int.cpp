#include <iostream>


int main()
    {
    int t = 13;
    int* test =  &t;

    std::cout << "*test " << *test  << "\n";
    std::cout << "&test " << &test<< "\n";
    std::cout << "test " << test<< "\n";
    return 0;
    }
