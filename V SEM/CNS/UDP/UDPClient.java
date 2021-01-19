import java.net.DatagramPacket;
import java.net.DatagramSocket;


public class UDPClient {
    public static void main(String[] args) throws Exception {
        int port = 7000;
        DatagramSocket ds = new DatagramSocket(port);
        
        byte[] buffer = new byte[100];
        boolean hasQuit = false;
        DatagramPacket dp;
        
        // Recieve the incoming packets and display it
        while (!hasQuit) {
            dp = new DatagramPacket(buffer, buffer.length);
            ds.receive(dp);
            String msg = new String(dp.getData(), dp.getOffset(), dp.getLength());
            
            if (msg.equals("quit")) {
                hasQuit = true;
                msg = "Server has quit!";
            }
            
            System.out.println(msg);
        }
        
        ds.close();
    }
}