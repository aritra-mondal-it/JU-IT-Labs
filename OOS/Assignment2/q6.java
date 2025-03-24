import java.util.concurrent.*;

public class q6 {

    // Shared variables
    private static int[] array;
    private static int e;  // Element to be searched
    private static volatile int result = -1; // Result index to store the found index

    public static void main(String[] args) throws InterruptedException {
        // Example initialization (size n = 100, n mod 10 = 0)
        int n = 100; // Size of the array (must be divisible by 10)
        array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = i + 1;  // Array is sorted from 1 to 100
        }

        e = 75;  // Element to search for

        // Create n/10 threads
        int numThreads = n / 10;
        ExecutorService executor = Executors.newFixedThreadPool(numThreads);

        // Create and submit threads to perform parallel binary search
        for (int i = 0; i < numThreads; i++) {
            int start = i * (n / 10);   // Starting index for this thread
            int end = start + (n / 10) - 1;  // Ending index for this thread
            executor.submit(new BinarySearchTask(start, end, i + 1));  // Pass the thread index (i + 1)
        }

        // Shutdown the executor and wait for all threads to complete
        executor.shutdown();
        if (!executor.awaitTermination(1, TimeUnit.MINUTES)) {
            executor.shutdownNow();
        }

        // If result is found, print it; otherwise, indicate it's not found
        if (result != -1) {
            System.out.println("Element " + e + " found at index " + result);
        } else {
            System.out.println("Element " + e + " not found.");
        }
    }

    // Binary Search Task implemented as a Runnable
    static class BinarySearchTask implements Runnable {
        private int start;
        private int end;
        private int threadIndex;

        public BinarySearchTask(int start, int end, int threadIndex) {
            this.start = start;
            this.end = end;
            this.threadIndex = threadIndex;
        }
        public void run() {
            int left = start;
            int right = end;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                // If the element is found, update the result and print thread info
                if (array[mid] == e) {
                    result = mid;
                    System.out.println("Thread " + threadIndex + " found element " + e + " at index " + mid);
                    return; // Exit as we have found the element
                }
                // Perform binary search: update left or right based on comparison
                if (array[mid] > e) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
    }
}
