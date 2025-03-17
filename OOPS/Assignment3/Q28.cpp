#include <iostream>
using namespace std;
class B
{
	public:
	B()
	{
		cout<<"B constructor"<<endl;
	}
	void show()
	{
		cout<<"Hi"<<endl;
	}
};
class C:public B
{
	public:
	C()
	{
		cout<<"C constructor"<<endl;
	}
};
int main()
{
	C ob;
	ob.B::show();
}
