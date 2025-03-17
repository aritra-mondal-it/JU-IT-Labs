#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int t,j, m=s.length ();
   int p=((m+1)/2);
   for(t=0;t<((m+1)/2);t++)
    {
        for(j=1;j<=t;j++)
        cout<<" ";
        cout<<s[t];
        if(t!=p-1)
        {
        for(j=1;j<=m-(2*t)-2;j++)
        cout<<" ";
        cout<<s[m-1-t]<<endl;
        }
    }
    cout<<endl;
    for(t=p-2;t>=0;t--)
    {
      for(j=1;j<=t;j++)
      cout<<" ";
      cout<<s[t];
      for(j=1;j<=m-(2*t)-2;j++)
      cout<<" ";
      cout<<s[m-1-t]<<endl;
    }
    return 0;
}
