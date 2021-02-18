import java.net.*;
import java.io.*;

public class SingleClientServer
{

	private ServerSocket ss = null;
	private Socket s = null;
	private String clientMessage = "";
	private String serverMessage = "";
	private BufferedReader br = null;
	private PrintWriter pw = null;


	public SingleClientServer(int port){
		try{
			ss = new ServerSocket(port);
			s = ss.accept();
			pw = new PrintWriter(s.getOutputStream());

			while(s.getInputStream() != null){
				System.out.println();
				br = new BufferedReader(new InputStreamReader(s.getInputStream()));
				clientMessage = br.readLine();
				System.out.println("\nClient : " + clientMessage);

				if(clientMessage.equalsIgnoreCase("stop"))
				{
					s.close();
					ss.close();
					break;
				}

				
				br = new BufferedReader(new InputStreamReader(System.in));
				System.out.print("\nEnter Message For Client: ");
				clientMessage = br.readLine();	
				pw.println(clientMessage);
				pw.checkError();
				pw.flush();

			}


		}catch(Exception e){
			System.out.println(e);
		}
	}

	public static void main(String args[])
	{
		SingleClientServer server = new SingleClientServer(7788);
	}
}