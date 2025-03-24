public class q5 {

    // Shared variable to store the final sum
    private static int finalSum = 0;

    public static void main(String[] args) {
        // Create two threads: one for odd numbers and one for even numbers
        Thread oddThread = new Thread(new OddNumberSum());
        Thread evenThread = new Thread(new EvenNumberSum());

        // Start both threads
        oddThread.start();
        evenThread.start();

        try {
            // Wait for both threads to finish
            oddThread.join();
            evenThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Print the final sum after both threads finish
        System.out.println("Final sum: " + finalSum);
    }

    // Runnable to calculate the sum of odd numbers (1, 3, 5, ..., 99)
    static class OddNumberSum implements Runnable {
        @Override
        public void run() {
            int sum = 0;
            for (int i = 1; i <= 99; i += 2) {
                sum += i;
            }
            // Synchronize access to the shared finalSum variable
            synchronized (q5.class) {
                finalSum += sum;
            }
        }
    }

    // Runnable to calculate the sum of even numbers (2, 4, 6, ..., 100)
    static class EvenNumberSum implements Runnable {
        @Override
        public void run() {
            int sum = 0;
            for (int i = 2; i <= 100; i += 2) {
                sum += i;
            }
            // Synchronize access to the shared finalSum variable
            synchronized (q5.class) {
                finalSum += sum;
            }
        }
    }
}
