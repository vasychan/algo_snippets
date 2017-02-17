/*
 * =====================================================================================
 *
 *       Filename:  test_owerloaded_bind.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02.06.2016 16:58:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <memory>

struct base {
  virtual void foo() { std::cout << "base\n"; }
  virtual ~base() {}
};

struct derived:base {
  void foo() override final { std::cout << "derived\n"; }
};

int main() {
  std::unique_ptr<base> der(new derived() );
  base* bas = new derived();

  auto func = std::bind(&base::foo, bas);
  func();
  //void (base::*mem_ptr)() = &base::foo;
  //std::unique_ptr<base> d( new derived() );
  //base* b = d.get();
  //(b->*mem_ptr)();
}
