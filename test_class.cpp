#include <iostream>

class Parent
    {
    public:
        int m_i;
        Parent() { std::cout << "parent() " << "\n"; };
        Parent(int i) : m_i(i) { std::cout << "parent(int i) " << "\n"; };
        virtual void replace_work()
            {
            std::cout << " parent::replace_work " << "i = " << m_i << "\n";
            }
        void work()
            {
            std::cout << " parent::work " << "i = " << m_i << "\n";
            replace_work();
            }
    };

class Child : public Parent
    {
    public:
        using Parent::replace_work;
        virtual void replace_work()
            {
            std::cout << " child::replace_work " << "\n";

            }

    };

int main()
    {
    Parent* obj = new  Child();
    obj->work();
        {
        Parent* obj = new Parent(10);
        obj->work();
        }
    }
