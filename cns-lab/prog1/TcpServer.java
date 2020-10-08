package prog1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;

/**
 * TcpServer
 */
public class TcpServer {
    public static void main(String[] args) throws Exception {
        int port = 4001;

        // Establist connection with the server
        ServerSocket serverSocket = new ServerSocket(port);
        System.out.println("Server Ready!");

        // Binding with port
        Socket socket = serverSocket.accept();
        System.out.println("Connection successful!");

        // Read the filename from the client
        InputStream iStream = socket.getInputStream();
        BufferedReader bReader = new BufferedReader(new InputStreamReader(iStream));
        String fileName = bReader.readLine();

        // Read the file contents
        BufferedReader contentRead = new BufferedReader(new FileReader(fileName));

        // Send the file contents to the client
        OutputStream oStream = socket.getOutputStream();
        PrintWriter pWriter = new PrintWriter(oStream, true);
        String content;

        while ((content = contentRead.readLine()) != null) {
            pWriter.println(content);
        }

        // Close all
        socket.close();
        serverSocket.close();
        pWriter.close();
        contentRead.close();

    }
}