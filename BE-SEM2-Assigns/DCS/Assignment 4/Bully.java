/**
 * 
 */

import java.util.Scanner;

/**
 * @author neo
 *
 */
public class Bully {
	int processes[];
	int np;
	int coordinator;
	private String boldStr;
	
	public Bully(int np) {
		this.np = np;
		processes = new int[np];
		coordinator = np;
		boldStr = "\033[2m";
		System.out.print("\nCreated Processes: ");
		for(int i = 0; i < np; i++) {
			System.out.print("P" + (i+1) + " ");
		}
		System.out.println("\n");
		System.out.println(boldStr+"\033[2mCoordinator Process: P" + this.coordinator);
		System.out.println("");
		
		
	}
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int choice = 0;
		Scanner sc = new Scanner(System.in);
		do {
			
			System.out.println("--------------------------------");
			System.out.println("\t\tMENU");
			System.out.println("--------------------------------");
			System.out.println("1. Add Number of Processes.");
			System.out.println("2. Down a process.");
			System.out.println("3. Send a Message.");
			System.out.println("4. Exit.");
			System.out.println("--------------------------------\n");
			System.out.print("Enter Your Choice: ");
			choice = sc.nextInt();
			
			switch(choice) {
			case 1:
				System.out.print("\nEnter Number of processes: ");
				int np = sc.nextInt();
				Bully bl = new Bully(np);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
			
			
			
			
			
			
		}while(choice != 4);
	}

}
