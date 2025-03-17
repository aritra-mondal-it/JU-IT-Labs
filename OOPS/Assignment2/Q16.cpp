#include <iostream>
#include <math.h>
using namespace std;
class Points
{
    int x,y,z;
    public:
    Points()
    {
        this->x=0;
        this->y=0;
        this->z=0;
    }
    Points(int a,int b,int c)
    {
        this->x=a;
        this->y=b;
        this->z=c;
    }
    void distance(Points a,Points b)
    {
        double d;
        d=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
        cout<<"The distance between the two points = "<<d;
    }
};
int main()
{
    Points p1;
    Points p2(1,2,3);
    p1.distance(p1,p2);
    return 0;
}
