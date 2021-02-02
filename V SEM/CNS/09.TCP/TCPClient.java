// Reference Java Docs
// https://docs.oracle.com/javase/tutorial/networking/sockets/clientServer.html#later

import java.io.BufferedReader;
import java.io.IOException;
import java.net.Socket;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class TCPClient {
    public static void main(String[] args) throws IOException {
        int port = 4444;
        String host = "127.0.0.1";
        
        // Create a socket and connect to specified port number on the named host
        Socket clientSocket = new Socket(host, port);

        // Standart input reader
        BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the filename: ");
        String filename = stdIn.readLine();

        // Get the input and output streams of client socket 
        // and open readers and writers on them
        PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
        BufferedReader in =  new BufferedReader(
            new InputStreamReader(clientSocket.getInputStream()));
        
        // Write the filename to the output stream
        out.println(filename);

        // Read the contents from the input stream
        System.out.println("The contents of the file are: \n");
        String content;
        while ((content = in.readLine()) != null) {
            System.out.println(content);
        }

        clientSocket.close();
        stdIn.close();
        out.close();
        in.close();
    }
}