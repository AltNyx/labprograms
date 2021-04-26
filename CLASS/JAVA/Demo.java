public class Demo {
    public static void main(String[] args) {
        int luckyNum = 1765;
        String myName = "Random";
        String fName = myName + luckyNum;
        System.out.println(fName); // Random1765

        // If else
        int marks = 61;
        if (marks > 60) {
            System.out.println("Pass");
        } else {
            System.out.println("Fail");
        }

        // Nested
        char grade = ' ';

        marks = 85;

        if (marks > 40) {
            System.out.println("Pass");
            if (marks >= 80)
                grade = 'A';
            else if (marks >= 70)
                grade = 'B';
            else
                grade = 'C';
        } else {
            System.out.println("Fail");
            grade = 'F';
        }

        System.out.println(grade);
    }
}