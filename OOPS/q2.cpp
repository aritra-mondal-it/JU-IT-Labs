#include<iostream>
using namespace std;
class Employee
{
	int basic_sal;
	void get_sal(int b)
	{
		basic_sal=b;
	}
	public:
	void cal_sal(int b)
	{
  		get_sal(b);
	}

};
class Manager: public Employee
{
	int basic_sal;
	public:
	void cal_sal(int b)
	{
		basic_sal=b;
		basic_sal=basic_sal+((basic_sal*40)/100);
	}
	int get()
	{
		return basic_sal;
	}
};
class Clerk:public Employee
{
	int basic_sal;
	public:
	void cal_sal(int b)
	{
		basic_sal=b;
		basic_sal=basic_sal+((basic_sal*30)/100);
	}
	int get()	
	{
		return basic_sal;
	}
};
int main()
{
	Manager ob[2];
	Clerk ob1[2];
	for(int i=0;i<2;i++)
	{
		ob[i].cal_sal(100);
		ob1[i].cal_sal(50);
	}
	int sum=0;
 	for(int j=0;j<2;j++)
	{
		sum+=ob[j].get();
		sum+=ob1[j].get();
	}
	cout<<"The total expenditure = "<<sum<<endl;
	return 0;
}

