import java.util.ArrayList;
import java.util.List;

// Base class Account
class Account {
    private String accountNumber;
    private String holderName;
    private double balance;

    // Constructor
    public Account(String accountNumber, String holderName, double balance) {
        this.accountNumber = accountNumber;
        this.holderName = holderName;
        this.balance = balance;
    }

    // Accessor and Mutator methods
    public String getAccountNumber() {
        return accountNumber;
    }

    public void setAccountNumber(String accountNumber) {
        this.accountNumber = accountNumber;
    }

    public String getHolderName() {
        return holderName;
    }

    public void setHolderName(String holderName) {
        this.holderName = holderName;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    // Print account details
    public void printDetails() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Holder Name: " + holderName);
        System.out.println("Balance: $" + balance);
    }
}

// SavingsAccount class extending Account
class SavingsAccount extends Account {
    private double interestRate;

    // Constructor
    public SavingsAccount(String accountNumber, String holderName, double balance, double interestRate) {
        super(accountNumber, holderName, balance);
        this.interestRate = interestRate;
    }

    // Accessor and Mutator for interestRate
    public double getInterestRate() {
        return interestRate;
    }

    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }

    // Method to calculate yearly interest
    public double calculateYearlyInterest() {
        return getBalance() * interestRate / 100;
    }

    @Override
    public void printDetails() {
        super.printDetails();
        System.out.println("Interest Rate: " + interestRate + "%");
    }
}

// CurrentAccount class extending Account
class CurrentAccount extends Account {
    // Constructor
    public CurrentAccount(String accountNumber, String holderName, double balance) {
        super(accountNumber, holderName, balance);
    }

    @Override
    public void printDetails() {
        super.printDetails();
    }
}

// Manager class
class Manager {
    private List<Account> accounts;

    // Constructor
    public Manager() {
        accounts = new ArrayList<>();
    }

    // Add account to the manager's list
    public void addAccount(Account account) {
        accounts.add(account);
    }

    // Print details of all accounts
    public void printAllAccounts() {
        for (Account account : accounts) {
            account.printDetails();
            System.out.println("-------------------");
        }
    }

    // Calculate and print interest for SavingsAccount
    public void calculateInterestForSavings() {
        for (Account account : accounts) {
            if (account instanceof SavingsAccount) {
                SavingsAccount savingsAccount = (SavingsAccount) account;
                double interest = savingsAccount.calculateYearlyInterest();
                System.out.println("Interest for Savings Account (" + savingsAccount.getAccountNumber() + "): $" + interest);
            }
        }
    }
}

// Main class
public class q8 {
    public static void main(String[] args) {
        // Create Manager instance
        Manager manager = new Manager();

        // Create SavingsAccount instances
        SavingsAccount savings1 = new SavingsAccount("SA123", "Alice", 5000, 5);
        SavingsAccount savings2 = new SavingsAccount("SA124", "Bob", 8000, 4);

        // Create CurrentAccount instances
        CurrentAccount current1 = new CurrentAccount("CA101", "Charlie", 10000);
        CurrentAccount current2 = new CurrentAccount("CA102", "Diana", 15000);
        CurrentAccount current3 = new CurrentAccount("CA103", "Eve", 20000);

        // Add accounts to manager
        manager.addAccount(savings1);
        manager.addAccount(savings2);
        manager.addAccount(current1);
        manager.addAccount(current2);
        manager.addAccount(current3);

        // Print details of all accounts
        System.out.println("Details of all accounts:");
        manager.printAllAccounts();

        // Calculate and print yearly interest for savings accounts
        System.out.println("Yearly Interest Calculation for Savings Accounts:");
        manager.calculateInterestForSavings();
    }
}

