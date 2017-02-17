#include <iostream>
#include <unistd.h>
#include <stdio.h>
int main()
    {
    for (int i =1; i < 100; i++)
    {
    clock_t max_begin = clock();
    sleep(1);
    std::cout << "=>" << i  << "\n";
    clock_t max_end = clock();
    double elapsed_secs = double(max_end - max_begin) / CLOCKS_PER_SEC;
    printf ("############### Total  %.4lf ",  elapsed_secs );
    }
    return 0;
    }
