import java.rmi.*;
import java.io.*;

public class Clients
{
	public static void main(String args[]) throws Exception
	{
		String url = "rmi://127.0.0.1/utilityObj";
		
		UtilityServices ms=(UtilityServices)Naming.lookup(url);
		
		float[] addUs={10,20};

		float sum=ms.add(addUs);

		float[] subtractUs={99.99f,23.76f};
		
		float difference=ms.subtract(subtractUs);
		
		System.out.println("\nSum is:"+sum);
		
		System.out.println("\nDifference is:"+difference);
	}
}