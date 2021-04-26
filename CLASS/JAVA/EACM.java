enum Subject {
    FS(4), ST, WT(4), AJJ(3), MAD(2);

    int credits; // Instance variable

    Subject() {
        this.credits = 0;
    }

    Subject(int credits) {
        this.credits = credits;
    }

    public int getCredits() {
        return this.credits;
    }
}


public class EACM {
    public static void main(String[] args) {
        for (Subject sub: Subject.values()) {
            System.out.println(sub + ": " + sub.getCredits());
        }

        int totalCredits = 0;
        for (Subject sub: Subject.values()) {
            totalCredits += sub.getCredits();
        }

        System.out.println("Total Credits: " + totalCredits);

        // Important methods
        // 1. ordinal() -> enum constant position in list (0 based idx)
        // 2. compareTo() -> compares the ordinal value of enum (-ve if lt, 0 if eq, +ve if gt)
        // 3. equals() -> compares for equality
        
        // Ordinal
        System.out.println("Ordinal Values");
        for (Subject sub: Subject.values()) {
            System.out.println(sub + ": " + sub.ordinal());
        }

        Subject sub1 = Subject.AJJ;
        Subject sub2 = Subject.MAD;
        System.out.println(sub1.ordinal()); // 3
        System.out.println(sub2.ordinal()); // 4
        System.out.println(sub1.compareTo(sub2)); // -1
        System.out.println(sub2.compareTo(sub1)); // 1
        System.out.println(sub1.compareTo(sub1)); // 0
        System.out.println(sub1.equals(sub2)); // false
        System.out.println(sub1 == sub2); // false
    }
}