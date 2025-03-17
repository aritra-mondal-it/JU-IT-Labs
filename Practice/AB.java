import animal.Animal;
class AB implements Animal{
	public void eat()
	{
		System.out.println("Animal eats");
	}
	public void travel()
	{
		System.out.println("Animal travels");
	}
	public static void main(String args[])
	{
		AB ob=new AB();
		ob.eat();
		ob.travel();
	}
}
