import java.net.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.rmi.*;

public class Server {

	public static void main(String[] args) {
		try{

			DatabaseImpl dbimpl = new DatabaseImpl();
			Naming.rebind("dbobj",dbimpl);

		}catch(Exception e){
			System.out.println(e);
		}
	}
}