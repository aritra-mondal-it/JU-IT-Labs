import java.util.concurrent.*;

public class q7{

    // Array of integers
    private static int[] array;
    // Element to be searched
    private static int e;
    // Shared variable to store the index of the element if found
    private static volatile int result = -1;

    public static void main(String[] args) throws InterruptedException {
        // Initialize the array and the element to search
        int n = 100;  // Example size of the array (size should be a multiple of 10)
        array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = i + 1;  // Array elements are from 1 to 100 (sorted)
        }

        // Element to search for
        e = 75;  // Example element to search

        // Number of threads: n/10
        int numThreads = n / 10;
        ExecutorService executor = Executors.newFixedThreadPool(numThreads);

        // Create and submit threads to perform parallel binary search
        for (int i = 0; i < numThreads; i++) {
            int start = i * (n / 10);
            int end = start + (n / 10) - 1;
            executor.submit(new BinarySearchTask(start, end, i + 1)); // Pass thread index (i + 1)
        }

        // Shutdown the executor service
        executor.shutdown();
        // Wait until all threads finish execution
        if (!executor.awaitTermination(1, TimeUnit.MINUTES)) {
            executor.shutdownNow();
        }

        // Print the result
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

        @Override
        public void run() {
            int left = start;
            int right = end;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                // If element is found, update result and print thread info
                if (array[mid] == e) {
                    result = mid;
                    System.out.println("Thread " + threadIndex + " found element " + e + " at index " + mid);
                    return;  // Found the element, no need to continue searching
                }
                // If element is smaller than mid, search the left half
                if (array[mid] > e) {
                    right = mid - 1;
                } else {
                    // If element is larger than mid, search the right half
                    left = mid + 1;
                }
            }
        }
    }
}
