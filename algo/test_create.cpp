/*
 * =====================================================================================
 *
 *       Filename:  test_create.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.12.2016 17:43:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <math.h>

int calculate1(int degree)
{
    return pow(2,degree);
}
int calculate2(int degree)
{
    int a = 1;
    for ( int i = 1; i <= degree; i++)
    {
        a *= 2;
    }
    return a;
}
int calculate3(int degree)
{
    int a = 1;
    for ( int i = 1; i <= degree; i++)
    {
        a <<= 1;
    }
    return a;
}
int main()
{
    std::cout << " print degree of 2 = "; 
    int t;
    std::cin >> t;
    std::cout << " 1 degree of 2 on " << t << " = " << calculate1(t) << " \n";
    std::cout << " 2 degree of 2 on " << t << " = " << calculate2(t) << " \n";
    std::cout << " 3 degree of 2 on " << t << " = " << calculate3(t) << " \n";
    return 0;
}
