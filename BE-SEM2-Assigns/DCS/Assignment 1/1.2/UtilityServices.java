import java.rmi.*;

public interface UtilityServices extends Remote{

	public float add(float[] addUs) throws RemoteException;
	public float subtract(float[] subtractUs) throws RemoteException;
	// public String makeUpper(String str) throws RemoteException;
}