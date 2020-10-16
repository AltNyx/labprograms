package prog2;
/* BY V. ABHISHEK KUMAR
1CR1818163
*/

import java.net.DatagramPacket;
import java.net.DatagramSocket;

/**
 * UdpClient
 */
public class UdpClient {
    public static void main(String[] args) throws Exception {
        int port = 7000;
        // Create datagram socket
        DatagramSocket ds = new DatagramSocket(port);
        // Buffer to hold incoming packets
        byte[] buffer = new byte[100];
        // Quit check variable
        boolean hasQuit = false;
        DatagramPacket dp;
        // Recieve the incoming packets ad display it
        while (!hasQuit) {
            dp = new DatagramPacket(buffer, buffer.length);
            // Recieve packet
            ds.receive(dp);
            // Get message from packet
            String msg = new String(dp.getData(), dp.getOffset(), dp.getLength());
            System.out.println(msg);
            if (msg.equals("Server has quit...")) {
                hasQuit = true;
            }
        }
        // Close all
        ds.close();

    }
}