#include <iostream>


int main()
    {
    int m_timestamp = 1412228917;
    //int m_timestamp = 1412228917;
    char timebuff[] = "0000-00-00 00:00:00";
    struct tm * timestamp = localtime((const time_t*)&m_timestamp );
    strftime(timebuff, sizeof(timebuff), "%F %X", timestamp);
   
    std::string t;

    //std::cout << "t" << t.c_str() << "\n";
    std::cout << timebuff << "\n";
    return 0;
    }
