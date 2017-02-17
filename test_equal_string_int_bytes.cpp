#include <iostream>
#include <string>
#include <limits>
#include <stdint.h>
#include <boost/lexical_cast.hpp>


int main()
    {
    std::string str("123456718446744073709551615");
    uint64_t val = std::numeric_limits<uint64_t>::max();
    uint64_t str_val = 0;
    try
    {
        str_val = boost::lexical_cast<uint64_t>(str);
    }
    catch(std::bad_cast& except)
    {
        std::cout << "wrong size" << std::endl; 
    }
    std::cout << str.size() << " with " << str_val << " == " << val << std::endl;
    return 0;
    }
