#include <iostream>

class Parent
    {
    public:
        Parent(int i, std::string test = ""); 
    };

Parent::Parent(int i, std::string test)
    {
    std::cout << i << test << "\n";
    };

int main()
    {
    Parent* obj = new  Parent(2);
    Parent* obj1 = new  Parent(1, "test");
    }
