/*
 * =====================================================================================
 *
 *       Filename:  test_variatic_tempalates.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20.07.2015 15:52:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <string>
#include <utility>
#include <tuple>
 #include <typeinfo>

template <class... Args>
struct Foo;
 
template <>
struct Foo<>
{
 
};
 
template <class T, class... Args>
struct Foo<T, Args...>: private Foo<Args...>
{
    Foo(T&& t, Args&&... args): Foo<Args...>(std::forward<Args>(args)...)
    {
        std::cout << t << std::endl;
    }
};

struct test
    {

    };

template<typename T, typename U>
struct is_same
{
    static const bool value = false;
};

template<typename T>
struct is_same<T, T>
{
    static const bool value = true;
};

template<typename T, typename U>
constexpr bool eqTypes() { return is_same<T, U>::value; }

struct YEAR 
    { 
    int data = 0; 
    YEAR(int d):data(d){}; 
    };

    std::ostream& operator<<(std::ostream &os, const YEAR& m) 
        { 
        return os << m.data;
        }

/*

template<class TT>
class base_vasy
    {

    public:
     base_vasy()
        {
        std::cout << "class base_vasy simple constructor " <<  "\n";
        }
    void print()
        {
        std::cout << " BASE VASY PRINT" << "\n";
        }
    template <class U>           
    base_vasy<TT>& operator=(const base_vasy<U>& r)
    {              
    time = r.time;    
    return *this;
    }

    };
*/
// ===================

template <class... Args>
struct vasy;
 
template <>
class vasy<>//:public base_vasy<T>
{
    public:
     vasy()
        {
        std::cout << "class T simple constructor " <<  "\n";
        }
    vasy(int a)
        {
        std::cout << "class T int simple constructor " << a <<  "\n";
        }
int time;

/*template <class U>           
vasy<T>& operator=(const vasy<U>& r)
    {              
    time = r.time;    
    return *this;
    }
*/
};

enum dateType 
    {
    GMTIME,
    LOCALTIME
    };


    template <dateType T>
    struct date_traits {}; 

    template <>
    struct date_traits<GMTIME> 
        {   
        };  

    template <>
    struct date_traits<LOCALTIME> 
        {   
        };  



template<typename T, typename... ARGS>
class vasy<T, ARGS...> //: public base_vasy<T>
{
    public:
    std::tuple<ARGS...> args_;
    vasy()
        {
        std::cout << "simple constructor " <<  "\n";
        }
    vasy(int i)
        {
        std::cout << "constructor with int" <<  "\n";
        }
    vasy(T&& t, ARGS&&... args):
    args_(std::make_tuple(std::forward<ARGS>(args)...))
    {
        std::cout << "vasy count args " << sizeof...(args) << "\n";

    
        using null_type = typename std::tuple_element < 1, std::tuple<ARGS... >>::type;
        //if (typeid (null_type) == typeid(YEAR) )
        if (eqTypes<null_type , YEAR >()) 
            {
            std::cout << " YEAR IS "   << " == " << std::get<0>(args_) << "\n";

            }

        std::cout << " param " <<std::get<0>(args_) << " " << std::get<1>(args_) << " " << std::get<2>(args_) << "\n";
    }
   void print()
        {
        std::cout << " VASY PRINT" << "\n";
        }
};

int main()
{
    //Foo<int, double, std::string> f(42, 3.14159, "The Matrix has you");
    vasy<date_traits<LOCALTIME>, YEAR, MONTH> f = vasy< date_traits<LOCALTIME>, YEAR, MONTH> ( date_traits<LOCALTIME>(), 22,  11, 44);
    //f.print();

    vasy<date_traits<LOCALTIME>> f1 = vasy<date_traits<LOCALTIME>>();
    vasy<date_traits<GMTIME>> f2 = vasy<date_traits<GMTIME>>(10);
    //f = f1;
    /*
    f1.print();
    vasy<test> f2 = vasy<test>(100000);
    f2.print(); */
    return 0;
}
