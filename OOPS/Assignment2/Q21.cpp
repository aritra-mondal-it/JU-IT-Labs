#include<iostream>
#include<algorithm>
using namespace std;
typedef struct account
{
  string name;
  long long int number;
int balance;

}acc;
void withdraw(acc *b)
{
int t;
   cout<<"which number account \n";
  cin>>t;
cout<<(*(b+t-1)).balance;
cout<<endl<<"enter amount to withdraw"<<endl;
int m;
cin>>m;
cout<<m<<"is withdrawn"<<endl;
(*(b+t-1)).balance= (*(b+t-1)).balance - m;
}
void deposit(acc* b)
{
  int t;
   cout<<"which number account \n";
  cin>>t;
cout<<(*(b+t-1)).balance;
cout<<endl<<"enter amount to deposit"<<endl;
int m;
cin>>m;
cout<<m<<"is deposited"<<endl;
(*(b+t-1)).balance= (*(b+t-1)).balance +m;
}
void interest(acc *b)
{
double r=0.4;
   int t;
   cout<<"which number account \n";
  cin>>t;
cout<<(*(b+t-1)).balance;
cout<<endl;
int m;
m=(*(b+t-1)).balance;
cout<<"interest for one year is"<<(m*r)/double (100) ;
int s= (m*r)/double(100);
m=m+s;
cout<<"new balance is"<<m<<endl;
}
void allinterest(acc *b)
{
  double  r=0.4;
    int t,w=0;
 for(t=0;t<10;t++)
{
int m;
m=(*(b+t-1)).balance;
int s= (m*r)/double(100);
w+=s;
}
cout<<"total interest is"<<w<<endl;
}
int main()
{
acc b[3];
int t;
for(t=0;t<3;t++)
{
      cout<<"enter name of holder,account number and balance respectively\n";
     cin>>b[t].name;
    cin>>b[t].number;
    cin>>b[t].balance;
}
int ch;
cout<<"1)withdraw,2).deposit,3).interest,4).all interest"<<endl;
while(1)
{
   cout<<"enter choice\n";
cin>>ch;
    switch(ch)
   {
      case 1: withdraw(&b[0]);
            break;
      case 2: deposit(&b[0]);
            break;
       case 3: interest(&b[0]);
             break;
      case 4: allinterest(&b[0]);
             break;
        default: cout<<"enter valid choice\n";
               break;
   }
}
return 0;
}

