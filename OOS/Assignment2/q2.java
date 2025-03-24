public class q2 {

    // Shared object for synchronization
    private static final Object lock = new Object();
    // Initial number to print
    private static int number = 1;

    public static void main(String[] args) throws InterruptedException {
        // Create the EvenThread and OddThread
        Thread evenThread = new Thread(new EvenThread());
        Thread oddThread = new Thread(new OddThread());

        // Start the threads
        oddThread.start();
        evenThread.start();

        // Wait for threads to finish
        oddThread.join();
        evenThread.join();
    }

    // Odd thread will print odd numbers
    static class OddThread implements Runnable {
        @Override
        public void run() {
            // Print odd numbers up to 7
            while (number <= 8) {
                synchronized (lock) {
                    if (number % 2 != 0) {
                        System.out.print(number + " ");
                        number++;  // Increment the number for next thread
                        lock.notify();  // Notify the even thread to print the next number
                    }
                    try {
                        if (number <= 8) {
                            lock.wait();  // Wait for the even thread to print
                        }
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    // Even thread will print even numbers
    static class EvenThread implements Runnable {
        @Override
        public void run() {
            // Print even numbers up to 8
            while (number <= 8) {
                synchronized (lock) {
                    if (number % 2 == 0) {
                        System.out.print(number + " ");
                        number++;  // Increment the number for next thread
                        lock.notify();  // Notify the odd thread to print the next number
                    }
                    try {
                        if (number <= 8) {
                            lock.wait();  // Wait for the odd thread to print
                        }
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }
}
