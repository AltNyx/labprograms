// Reference Java Docs
// https://docs.oracle.com/javase/tutorial/networking/sockets/clientServer.html#later

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.InputStreamReader;

public class TCPServer {
    public static void main(String[] args) throws IOException {
        int port = 4444;
        
        // Create  a server socket bound to the specified port
        ServerSocket serverSocket = new ServerSocket(port);
        System.out.println("Server Ready!");
        
        // Listen for a connection and accept it
        Socket clientSocket = serverSocket.accept();
        System.out.println("Connection Sucessful!");
        
        // Get the input and output streams of client socket 
        // and open readers and writers on them
        PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(
            new InputStreamReader(clientSocket.getInputStream()));
    
        // Read the file name
        String filename = in.readLine();
        
        // ContentReader to get the contents of the file
        BufferedReader contentReader = new BufferedReader(new FileReader(filename));

        // Read the contents of the file and send it to client
        String content;
        while ((content = contentReader.readLine()) != null) {
            out.println(content);
        }

        // Close all resources
        contentReader.close();
        serverSocket.close();
        clientSocket.close();
        out.close();
        in.close();
    }
}