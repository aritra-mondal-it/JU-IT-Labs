// Base class representing an Automobile
class Automobile {
    private String make;
    private String type;
    private double maxSpeed;
    private double price;
    private double mileage;
    private String registrationNumber;

    // Constructor for Automobile
    public Automobile(String make, String type, double maxSpeed, double price, double mileage, String registrationNumber) {
        this.make = make;
        this.type = type;
        this.maxSpeed = maxSpeed;
        this.price = price;
        this.mileage = mileage;
        this.registrationNumber = registrationNumber;
    }

    // Getter and Setter methods for Automobile attributes
    public String getMake() {
        return make;
    }

    public void setMake(String make) {
        this.make = make;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public double getMaxSpeed() {
        return maxSpeed;
    }

    public void setMaxSpeed(double maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getMileage() {
        return mileage;
    }

    public void setMileage(double mileage) {
        this.mileage = mileage;
    }

    public String getRegistrationNumber() {
        return registrationNumber;
    }

    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }

    // Method to display information of the automobile
    public void displayInfo() {
        System.out.println("Make: " + make);
        System.out.println("Type: " + type);
        System.out.println("Max Speed: " + maxSpeed + " km/h");
        System.out.println("Price: " + price + " USD");
        System.out.println("Mileage: " + mileage + " km/l");
        System.out.println("Registration Number: " + registrationNumber);
    }
}

// Subclass representing a Truck (inherits from Automobile)
class Truck extends Automobile {
    private double capacity; // in tons
    private String hoodType;
    private int noOfWheels;

    // Constructor for Truck
    public Truck(String make, String type, double maxSpeed, double price, double mileage, String registrationNumber, 
                 double capacity, String hoodType, int noOfWheels) {
        super(make, type, maxSpeed, price, mileage, registrationNumber);
        this.capacity = capacity;
        this.hoodType = hoodType;
        this.noOfWheels = noOfWheels;
    }

    // Getter and Setter methods for Truck specific attributes
    public double getCapacity() {
        return capacity;
    }

    public void setCapacity(double capacity) {
        this.capacity = capacity;
    }

    public String getHoodType() {
        return hoodType;
    }

    public void setHoodType(String hoodType) {
        this.hoodType = hoodType;
    }

    public int getNoOfWheels() {
        return noOfWheels;
    }

    public void setNoOfWheels(int noOfWheels) {
        this.noOfWheels = noOfWheels;
    }

    // Method to display information of the Truck
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Truck Capacity: " + capacity + " tons");
        System.out.println("Hood Type: " + hoodType);
        System.out.println("Number of Wheels: " + noOfWheels);
    }
}

// Subclass representing a Car (inherits from Automobile)
class Car extends Automobile {
    private int noOfDoors;
    private int seatingCapacity;

    // Constructor for Car
    public Car(String make, String type, double maxSpeed, double price, double mileage, String registrationNumber, 
               int noOfDoors, int seatingCapacity) {
        super(make, type, maxSpeed, price, mileage, registrationNumber);
        this.noOfDoors = noOfDoors;
        this.seatingCapacity = seatingCapacity;
    }

    // Getter and Setter methods for Car specific attributes
    public int getNoOfDoors() {
        return noOfDoors;
    }

    public void setNoOfDoors(int noOfDoors) {
        this.noOfDoors = noOfDoors;
    }

    public int getSeatingCapacity() {
        return seatingCapacity;
    }

    public void setSeatingCapacity(int seatingCapacity) {
        this.seatingCapacity = seatingCapacity;
    }

    // Method to display information of the Car
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Number of Doors: " + noOfDoors);
        System.out.println("Seating Capacity: " + seatingCapacity);
    }
}

// Main class to demonstrate the functionality
public class q13 {
    public static void main(String[] args) {
        // Creating a Truck object
        Truck truck1 = new Truck("Volvo", "Truck", 120, 50000, 8, "AB123CD", 15, "Flat", 18);
        
        // Creating a Car object
        Car car1 = new Car("Toyota", "Sedan", 180, 25000, 15, "XY987Z", 4, 5);

        // Display information about the Truck
        System.out.println("Truck Details:");
        truck1.displayInfo();
        System.out.println();

        // Display information about the Car
        System.out.println("Car Details:");
        car1.displayInfo();
    }
}

