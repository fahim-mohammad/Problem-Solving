import java.util.Scanner;

abstract class Calculator {
    abstract void calculate(int n);
}

class FactorialCalculator extends Calculator implements Runnable {
    int n;       
    int result = 1;

    public void run() {
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        System.out.println("Factorial of " + n + " = " + result);
    }

    void calculate(int n) {
        this.n = n; 
        Thread t = new Thread(this); 
        t.start(); 
    }
}


public class Main {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter an integer: ");
            int n = sc.nextInt();

            Calculator calc = new FactorialCalculator();
            calc.calculate(n);

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
