#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>


int main()
    {
    std::string u_value = "20.03.2015/0:2/1:3/5:0";
    std::cout << u_value.c_str() << "\n";
    char *str = strdup(u_value.c_str());
    char *path = strtok (str,"/");                                                                                                                                                          
    if (path == NULL)               
        throw;
    std::cout << path  << "\n";     

    path = strtok ( NULL,":");      
    if (path == NULL)               
        throw;     
    std::cout << path  << "\n";     

    path = strtok ( NULL,"/");      
    if (path == NULL)               
        throw;
    std::cout << path  << "\n";      

    path = strtok ( NULL, ":");      
    if (path == NULL)               
        throw;
    std::cout << path  << "\n";     

    path = strtok ( NULL, "/");      
    if (path == NULL)               
        throw;
    std::cout << path  << "\n";

    path = strtok ( NULL, ":");      
    if (path == NULL)               
        throw;
    std::cout << path  << "\n";

    path = strtok ( NULL, ":");      
    if (path == NULL)               
        throw;
    std::cout << path  << "\n";
    free(str);
    return 0;
    }
