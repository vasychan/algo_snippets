#include <iostream>
#include <string>


struct test { std::string b ;};

int main()
    {

    test a_array[2]; 
    //a_array[0] = new test();
    //a_array[1] = new test();
    test* a_ptr = a_array;
    //a_ptr = a_ptr + 1;
    int d = ( (a_array - a_ptr) + 1) % 2;
    //std::cout << timebuff << "\n";
    return 0;
    }
