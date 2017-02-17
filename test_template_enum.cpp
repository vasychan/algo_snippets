#include <iostream>
enum  FirstLogic : int  
{
    A = 1
};

enum  SecondLogic : int  
{
    B = 1
};

template <typename _t> class MyTemplate
{
public:
    void print()
    {
        std::cout << "not using any specialisation" << std::endl;
    }
};

template <> class MyTemplate <FirstLogic>
{
public:
    void print()
    {
        std::cout << "MyEnum specialisation " << FirstLogic::A << std::endl;
    }
};

template <> class MyTemplate <SecondLogic>
{
public:
    void print()
    {
        std::cout << "MyEnum specialisation " << SecondLogic::B << std::endl;
    }
};

template<> class MyTemplate <int>
{
public:
    void print()
    {
        std::cout << "int specialisation" <<  std::endl;
    }
};

template <typename _t> void print(_t param)
{
    MyTemplate<_t> m;
    m.print();
}


int main()
{
    print(FirstLogic);
    print(SecondLogic);
    print(5);

    return 0;
}
