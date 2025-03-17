#include<iostream>
#include<vector>
using namespace std;

class Vectors
{
	int n;
	vector<int> v;
	public:
	Vectors()
	{
		this->n=0;
	}
	Vectors(int x)
	{
		this->n=x;
	}
	void input()
	{
		cout<<"Enter the elements of the vector : ";
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
	}
	void addition(Vectors a,Vectors b)
	{
		cout<<"Addition of 2 vectors :";
		for(int i=0;i<a.n;i++)
			cout<<a.v[i]+b.v[i]<<'\t';;
		cout<<endl;
	}
	void subtraction(Vectors a,Vectors b)
	{
		cout<<"Subtraction of 2 vectors :";
		for(int i=0;i<a.n;i++)
			cout<<a.v[i]-b.v[i]<<'\t';
		cout<<endl;
	}
	int compare(Vectors a,Vectors b)
	{
		for(int i=0;i<a.n;i++)
		{
			if(a.v[i] > b.v[i])
				return 1;
			else if (a.v[i] < b.v[i])
				return -1;
		}
		return 0;
	}
};
int main()
{
	int n;	
	cout<<"Enter the size of the vector = ";
	cin>>n;	
	Vectors x(n);
	x.input();
	Vectors y(n);
	y.input();
	x.addition(x,y);
	x.subtraction(x,y);
	if (x.compare(x,y) == 1)
		cout<<"First one is greater"<<endl;
	else if(x.compare(x,y) == -1)
		cout<<"Second one is greater"<<endl;
	else
		cout<<"Both are equal"<<endl;
}
