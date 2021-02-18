
import java.io.*;
import java.net.*;

class ClientHandler extends Thread  
{ 
    private BufferedReader in;
    private PrintWriter pw;
    private Socket soc; 
    private String clientMessage = "";
    private String serverMessage = "";  
    private String clientName = "";
  
    // Constructor 
    public ClientHandler(Socket soc, String clientName)  
    { 
        this.soc = soc;
        this.clientName = clientName;
    } 
  
    @Override
    public void run()  
    { 

        while (true)  
        { 
            try { 
                
                while(soc.getInputStream() != null){
                    System.out.println();
                    in = new BufferedReader(new InputStreamReader(soc.getInputStream()));
                    clientMessage = in.readLine();
                    System.out.println("\n"+clientName+ " : " + clientMessage);
                    if(clientMessage.equalsIgnoreCase("stop"))
                    {
                        soc.close();
                        break;
                    }

                }
                 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
        }  
    } 
} 