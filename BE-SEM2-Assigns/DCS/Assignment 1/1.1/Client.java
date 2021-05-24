
import java.net.*;
import java.io.*;

public class Client
{

	private static Socket soc = null;
	private String clientMessage = "";
	private String serverMessage = "";
	private PrintWriter pw = null;
	private BufferedReader br = null;

	public Client(String host,int port) throws Exception{
		
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
			}


		}catch(Exception e){

			System.out.println(e);
		}
	}

	public static void main(String args[]) throws Exception
	{
		Client client = new Client("localhost",7788);
	}
}