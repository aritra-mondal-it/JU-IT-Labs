import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Book Class
class Book {
    private String author;
    private String title;
    private String publisher;
    private double cost;
    private int stock;

    // Constructor
    public Book(String author, String title, String publisher, double cost, int stock) {
        this.author = author;
        this.title = title;
        this.publisher = publisher;
        this.cost = cost;
        this.stock = stock;
    }

    // Getters
    public String getAuthor() {
        return author;
    }

    public String getTitle() {
        return title;
    }

    public String getPublisher() {
        return publisher;
    }

    public double getCost() {
        return cost;
    }

    public int getStock() {
        return stock;
    }

    // Setters
    public void setStock(int stock) {
        this.stock = stock;
    }

    // Method to check if a book matches by title and author
    public boolean matches(String searchTitle, String searchAuthor) {
        return this.title.equalsIgnoreCase(searchTitle) && this.author.equalsIgnoreCase(searchAuthor);
    }
}

// Main Class to Manage Bookshop
public class q10 {
    private List<Book> inventory;

    // Constructor to initialize inventory
    public q10() {
        this.inventory = new ArrayList<>();
    }

    // Method to add a book to the inventory
    public void addBook(Book book) {
        inventory.add(book);
    }

    // Method to search for a book by title and author
    public Book searchBook(String title, String author) {
        for (Book book : inventory) {
            if (book.matches(title, author)) {
                return book;
            }
        }
        return null; // Book not found
    }

    // Main method to demonstrate the functionality
    public static void main(String[] args) {
        q10 bookshop = new q10();

        // Adding sample books to the inventory
        bookshop.addBook(new Book("J.K. Rowling", "Harry Potter", "Bloomsbury", 500, 10));
        bookshop.addBook(new Book("J.R.R. Tolkien", "The Lord of the Rings", "Allen & Unwin", 700, 5));
        bookshop.addBook(new Book("George Orwell", "1984", "Secker & Warburg", 300, 8));

        Scanner scanner = new Scanner(System.in);

        // Accepting user input for book search
        System.out.print("Enter the title of the book: ");
        String title = scanner.nextLine();
        System.out.print("Enter the author of the book: ");
        String author = scanner.nextLine();

        Book book = bookshop.searchBook(title, author);

        if (book == null) {
            System.out.println("Book not available in the inventory.");
        } else {
            System.out.println("\nBook Details:");
            System.out.println("Title: " + book.getTitle());
            System.out.println("Author: " + book.getAuthor());
            System.out.println("Publisher: " + book.getPublisher());
            System.out.println("Cost: " + book.getCost());
            System.out.println("Stock Available: " + book.getStock());

            // Asking for number of copies required
            System.out.print("\nEnter the number of copies required: ");
            int copies = scanner.nextInt();

            if (copies <= book.getStock()) {
                double totalCost = copies * book.getCost();
                book.setStock(book.getStock() - copies); // Update stock
                System.out.println("Total cost: " + totalCost);
                System.out.println("Stock updated. Remaining stock: " + book.getStock());
            } else {
                System.out.println("Required copies not in stock.");
            }
        }

        scanner.close();
    }
}
