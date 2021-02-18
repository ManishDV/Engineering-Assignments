import java.io.*; 
import java.text.*; 
import java.util.*; 
import java.net.*; 
   
public class MultiClientServer  
{ 
    public static void main(String[] args) throws IOException  
    { 
        int port = 7788;
        ServerSocket ss = new ServerSocket(port); 
        int  i =1;
        System.out.println("Server Listening On Port " + port);  
        
        while (true)  
        { 
            Socket s = null; 
              
            try 
            { 
                s = ss.accept(); 
                System.out.println("A new client is connected : " + s); 
                Thread t = new ClientHandler(s,"Client "+String.valueOf(i)); 
                i++;
                t.start();   
            } 
            catch (Exception e){ 
                s.close(); 
                e.printStackTrace(); 
            } 
        } 
    }
} 