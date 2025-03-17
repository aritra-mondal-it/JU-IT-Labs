#include <iostream>
#include <math.h>
#define n 2
using namespace std;
class Devices
{
    int x,y,uid,ctr;
    public:
    Devices()
    {
        this->x=0;
        this->y=0;
        this->uid=0;
        this->ctr=0;
    }
    void input(int a,int b,int c,int d)
    {
        this->x=a;
        this->y=b;
        this->uid=c;
        this->ctr=d;
    }
    void Neighbour(Devices a,Devices b)
    {
        double d=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
        if(d<ctr)
            cout<<b.uid<<" ";
    }
    int getUID()
    {
        return this->uid;
    }
};
int main()
{
    Devices arr[10];
    
    for(int i = 0; i < n; i++)
    {
        int a,b,d;
        cout << "Enter co-ordinates of the " << i+1 << " device : ";
        cin >> a >> b;
        cout << "Enter transmission range of the " << i+1 << " device : ";
        cin >> d;
        arr[i].input(a,b,i+1,d);
    }
    for(int i = 0; i < n; i++)
    {
        cout << "Neighbours of " << arr[i].getUID() << " are : ";
        for(int j = 0; j < n; j++)
        {
            if(i!=j)
                arr[i].Neighbour(arr[i],arr[j]);
        }
        cout<<endl;
    }
}
