#include <iostream>
#include <vector>

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
    //first
    //std::vector<int> m_old_container { 1, 2, 3, 4, 5, 6, 9, 10 } ;
    //std::vector<int> m_container { 2,  7, 9 } ;
    
    // second
    std::vector<int> m_old_container { 2, 7, 9 } ;
    std::vector<int> m_container { 1, 3, 4, 5, 6, 9, 10 } ;


    auto new_it  = m_container.begin();
    
    for ( auto old_it  = m_old_container.begin(); old_it != m_old_container.end(); ++old_it )
        {
        if (((*new_it) < (*old_it) || (*old_it) < (*new_it)) && ( (*old_it) == 9 ||  (*old_it) == 7) || (*old_it) == 2)
            {
            std::cout << " INSERT " << *(old_it) << "\n";
            m_container.emplace_back( *(old_it) );
            }

        for ( ; new_it != m_container.end(); ++new_it )
            {
            std::cout << " new_it " << *new_it  << " > old_it " << *old_it << " \n";
            if ( (*old_it) < (*new_it) )
                {
                std::cout << "BREAK " << "\n";
                break; 
                }        
            }        
          
        }

    std::cout << " new vector {  "  ;
    for ( auto&& i : m_container )
        {
        std::cout << " " << i ;
        }

        std::cout << " } \n "  ;
    }

