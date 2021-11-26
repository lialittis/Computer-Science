#include<iostream>

template <typename T>
struct S
{
    typedef void value;
};

template < >
struct S<double>
{
    typedef void type;
};

template <typename T>
struct S<T>::type foo(T t)
{
    std::cout<< "A";
};

template <typename T>
struct S<T>::value foo(T t)
{
    std::cout<<"B";
};

int main(){
    foo("hello");
    foo(3.14);
}