#include <iostream>
#include <string>
#include <array>


int main()
    {
    std::array<int, 10> a;
    for ( auto&& i : a )
        {
        std::cout << i << "\n";
        }
    return 0;
    }
