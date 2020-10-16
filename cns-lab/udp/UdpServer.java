package prog2;
/* BY V.ABHISHEK KUMAR
1CR1815163
*/

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

/**
 * UdpServer
 */
public class UdpServer {
    public static void main(String[] args) throws Exception {
        // Create a datagram socket
        DatagramSocket ds = new DatagramSocket();
        // Get the host ip address by host name
        InetAddress ip = InetAddress.getByName("localhost");
        // Set port
        int port = 7000;
        // Quit check variable
        boolean hasQuit = false;
        Scanner sc = new Scanner(System.in);
        DatagramPacket dp;
        // Get message and send it until server quits
        while (!hasQuit) {
            String msg = sc.nextLine();
            if (!msg.equals("quit")) {
                // Create message packet to send to the client (ip and port)
                dp = new DatagramPacket(msg.getBytes(), msg.length(), ip, port);
            } else {
                // Setting message to quit
                msg = "Server has quit...";
                dp = new DatagramPacket(msg.getBytes(), msg.length(), ip, port);
                hasQuit = true;
            }
            // Send packet
            ds.send(dp);
        }
        // Close all
        sc.close();
        ds.close();
    }
}