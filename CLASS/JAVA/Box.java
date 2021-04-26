public class Box {
    static int numBoxes;
    int width;
    int height;
    int length;
    
    Box(int width, int height, int length) {
        this.width = width;
        this.height = height;
        this.length = length;
        numBoxes++;
    }

    static {
        System.out.println("Box initialized");
    }

    int volume() {
        return this.width*this.height*this.length;
    }

    public static void main(String[] args) {
        // OOP
        Box box1 = new Box(1, 2, 3);
        Box box2 = new Box(4, 5, 6);
        Box box3 = new Box(7, 8, 9);
        
        System.out.println(Box.numBoxes);  // 3
        System.out.println(box1.volume()); // 6
        System.out.println(box2.volume()); // 120
        System.out.println(box3.volume()); // 504
    }
}