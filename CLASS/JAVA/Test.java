public class Test {
    public static void main(String[] args) {
        // Switch
        int day = 6;
        switch (day) {
        case 1:
            System.out.println("Monday");
            break;
        case 2:
            System.out.println("Tuesday");
            break;

        case 3:
            System.out.println("Wednesday");
            break;
        case 6: // No break causes all statements to execute until it finds a break
        case 7:
            System.out.println("Weekend");
            break;
        default:
            System.out.println("Invalid day.");
        } // weekend

        // Arrays
        String[] subjects = { "Java", "Python", "Rust" };

        for (int i = 0; i < subjects.length; i++) {
            System.out.println(subjects[i]);
        }

        // For each
        for (String subject : subjects) {
            System.out.println(subject);
        }

        // While loop
        int counter = 0;
        int limit = 10;
        while (++counter < limit) {
            System.out.println(counter);
        } // 1...9

        // Break and continue
        int tick = 0;
        while (++tick < 10) {
            if (tick == 3)
                continue;
            if (tick == 5)
                break;
            System.out.println(tick);
        } // 1 2 4
    }
}