#include<iostream>
#include<algorithm>
using namespace std;
class IntArray
{
 int a[200],t;
 public:
 IntArray()
 {
    cout<<"enter number of element\n";
    cin>>t;
    cout<<"enter elements\n";
    for(int j=0;j<t;j++)
    cin>>a[j];
 }
 IntArray(int x)
 {
 }
 void display ()
 {
    for(int j=0;j<t;j++)
    cout<<a[j]<<"\t";
 }
  void sortarr()
  {
   sort(a, a+t);
  }
  void rev()
  {
    int b[200],s=-1,j;
    for(j=t-1;j>=0;j--)
    b[++s]=a[j];
    for(j=0;j<t;j++)
    a[j]=b[j];
  }
  ~IntArray()
  {
  }
  IntArray(IntArray &on)
  {
    t=on.t;
   for(int j=0;j<t;j++)
   a[j]=on.a[j];
  }
  IntArray( IntArray &d,IntArray &k)
  {
       int w= (d.t + k.t);
       int s=-1;
       IntArray h(0),e(0);
       t=w;
         if(d.t>=k.t)
         {
         h=d;
         e=k;
         }
         else
         {
           h=k;
           e=d;
         }
         for(int j=0;j<h.t;j++)
         a[j]=h.a[j];
         for(int j=h.t;j<w;j++)
         a[j]=e.a[++s];
  }
};
int main()
{
    IntArray p;
    IntArray q(p);
    p.display();
    cout<<endl;
    q.display();
    cout<<endl;
    q.rev();
    p.display();
    cout<<endl<<"after reverse it is \n";
    q.display();
    return 0;
}