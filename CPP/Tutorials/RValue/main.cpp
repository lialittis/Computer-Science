#include <iostream>
#include <vector>

using namespace std;

/* Examples of two reference functions */
void fn(int &ref)
{
	cout <<"Normal.."<<endl;
}

void fn(int &&ref)
{
	cout <<"RVAL ref.."<<endl;
}


struct A {
	int *ptr; // value member
	A() { // constructor
		cout <<"Cons.."<<endl;
		ptr = new int; 
	}

	A(const A & a1) { // copy constructor
		cout <<"Copy Cons.."<<endl;
		this->ptr = new int;
	}

	~A() {
		cout <<"Decons.."<<endl;
		delete ptr;
	} // deconstructor

};

int main()
{
	/* Example1 */
	int i = 10;
	int &j = i; 
	// j is just a reference to i, they share the same address,
	// j doesn't have a storage for itself
	
	/* Example2 */
	fn(i);
	fn(100);
	
	/* Example3 */
	vector<A> v1;
	v1.push_back(A());


	return 0;
}
