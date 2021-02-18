import java.rmi.*;
import java.net.*;
import java.rmi.registry.*;

public class Server 
{
	public static void main(String args[]) throws Exception
	{
		try{
			UtilityImpl m=new UtilityImpl();
			Naming.rebind("utilityObj",m);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}