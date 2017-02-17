/*
 * =====================================================================================
 *
 *       Filename:  quick_sort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06.01.2017 01:48:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

void quick_sort(int* arr, int n)
{

    if ( n < 3) 
        return ;
    int pivot = arr[n>>1];
    int left = 0;
    int right = n-1;
    std::cout << pivot << ":  ARRAY START >>>> :  ";
     for ( int i =0 ; i < 10; i++)
    {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;

    do
    {
    while( arr[left] < pivot ) left++;
    while( arr[right] > pivot ) right--;

    if ( left <= right )
    {
       std::cout << arr[pivot] << " : " << arr[left] << " <<>>  " << arr[right] << "\n"; 
       arr[left] ^= arr[right];
       arr[right] ^= arr[left];
       arr[left] ^= arr[right];
       left++;;
       right--;
    }
    }while( left <= right);

    std::cout <<pivot << ": ARRAY END <<<<<  ";
     for ( int i =0 ; i < 10; i++)
    {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
    if ( right > 3) 
    {
    std::cout << "call rigth recursion "<< right << "\n";
    quick_sort(arr, right);   
    }
    if (  n + 3 > left )
    {
    std::cout << "call left recursion " << left << "\n";
    quick_sort(arr+left, n-left);   
    }


}

int main()
{
int n = 10;
int *arr = new int [n];
srand(time(NULL));
for ( int i = 0; i < n; i++)
{
    arr[i] = rand() % 100; 
}
std::cout << " UNSORTED ARRAY:  ";
for ( int i =0 ; i < n; i++)
{
    if ( i == n/2 ) std::cout << " | ";
    std::cout << arr[i] << " , ";
    if ( i == n/2 ) std::cout << " | ";
}
std::cout << std::endl; 
quick_sort(arr, n);
std::cout << " SORTED ARRAY:  ";
for ( int i =0 ; i < n; i++)
{
    if ( i == n/2 ) std::cout << " | ";
    std::cout << arr[i] << " , ";
    if ( i == n/2 ) std::cout << " | ";
}
std::cout << std::endl; 
return 0;
}
