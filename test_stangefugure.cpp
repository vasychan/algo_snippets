#include <iostream>


int main()
    {
    bool booltest = false;

    booltest |= false;
    
    if (booltest == true)
        std::cout << "true" << "\n";
    return 0;
    }
