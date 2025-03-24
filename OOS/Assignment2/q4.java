import java.io.*;
import java.util.*;

class SharedData {
    private List<Integer> buffer = new ArrayList<>();
    private int sum = 0;
    private final int BUFFER_LIMIT = 10;  // Buffer size limit for the producer-consumer model
    
    // Add data to the buffer
    public synchronized void produce(int value) throws InterruptedException {
        while (buffer.size() == BUFFER_LIMIT) {
            wait();  // Wait until there is space in the buffer
        }
        buffer.add(value);
        System.out.println("Produced: " + value);
        notifyAll();  // Notify the consumer that new data is available
    }
    
    // Consume data from the buffer and add to the sum
    public synchronized void consume() throws InterruptedException {
        while (buffer.isEmpty()) {
            wait();  // Wait until there is something to consume
        }
        int value = buffer.remove(0);  // Consume the first element
        sum += value;
        System.out.println("Consumed: " + value);
        notifyAll();  // Notify the producer that there is space in the buffer
    }
    
    // Return the current sum
    public synchronized int getSum() {
        return sum;
    }
}

class Producer implements Runnable {
    private SharedData sharedData;
    private String fileName;

    public Producer(SharedData sharedData, String fileName) {
        this.sharedData = sharedData;
        this.fileName = fileName;
    }

    public void run() {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                int num = Integer.parseInt(line.trim());
                sharedData.produce(num);  // Add the number to the buffer
            }
            // Signal the consumer thread to stop (by adding a sentinel value to indicate end of input)
            sharedData.produce(-1);  // End signal for the consumer
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Consumer implements Runnable {
    private SharedData sharedData;

    public Consumer(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    @Override
    public void run() {
        try {
            while (true) {
                sharedData.consume();  // Consume data from the buffer and add it to the sum
                // If the consumer gets the sentinel value, stop consuming
                if (sharedData.getSum() == -1) {
                    break;
                }
            }
            System.out.println("Total sum: " + sharedData.getSum());
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class q4 {
    public static void main(String[] args) {
        String fileName = "numbers.txt";  // Path to the file containing integers
        SharedData sharedData = new SharedData();

        // Create producer and consumer threads
        Thread producerThread = new Thread(new Producer(sharedData, fileName));
        Thread consumerThread = new Thread(new Consumer(sharedData));

        // Start threads
        producerThread.start();
        consumerThread.start();
    }
}
