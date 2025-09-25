import java.util.Scanner;

// Abstract Class
abstract class BankAccount {
    String accountHolder;
    double balance;

    BankAccount(String accountHolder, double balance) {
        this.accountHolder = accountHolder;
        this.balance = balance;
    }

    abstract void deposit(double amount) throws IllegalArgumentException;

    void displayBalance() {
        System.out.println("Account Holder: " + accountHolder);
        System.out.println("Balance: " + balance);
    }
}

// Interface
interface LoanEligibility {
    void checkEligibility() throws IllegalStateException;
}

// CustomerAccount Class
class CustomerAccount extends BankAccount implements LoanEligibility {

    CustomerAccount(String accountHolder, double balance) {
        super(accountHolder, balance);
    }

    @Override
    public void deposit(double amount) throws IllegalArgumentException {
        if (amount <= 0) {
            throw new IllegalArgumentException("Invalid deposit amount: must be greater than zero.");
        }
        balance += amount;
    }

    @Override
    public void checkEligibility() throws IllegalStateException {
        if (balance < 0) {
            throw new IllegalStateException("Balance cannot be negative for loan eligibility check.");
        }
        if (balance >= 5000) {
            System.out.println("Eligible for loan.");
        } else {
            System.out.println("Not eligible for loan.");
        }
    }
}

// Main Class
public class BankSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter account holder name: ");
            String name = sc.nextLine();

            System.out.print("Enter initial balance: ");
            double initialBalance = sc.nextDouble();

            CustomerAccount customer = new CustomerAccount(name, initialBalance);

            System.out.print("Enter deposit amount: ");
            double depositAmount = sc.nextDouble();

            try {
                customer.deposit(depositAmount);
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
                return;
            }

            customer.displayBalance();

            try {
                customer.checkEligibility();
            } catch (IllegalStateException e) {
                System.out.println(e.getMessage());
            }

        } catch (Exception e) {
            System.out.println("Invalid input. Please enter valid data.");
        } finally {
            sc.close();
        }
    }
}
