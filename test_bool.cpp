#include <iostream>


int main()
    {
    bool a = false;
    bool b = true;
    bool c = true;
    bool d = true;
    if (a || (!(b && c) && d))
        std::cout << "true" << "\n";
    else
        std::cout << "false " << "\n";
    return 0;
    }
