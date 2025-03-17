#include<iostream>
#include<algorithm>
using namespace std;
class stack
{
 int *buffer;
 int top=-1;
 public:
	int size;
	void create()
	{
		int  *buffer=new int [size];
	}
 void push()
 {
	if (top == size -1)
		cout<<"stack is full"<<endl;
	else
	{
		int  x;
		cout<<"Enter the elements"<<endl;
		cin>>x;
		top+=1;
		buffer[top]=x;
	}
}
 void pop()
 {
	if(top==-1)
		cout<<"stack is empty"<<endl;
	else
	{
		top=top-1;
		int  k=buffer[top+1];
		int  *a=&buffer[top+1];
		cout<<buffer[top]<"\t";
	}
}
 void disp()
 {
  for(int t=0;t<=top;t++)
	cout<<buffer[t]<<"\t";
 cout<<endl;
 }
 
};
int main()
{
 stack y;
 cout<<"1).create2).push3).pop4).display"<<endl;
 while(1)
 {
	int g;
	cout<<"Enter choice"<<endl;
	cin>>g;
	switch(g)
	{
		case 1:
		 cout<<"Enter size"<<endl;
		int q;
		cin>>q;
		y.size=q;
		y.create();
		break;
		case 2:
		y.push();
		break;
		case 3:
		y.pop();
		break;
		case 4:
		y.disp();
		break;
		default:
		return 0;
	}
 }
}

