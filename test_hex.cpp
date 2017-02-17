/*
 * =====================================================================================
 *
 *       Filename:  test_hex.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09.10.2015 16:27:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>     // std::cout, std::dec, std::hex, std::oct
#include <sstream>
#include <string>
#include "boost/lexical_cast.hpp"

int main () {
/*
    std::string s = "7dd0ed271";
    unsigned uint32_t y = std::stoul(s, nullptr, 16);
    std::cout << y << "\n";
*/
    uint32_t x;   
    std::stringstream ss;
    ss << std::hex << "7dd0ed21"; //"7dd0ed26f877064cffa336e27287abc6bab3f5b5";
    ss >> x;

    //std::cout << static_cast<uint32_t>(x) << std::endl;
    ///uint8_t array[8] = { 0x01, 0x00, 0xcb, 0xbe, 0xa4, 0x63, 0x95, 0x8f };
    //x <<= 8;
    //x |=  array[1];
    // output it as a signed type
    std::cout << static_cast<uint32_t>(x) << std::endl;

    /*
  const char n[] = "7dd0ed271";
  std::cout << std::dec << (int)n << '\n';
  std::cout << std::hex << (int)n << '\n';
  std::cout << std::oct << (int)n << '\n';
*/
  return 0;
}
