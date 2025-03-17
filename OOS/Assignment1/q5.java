class Complex{
int real,img;
Complex()
{
  real=0;
  img=0;
}
Complex(int setimg)
{
  real=0;
  img=setimg;
}
Complex(int setreal,int im)
{
 real=setreal;
 img=im;
}
 void add(Complex ob2)
{
  int s=real+ob2.real;
  int g=img+ ob2.img;
System.out.println(s+" + i"+g);
}
 void mul(Complex ob2){
    int sa=(real)*(ob2.real)-(img)*(ob2.img);
   int ga= (real)*(ob2.img)+(img)*(ob2.real);
System.out.println(sa+" + i"+ga);
}
}
class q5{

public static void main(String args[]){
 Complex num1=new Complex(3,2);
Complex num2=new Complex(4,-2);
num1.add(num2);
num1.mul(num2);
}
}

