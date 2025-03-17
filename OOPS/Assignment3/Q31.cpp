#include<iostream>
using namespace std;
class person{
string name;
int age;
int height;
public:
void get(){
cout<<"enter name,age and height\n";
cin>>name;
cin>>age;
cin>>height;
}
virtual void printDetails(){
cout<<"age is "<<age<<" name is "<<name<<" height is "<<height<<endl;
}
};
class student:public person{
int roll;
string admission;
public:
void set(){
cout<<"enter roll and admission date\n";
cin>>roll;
cin>>admission;
}
void printDetails(){
person::printDetails();
cout<<"admission date is  "<<admission<<"roll is "<<roll<<endl;
}
};
int main(){
person p1,p2;
student s1,s2;
p1.get();
p1.printDetails();
s1.get();
s1.set();
s2.set();
s2.get();
person * pon[2];
pon[0]=&s1;
pon[1]=&s2;
for(int t=0;t<2;t++){
pon[t]->printDetails();
}
return 0;
}
