import java.rmi.*;
import java.util.ArrayList;

public interface DatabaseInterface extends Remote{
	public ArrayList<Student> getStudentData() throws RemoteException;
}