#include <iostream>


struct Base
{
    int a = 1;
};

void a (const  int && t )
    {
    std::cout << " rvalue " << "\n";
    }
void a (const int & t )
    {
    std::cout << " lvalue " << "\n";
    }
int main()
    {
    auto&& rval = Base();
    auto&& t = 1000;


    std::cout << rval.a <<  " " << t << "\n";
    std::cout << "test rvalue/lvalue \n";
    int bb = 100;

    a(std::move(bb));
    a(bb);
    return 0;
    }
