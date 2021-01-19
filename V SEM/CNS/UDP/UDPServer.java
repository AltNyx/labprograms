import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;


public class UDPServer {
    public static void main(String[] args) throws Exception {
        DatagramSocket ds = new DatagramSocket();
        
        InetAddress ip = InetAddress.getByName("localhost");
        int port = 7000;
        
        boolean hasQuit = false;
        Scanner sc = new Scanner(System.in);
        DatagramPacket dp;
        
        // Read message and send it to client until server quits
        while (!hasQuit) {
            String msg = sc.nextLine();
            if (msg.equals("quit")) { hasQuit = true; }
            dp = new DatagramPacket(msg.getBytes(), msg.length(), ip, port);
            ds.send(dp);
        }
        
        sc.close();
        ds.close();
    }
}