#include <iostream>

using namespace std;

int main()
{
	// lvalues
	int i = 42; 
	i = 43; // ok, i is a lvalue
	int *p = &i; // ok, i is a lvalue
	int &foo(); // a foo function, return int & (int value reference)
	foo() = 42; // ok, foo() is a lvalue
	int *p1 = &foo(); // ok, foo() is a lvalue

	// rvalues
	int foobar();
	int j = 0;
	j = foobar(); // ok, foobar() is an rvalue
	// int* p2 = &foobar(); // error, cannot take the address of an rvalue
	j = 42; // ok, 42 is an rvalue 
	cout<<j<<endl;
	return 0;
}
