import java.net.*; 
import java.io.*; 
import java.util.*; 
public class GChat 
{ 
    private static final String TERMINATE = "Exit"; 
    static String name; 
    static volatile boolean finished = false; 
    public static void main(String[] args) 
    { 
        
            try
            { 
                InetAddress group = InetAddress.getByName("239.0.0.0"); 
                int port = 7788; 
                Scanner sc = new Scanner(System.in); 

                //Inputting User name 
                System.out.print("Enter your name: "); 
                name = sc.nextLine(); 

                //Creating MultiSocket
                MulticastSocket socket = new MulticastSocket(port); 
              
             	//Joining group  
                socket.joinGroup(group); 

                //Creating thread for the client
                Thread t = new Thread(new ReadThread(socket,group,port)); 
              
                // Spawn a thread for reading messages 
                t.start();  
                  
                // sent to the current group 
                System.out.println("Start typing messages...\n"); 
                while(true) 
                { 
                    String message; 
                    System.out.print("\nEnter Message: ");
                    message = sc.nextLine(); 
                    if(message.equalsIgnoreCase(GChat.TERMINATE)) 
                    { 
                        finished = true; 
                        socket.leaveGroup(group); 
                        socket.close(); 
                        break; 
                    } 
                    message = name + ": " + message; 
                    byte[] buffer = message.getBytes(); 
                    DatagramPacket datagram = new
                    DatagramPacket(buffer,buffer.length,group,port); 
                    socket.send(datagram); 
                } 
            } 
            catch(SocketException se) 
            { 
                System.out.println("Error creating socket"); 
                se.printStackTrace(); 
            } 
            catch(IOException ie) 
            { 
                System.out.println("Error reading/writing from/to socket"); 
                ie.printStackTrace(); 
            } 
         
    } 
} 


class ReadThread implements Runnable 
{ 
    private MulticastSocket socket; 
    private InetAddress group; 
    private int port; 
    private static final int MAX_LEN = 1000; 
    ReadThread(MulticastSocket socket,InetAddress group,int port) 
    { 
        this.socket = socket; 
        this.group = group; 
        this.port = port; 
    } 
      
    @Override
    public void run() 
    { 
        while(!GChat.finished) 
        { 
            try
            { 	
                byte[] buffer = new byte[ReadThread.MAX_LEN]; 
                DatagramPacket datagram = new DatagramPacket(buffer,buffer.length,group,port); 

                socket.receive(datagram); 
                String message = new String(buffer,0,datagram.getLength(),"UTF-8"); 
                if(!message.startsWith(GChat.name)) 
                    System.out.println("\n"+message); 
            } 
            catch(IOException e) 
            { 
                System.out.println("Socket closed!"); 
            } 
        } 
    } 
}