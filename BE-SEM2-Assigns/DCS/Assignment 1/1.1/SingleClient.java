
import java.net.*;
import java.io.*;

public class SingleClient
{

	private static Socket soc = null;
	private String clientMessage = "";
	private String serverMessage = "";
	private PrintWriter pw = null;
	private BufferedReader br = null;

	public SingleClient(String host,int port) throws Exception{
		
		try{
			soc = new Socket(host,port);
			pw = new PrintWriter(soc.getOutputStream());

			while(soc.getInputStream() != null){
				System.out.println();
				br = new BufferedReader(new InputStreamReader(System.in));
				System.out.print("Enter Message For Server: ");
				clientMessage = br.readLine();	
				pw.println(clientMessage);
				pw.checkError();
				pw.flush();
				
				br = new BufferedReader(new InputStreamReader(soc.getInputStream()));
				serverMessage = br.readLine();
				System.out.println("\nServer : " + serverMessage);

				if(serverMessage.equalsIgnoreCase("stop"))
				{
					soc.close();
					break;
				}
			}


		}catch(Exception e){

			System.out.println(e);
		}
	}

	public static void main(String args[]) throws Exception
	{
		SingleClient client = new SingleClient("localhost",7788);
	}
}