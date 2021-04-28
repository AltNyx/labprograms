public class TypeWrapperDemo {
    public static void main(String[] args) {
        Integer iob1 = new Integer(4); // Deprecated

        // Since JDK 9
        Integer iob2 = Integer.valueOf(4);

        System.out.println("Using constructor iob: " + iob1);
        System.out.println("Using valueOf iob: " + iob2);

        int i = iob2.intValue(); // Obtain primitive data type value
        byte b = iob2.byteValue();
        long l = iob2.longValue();

        Integer ig = 10; // autoboxing: converting primitive type to an object
        int it = ig; // auto unboxing: object is automatically unboxed
    }
}