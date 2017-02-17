#include <iostream>
#include <signal.h>


int main()
    {
    signal(SIGINT, SIG_IGN); 
    while (true)
    {
        std::cout << "while " << "\n";
        //sleep(1);
    }
    std::cout << "!!!! BUG !!! sigint is work" << "\n";
    return 0;
    }
