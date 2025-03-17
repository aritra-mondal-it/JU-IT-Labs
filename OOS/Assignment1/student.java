class student{
	String name;
	int marks1,marks2,marks3;
	student(String n, int m1, int m2, int m3)
	{
		name=n;
		marks1=m1;
		marks2=m2;
		marks3=m3;
	}
	int total_avg()
	{
		return(marks1+marks2+marks3)/3;
	}
	void show()
	{
		System.out.println("Students Name = "+name);
		System.out.println("Avergae marks = "+total_avg());
	}
}
class q2{
public static void main(String args[]){
	student ob=new student("Aritra",90,91,92);
	ob.show();
}
}
