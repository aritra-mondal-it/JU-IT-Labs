class q3 {
    private static double result = 1.0;  // To store the result
    private static int denominator = 1;  // To store the current denominator (factorial value)
    private static final int N = 10;     // Number of terms in the series

    public static void main(String[] args) {
        // Create two threads: t1 to generate denominators and t2 to compute the terms and sum them
        Thread t1 = new Thread(new DenominatorGenerator());
        Thread t2 = new Thread(new TermAdder());

        // Start the threads
        t1.start();
        t2.start();

        try {
            // Wait for both threads to finish
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Print the result of the series
        System.out.println("The sum of the series is: " + result);
    }

    // Thread to generate factorial denominators
    static class DenominatorGenerator implements Runnable {
        public void run() {
            for (int i = 1; i <= N; i++) {
                synchronized (q3.class) {
                    // Update the denominator for each term
                    denominator *= i;
                    q3.class.notify();
                    try {
                        if (i < N) {
                            q3.class.wait();
                        }
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    // Thread to compute and add the terms of the series
    static class TermAdder implements Runnable {
        public void run() {
            for (int i = 1; i <= N; i++) {
                synchronized (q3.class) {
                    // Add the current term (1/denominator) to the result
                    result += 1.0 / denominator;
                   q3.class.notify();
                    try {
                        if (i < N) {
                            q3.class.wait();
                        }
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }
}
