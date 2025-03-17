class room{

	int height;
	int width;
	int breadth;
	room()
	{
		this(5,6,7);
	}
	room(int h, int w, int b)
	{
		height=h;
		width=w;
		breadth=b;
	}
	int volume()
	{
		return height*width*breadth;
	}
}
class RoomDemo{
public static void main(String[] args)
{
	room r1=new room();
	room r2=new room(10,11,12);
	System.out.println("Volume = "+r1.volume());
	System.out.println("Volume = "+r2.volume());
}
}
