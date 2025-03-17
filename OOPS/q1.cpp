#include <iostream>
using namespace std;
class Number
{
	int a,b;
	public:
	Number(int ,int);
	friend void swap(Number&,Number&);
	void show();
};
Number::Number(int x,int y)
{
	a=x;
	b=y;
}
void swap(Number &oba, Number &obb)                
{
	int c;
	c=oba.a;
	oba.a=obb.a;
	obb.a=c;
	int d;
	d=oba.b;
	oba.b=obb.b;
	obb.b=d;
}
void Number::show()
{
	cout<<"Value of a="<<a<<"\t";
	cout<<"Value of b="<<b<<endl;
}
int main()
{
	Number oba(10,20);
	Number obb(30,40);
	oba.show();
	obb.show();
	swap(oba,obb);
	cout<<"After swapping:"<<endl;
	oba.show();
	obb.show();
	return 0;
}

