import java.util.ArrayList;
import java.util.List;

// Abstract class Publication
abstract class Publication {
    private int noOfPages;
    private double price;
    private String publisherName;

    // Constructor
    public Publication(int noOfPages, double price, String publisherName) {
        this.noOfPages = noOfPages;
        this.price = price;
        this.publisherName = publisherName;
    }

    // Accessor and Mutator methods
    public int getNoOfPages() {
        return noOfPages;
    }

    public void setNoOfPages(int noOfPages) {
        this.noOfPages = noOfPages;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getPublisherName() {
        return publisherName;
    }

    public void setPublisherName(String publisherName) {
        this.publisherName = publisherName;
    }

    // Abstract method to be implemented by subclasses
    public abstract void printDetails();
}

// Subclass Book
class Book extends Publication {
    private String author;

    // Constructor
    public Book(int noOfPages, double price, String publisherName, String author) {
        super(noOfPages, price, publisherName);
        this.author = author;
    }

    // Accessor and Mutator for author
    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    @Override
    public void printDetails() {
        System.out.println("Book Details:");
        System.out.println("Author: " + author);
        System.out.println("No of Pages: " + getNoOfPages());
        System.out.println("Price: $" + getPrice());
        System.out.println("Publisher: " + getPublisherName());
        System.out.println();
    }
}

// Subclass Journal
class Journal extends Publication {
    private String issue;

    // Constructor
    public Journal(int noOfPages, double price, String publisherName, String issue) {
        super(noOfPages, price, publisherName);
        this.issue = issue;
    }

    // Accessor and Mutator for issue
    public String getIssue() {
        return issue;
    }

    public void setIssue(String issue) {
        this.issue = issue;
    }

    @Override
    public void printDetails() {
        System.out.println("Journal Details:");
        System.out.println("Issue: " + issue);
        System.out.println("No of Pages: " + getNoOfPages());
        System.out.println("Price: $" + getPrice());
        System.out.println("Publisher: " + getPublisherName());
        System.out.println();
    }
}

// Class Library
class Library {
    private List<Publication> publications;

    // Constructor
    public Library() {
        publications = new ArrayList<>();
    }

    // Add publication to the library
    public void addPublication(Publication publication) {
        publications.add(publication);
    }

    // Print details of all publications
    public void printAllPublications() {
        for (Publication publication : publications) {
            publication.printDetails();
        }
    }
}

// Main class
public class q7 {
    public static void main(String[] args) {
        // Create Library
        Library library = new Library();

        // Create Books
        Book book1 = new Book(300, 15.99, "Penguin Books", "Author A");
        Book book2 = new Book(400, 19.99, "HarperCollins", "Author B");
        Book book3 = new Book(250, 10.99, "Macmillan", "Author C");

        // Create Journals
        Journal journal1 = new Journal(50, 5.99, "Springer", "Issue 1");
        Journal journal2 = new Journal(60, 6.99, "Elsevier", "Issue 2");

        // Add books and journals to library
        library.addPublication(book1);
        library.addPublication(book2);
        library.addPublication(book3);
        library.addPublication(journal1);
        library.addPublication(journal2);

        // Print details of all publications
        library.printAllPublications();
    }
}


