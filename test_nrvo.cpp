/*
 * =====================================================================================
 *
 *       Filename:  test_nrvo.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04.02.2016 16:01:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>

using namespace std;
 
 class foo {
     public:

           foo() { cout <<"foo::foo()\n"; }
                 foo( const foo& ){ cout << "foo::foo( const foo& )\n"; }
                       ~foo(){ cout << "foo::~foo()\n"; }
 };

 foo bar(){ foo local_foo; return local_foo; }
  
  int main()
  {
            foo f = bar();
  }
