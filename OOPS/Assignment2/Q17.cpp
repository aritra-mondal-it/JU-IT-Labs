#include <iostream>
#include <math.h>
using namespace std;
class Rectangle
{
    int l,b;
    public:
    Rectangle()
    {
        this->l=0;
        this->b=0;
    }
    Rectangle(int a,int b)
    {
        this->l=a;
        this->b=b;
    }
    void area()
    {
        int area;
        area=l*b;
        cout<<"The area of the rectangle is = "<<area<<endl;
    }
};
int main()
{
    Rectangle R1(1,2);
    Rectangle R2(3,4);
    Rectangle R3(5,6);
    Rectangle R4(7,8);
    R1.area();
    R2.area();
    R3.area();
    R4.area();
}