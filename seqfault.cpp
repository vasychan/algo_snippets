/*
 * =====================================================================================
 *
 *       Filename:  seqfault.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.10.2016 19:08:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

struct A {
      void Foo() {
              std::cout << "Hello\n";
                }
                  int i;
};

void Process1(A* a)
{
      a->Foo();
}

void Process2(A* a)
{
      std::cout << a->i;
}

void Process3(A& a)
{
      std::cout << a.i;
}

int main()
{
      A* a = NULL;
        
          Process1(a);
            Process2(a);
              Process3(*a);
                return 0;
}
