/*
 * =====================================================================================
 *
 *       Filename:  copy_class.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28.12.2016 16:47:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
class Foo {
public:
  Foo(A* a, B* b): a(a), b(b) {}

  ~Foo() {
    delete a;
    delete b;
  }

  // Write the copy constructor for the class Foo. 
  // Ownership of a and b should be maintained by Foo.
  // Types A and B are copy-constructible.

private:
  A* a;
  B* b;
};


int main()
{

return 0;
}
