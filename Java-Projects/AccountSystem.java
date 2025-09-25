abstract class Account {
    double balance;

    public Account(double balance) {
        this.balance = balance;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) {
        balance -= amount;
    }

    abstract void calculateInterest();
}

class SavingsAccount extends Account {
    double interestRate = 0.05;

    public SavingsAccount(double balance) {
        super(balance);
    }

    @Override
    void calculateInterest() {
        double interest = balance * interestRate;
        System.out.println("Interest: " + interest);
    }
}

class CurrentAccount extends Account {

    public CurrentAccount(double balance) {
        super(balance);
    }

    @Override
    void calculateInterest() {
        System.out.println("No interest for current account.");
    }
}

public class Main {
    public static void main(String[] args) {
        SavingsAccount sa = new SavingsAccount(1000);
        CurrentAccount ca = new CurrentAccount(2000);

        sa.deposit(500);
        sa.calculateInterest();

        ca.withdraw(300);
        ca.calculateInterest();
    }
}
