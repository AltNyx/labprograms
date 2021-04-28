public class EnumMethods {
    enum Subject { FS, ST, WT, AJJ, MAD }
    enum Elective { AJJ, DM }

    public static void main(String[] args) {
        Subject sub1 = Subject.FS;
        Subject sub2 = Subject.AJJ;
        Subject sub3 = Subject.FS;

        Elective elec = Elective.AJJ;

        System.out.println(sub1.compareTo(sub2)); // -3
        System.out.println(sub2.compareTo(sub1)); // 3
        System.out.println(sub1.compareTo(sub3)); // 0

        // Equals
        System.out.println(sub1.equals(sub3)); // true
        System.out.println(sub1.equals(sub2)); // false
        System.out.println(sub2.equals(elec)); // false
        
        // ==
        System.out.println(sub1 == sub3); // true
        // System.out.println(sub2 == elec); // Err: Incompatible operand types
    }
}