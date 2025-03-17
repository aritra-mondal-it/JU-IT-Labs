// Class for the child thread using Runnable
class ChildThread implements Runnable {
	public void run() 
	{
        	System.out.println("In child thread");
    	}
}

public class q1 {
    	public static void main(String[] args) 
	{
        	Thread childThread = new Thread(new ChildThread());
	        childThread.start();
	        System.out.println("In main thread");
        	try
		{
            		childThread.join();
        	} 
		catch (InterruptedException e) 
		{
            		System.out.println("Main thread interrupted.");
        	}
    	}
}

