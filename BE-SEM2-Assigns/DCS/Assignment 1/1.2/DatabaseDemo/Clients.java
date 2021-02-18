import java.rmi.*;
import java.io.*;

import java.util.ArrayList;
public class Clients
{
	public static void main(String args[]) throws Exception
	{
		String url = "rmi://127.0.0.1/dbobj";
		
		DatabaseInterface ms=(DatabaseInterface)Naming.lookup(url);
		
		ArrayList<Student> data = ms.getStudentData();


		System.out.println("\n-----------------------------------------------\n");
		System.out.println("\nROLL_NO\t  NAME\t\t\t  CLASS\n");
		System.out.println("\n-----------------------------------------------\n");
		

		for(Student s : data){
			System.out.println(s.getRoll() + "\t  " + s.getName() + "\t\t\t " + s.getClassName() + "\n");
			System.out.println("-------------------------------------------------------\n");
					
		}

		System.out.println("\n-----------------------------------------------\n");
		



	}
}