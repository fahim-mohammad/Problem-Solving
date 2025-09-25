
class MyException extends Exception {
    public MyException(String msg) {
        super(msg);
    }
}

class VoterAge {
    void checkAge(int n) throws MyException {
        if (n < 18) {
            throw new MyException("Age is under 18. Not allowed");
        }
        System.out.println("Vote done");
    }
}

public class Main {
    public static void main(String[] args) {
        try {
            VoterAge voter = new VoterAge();
            voter.checkAge(17); 
        } catch (MyException e) {
            System.out.println("Exception Handled: " + e.getMessage());
        }
    }
}
