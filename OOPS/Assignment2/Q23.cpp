#include<iostream>
using namespace std;
class complex
{
double a;
double b;
public:
void setReal(double x)
{
 a=x;
}
void setImg(double x)
{
b=x;
}
double getReal()
{
return a;
}
double getImg()
{
return b;
}
void display( complex w,complex k)
{
  a=w.getReal()+ k.getReal();
  b=w.getImg() + k.getImg();
  cout<<"the summation is "<< a<<" + "<<b<<"i"<<endl;
}
};
int main()
{
  complex o1,o2,o3;
  o1.setReal(5);
 o1.setImg(6);
  cout<<"the first complex number is "<<o1.getReal()<<"+i"<<o1.getImg()<<endl;
  o2.setReal(7);
 o2.setImg(4);
  cout<<"the second complex number is "<<o2.getReal()<<"+i"<<o2.getImg()<<endl;
 o3.display(o1,o2);
return 0;
}
