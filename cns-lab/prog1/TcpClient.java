package prog1;

import java.io.BufferedReader;
import java.io.InputStream;
import java.net.Socket;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;

/**
 * TcpClient
 */
public class TcpClient {

    public static void main(String[] args) throws Exception {
        String host = "127.0.0.1";
        int port = 4001;

        // Create Socket
        Socket socket = new Socket(host, port);

        // Read file name
        BufferedReader bReader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the filename: ");
        String fileName = bReader.readLine();

        // Send the filename to server
        OutputStream oStream = socket.getOutputStream();
        PrintWriter pWriter = new PrintWriter(oStream, true);
        pWriter.println(fileName);

        // Recieving the contents of the file from the server
        InputStream iStream = socket.getInputStream();
        BufferedReader socketRead = new BufferedReader(new InputStreamReader(iStream));

        // Read and print the contents of file
        System.out.println("The file contents are: \n");
        String content;
        while ((content = socketRead.readLine()) != null) {
            System.out.println(content);
        }

        // Close all
        pWriter.close();
        socket.close();
        bReader.close();
    }
}