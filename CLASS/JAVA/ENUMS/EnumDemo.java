package ENUMS;

enum Subject {
    FS, ST, WT, MAD // Public static final
}

enum Compass {
    EAST, WEST, NORTH, SOUTH
}

public class EnumDemo {
    public static void main(String[] args) {
        Subject sub = Subject.MAD;

        if (sub == Subject.MAD) {
            System.out.println(Subject.MAD);
        }

        switch (sub) {
            case FS:
                System.out.println("File structures");
                break;
            case ST:
                System.out.println("Software testing");
                break;
            case WT:
                System.out.println("Web technology");
                break;
            case MAD:
                System.out.println("Mobile application development");
                break;
        }


        // enum methods
        // 1. public static enum-type[] values()
        // 2. public static enum-type valueOf(String str)

        for (Subject s: Subject.values()) {
            System.out.println(s);
        } // FS ST WT MAD

        Subject fs = Subject.valueOf("FS");
        System.out.println(fs); // FS


        Compass cs = Compass.NORTH;
        System.out.println(cs);

        cs = Compass.SOUTH;

        switch (cs) {
            case EAST:
                System.out.println("Going east");
                break;
            case WEST:
                System.out.println("Going west");
                break;
            case NORTH:
                System.out.println("Going north");
                break;
            case SOUTH:
                System.out.println("Going south");
                break;
        }

        for(Compass dir: Compass.values()) {
            System.out.println(dir);
        }
        
    }
}