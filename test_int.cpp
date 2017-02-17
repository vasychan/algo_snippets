#include <iostream>
#include <iostream>     // std::cout, std::dec, std::hex, std::oct
#include <sstream>
#include <string>              
#include "boost/lexical_cast.hpp"

#include <stdint.h>
class A
{

};

int main()
    {
        /*
    A a = A();  
    A *a_ptr = new A();  
    bool test = false;
    while (!test)
    {
        
        std::cout << "while " << "\n";
    }
    */
    uint32_t max = UINT32_MAX;
    std::cout << max << "\n";
    return 0;
    }
