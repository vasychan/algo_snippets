#include <iostream>


int main()
    {
    char s[] = "hello";
    int i = 0;
    while (s[i] != 0 )
    {
        
        std::cout << *(s+i)  << "\n";
        i++;
    }
    return 0;
    }
