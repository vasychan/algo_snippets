/*
 * =====================================================================================
 *
 *       Filename:  bubble_sort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05.01.2017 19:06:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

int main () 
{

int list[] = { 1,4,5,7,2,4,6 };

for ( int j = 0; j < sizeof(list)/sizeof(int); j++ )
{
    for ( int i = 0; i < sizeof(list)/sizeof(int); i++ )
    {
        if (list[i] < list[i-1])
        {
            int x = list[i-1];
            list[i-1] = list[i];
            list[i] = x;
        }
    }
}

for ( int a = 0; a < sizeof(list)/sizeof(int); a++)
{
    std::cout << list[a] << " , " ;
}
std::cout << std::endl;
return 0;
}
