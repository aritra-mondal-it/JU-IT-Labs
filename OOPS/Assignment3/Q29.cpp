#include <iostream>
using namespace std;
class B1
{
        public:
        B1()
        {
                cout<<"B1 constructor"<<endl;
        }
        void show()
        {
                cout<<"Hi"<<endl;
        }
};
class B2
{
        public:
        B2()
        {
                cout<<"B2 constructor"<<endl;
        }
        void show()
        {
                cout<<"Hi2"<<endl;
        }
};
class C:public B1,public B2
{
        public:
        C()
        {
                cout<<"C constructor"<<endl;
        }
};
int main()
{
        C ob;
        ob.B1::show();
	ob.B2::show();
}

