import java.rmi.*;

import java.rmi.server.*;  
public class UtilityImpl extends UnicastRemoteObject implements  UtilityServices{
		public UtilityImpl() throws Exception 
		{}
		
		public float add(float[] addUs)
		{
			return addUs[0]+addUs[1];
		}
		
		public float subtract(float[] subtractUs)
		{
			return subtractUs[0]-subtractUs[1];
		}
}