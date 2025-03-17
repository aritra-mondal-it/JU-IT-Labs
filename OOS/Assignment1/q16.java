// Define the Fruit interface
interface Fruit {
    boolean hasAPeel();
}

// Define the Vegetable interface
interface Vegetable {
    boolean hasARoot();
}

// Implement the Tomato class
class Tomato implements Fruit, Vegetable {

    @Override
    public boolean hasAPeel() {
        return true; // Tomatoes have a peel
    }

    @Override
    public boolean hasARoot() {
        return false; // Tomatoes do not have a root, as they are fruits of a plant
    }

    @Override
    public String toString() {
        return "Tomato { hasAPeel: " + hasAPeel() + ", hasARoot: " + hasARoot() + " }";
    }
}

// Main class to test the implementation
public class q16 {
    public static void main(String[] args) {
        // Instantiate a Tomato object
        Tomato tomato = new Tomato();

        // Print details of the Tomato object
        System.out.println(tomato);
    }
}

