import java.io.*;
import java.net.*;


class DemoServer{
	
	private ServerSocket serverSoc = null;
	private Socket soc = null;
	private BufferedReader br1 = null;
	private BufferedReader br2 = null;
	private String serverMessage = "";
	private String clientMessage = "";
	
	public DemoServer(int port){
		try{
				serverSoc = new ServerSocket(port);
				soc = serverSoc.accept();

				while(!serverMessage.equals("stop")){
					//Reading Client Message
					br1 = new BufferedReader(new InputStreamReader(soc.getInputStream()));
					clientMessage = br1.readLine();
					System.out.println("Client Message: " + clientMessage);
				
					//Sending Messafe to client 
					PrintWriter pw = new PrintWriter(soc.getOutputStream());
					br2 = new BufferedReader(new InputStreamReader(System.in));
					System.out.println("Enter Message for Client: ");
					serverMessage = br2.readLine();
					pw.println(serverMessage);
					pw.checkError();
					System.out.println("");
				}


		}catch(Exception e){
			System.out.println("Server Error Occured......!\n\t" + e.toString());
		}
	}

	public static void main(String[] args) {
		DemoServer server = new DemoServer(7777);
	}


}