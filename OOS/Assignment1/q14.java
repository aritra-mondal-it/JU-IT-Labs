// Define the Shape interface
interface Shape {
    double area();
    void draw();
    void rotate(double angle);
    void move(double x, double y);
}

// Implement the Circle class
class Circle implements Shape {
    private double radius;
    private double x;
    private double y;

    public Circle(double radius, double x, double y) {
        this.radius = radius;
        this.x = x;
        this.y = y;
    }

    @Override
    public double area() {
        return Math.PI * radius * radius;
    }

    @Override
    public void draw() {
        System.out.println("Drawing a Circle at (" + x + ", " + y + ") with radius " + radius);
    }

    @Override
    public void rotate(double angle) {
        System.out.println("Circle rotation does not affect its appearance.");
    }

    @Override
    public void move(double x, double y) {
        this.x += x;
        this.y += y;
        System.out.println("Circle moved to new position (" + this.x + ", " + this.y + ").");
    }

    @Override
    public String toString() {
        return "Circle{radius=" + radius + ", x=" + x + ", y=" + y + "}";
    }
}

// Implement the Rectangle class
class Rectangle implements Shape {
    private double width;
    private double height;
    private double x;
    private double y;

    public Rectangle(double width, double height, double x, double y) {
        this.width = width;
        this.height = height;
        this.x = x;
        this.y = y;
    }

    @Override
    public double area() {
        return width * height;
    }

    @Override
    public void draw() {
        System.out.println("Drawing a Rectangle at (" + x + ", " + y + ") with width " + width + " and height " + height);
    }

    @Override
    public void rotate(double angle) {
        System.out.println("Rectangle rotated by " + angle + " degrees.");
    }

    @Override
    public void move(double x, double y) {
        this.x += x;
        this.y += y;
        System.out.println("Rectangle moved to new position (" + this.x + ", " + this.y + ").");
    }

    @Override
    public String toString() {
        return "Rectangle{width=" + width + ", height=" + height + ", x=" + x + ", y=" + y + "}";
    }
}

// Main class to test the implementation
public class q14 {
    public static void main(String[] args) {
        // Create two circles
        Circle circle1 = new Circle(5, 0, 0);
        Circle circle2 = new Circle(3, 2, 2);

        // Create three rectangles
        Rectangle rectangle1 = new Rectangle(4, 6, 0, 0);
        Rectangle rectangle2 = new Rectangle(3, 8, 1, 1);
        Rectangle rectangle3 = new Rectangle(5, 7, 2, 3);

        // Print details before moving
        System.out.println("Before moving:");
        System.out.println(circle1);
        System.out.println(circle2);
        System.out.println(rectangle1);
        System.out.println(rectangle2);
        System.out.println(rectangle3);

        // Move the shapes
        circle1.move(3, 3);
        circle2.move(-1, -1);
        rectangle1.move(2, 3);
        rectangle2.move(-2, 2);
        rectangle3.move(1, -1);

        // Print details after moving
        System.out.println("\nAfter moving:");
        System.out.println(circle1);
        System.out.println(circle2);
        System.out.println(rectangle1);
        System.out.println(rectangle2);
        System.out.println(rectangle3);
    }
}

