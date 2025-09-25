// Custom Exception class
class MyException extends Exception {
    public MyException(String msg) {
        super(msg);
    }
}

// Class to check voter age
class VoterAge {
    void checkAge(int n) throws MyException {
        if (n < 18) {
            throw new MyException("Age is under 18. Not allowed");
        }
        System.out.println("Vote done");
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        try {
            VoterAge voter = new VoterAge();
            voter.checkAge(17); // test with age less than 18
        } catch (MyException e) { // catch the custom exception
            System.out.println("Exception Handled: " + e.getMessage());
        }
    }
}
