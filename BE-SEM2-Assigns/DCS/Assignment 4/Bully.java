/**
 * 
 */
package com.dcs.election;

import java.util.Scanner;

/**
 * @author neo
 *
 */
public class Bully {
	boolean processes[];
	int np;
	int coordinator;
	
	public Bully(int np) {
		this.np = np;
		processes = new boolean[np];
		coordinator = np;
		
		System.out.print("\nCreated Processes: ");
		for(int i = 0; i < np; i++) {
			System.out.print("P" + (i+1) + " ");
			processes[i] = true;
		}
		System.out.println("\n");
		System.out.println("Coordinator Process: P" + this.coordinator);
		System.out.println("");
		
		
	}
	
	//Changing state of process to up
	void up(int proc) {
		//if process is already up
		if(processes[proc-1])
			System.out.println("\nProcess P"+proc+" is already UP!");
		else {
			//Making process up and starting election by sending [ELECTION] message to upper processes
			processes[proc-1] = true;
			System.out.println("\nProcess " + proc + " Started Election");
			//if process to be UP is highest order process then do the formality of sending message to lower processes
			if(proc == np) {
				for(int i = proc-2; i > 0; i--) {
					System.out.println("\nProcess P" + proc + " sent [ELECTION] Messag to Process P" + (i+1));
				}
				//Make process coordinator
				coordinator = proc;
			}else {
				//if process to be up is not highest of all then send message to higher processes
				for(int i = proc; i < np; i++) {
					System.out.println("\nProcess P" + proc + " sent [ELECTION] Messag to Process P" + (i+1));
					if(processes[i]) {
						coordinator = i;
					}
				}
			}
			
			System.out.println("\n[COORDINATOR] Message Sent by Process P" + coordinator + " to All other Processes");
			
		}
			
	}
	
	
	void down(int proc) {
		//if process is already down 
		if(!processes[proc-1])
			System.out.println("Process " + proc + " is already down !");
		else{
			//Make process down
			processes[proc-1] = false;
			System.out.println("Process P" + proc + " is down");
		}
	}
	
	//Showing active processes
	void showActive() {
		System.out.print("\nActive Processes Are : ");
		for(int i = 0; i < processes.length; i++) {
			if(processes[i])
				System.out.print("P" + (i+1) + "\t");
		}
		System.out.println();
	}
	
	//Sending Message to start Election
	void sendMessage(int proc) {
		//if process is not down then process can send message
		if(processes[proc-1]) {
			System.out.println("\nProcess P" + proc + " Started Election");
			//Same as up()
			if(proc == np) {
				for(int i = proc-1; i > 0; i--) {
					System.out.println("\nProcess P" + proc + " sent Election Messag to Process P" + (i+1));
				}
				coordinator = proc;
			}else {
				for(int i = proc; i < np; i++) {
					System.out.println("\nProcess P" + proc + " sent Election Messag to Process P" + (i+1));
					if(processes[i]) {
						coordinator = i+1;
					}
				}
			}
			
			System.out.println("\n[COORDINATOR] Message Sent by Process P" + coordinator + " to All other Processes");
			
			
		}else {
			System.out.println("\nProcess " + proc + " is down can't send message\n");
		}
	}
	
	void showCoord() {
		System.out.println("Process P"+coordinator+" is Coordinator Process");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int choice = 0;
		Bully bl = null;
		int proc = 0;
		Scanner sc = new Scanner(System.in);
		do {
			
			System.out.println("--------------------------------");
			System.out.println("\t\tMENU");
			System.out.println("--------------------------------");
			System.out.println("1. Add Number of Processes.");
			System.out.println("2. Show Active Processes.");
			System.out.println("3. DOWN a process.");
			System.out.println("4. UP a process.");
			System.out.println("5. Send a Message.");
			System.out.println("6. Show Coordinator Process.");
			System.out.println("7. Exit.");
			
			System.out.println("--------------------------------\n");
			System.out.print("Enter Your Choice: ");
			choice = sc.nextInt();
			
			switch(choice) {
			case 1:
				System.out.print("\nEnter Number of processes: ");
				int np = sc.nextInt();
				bl = new Bully(np);
				break;
			case 2:
				bl.showActive();
				break;
			case 3:
				proc = 0;
				System.out.println("Enter the Process Number to be down: ");
				proc = sc.nextInt();
				bl.down(proc);
				break;
			case 4:
				System.out.println("Enter the Process Number to UP: ");
				proc = sc.nextInt();
				bl.up(proc);
				break;
			case 5:
				System.out.println("Enter the Process Number which will Send Message: ");
				proc = sc.nextInt();
				bl.sendMessage(proc);
				break;
			case 6:
				bl.showCoord();
			case 7:
				break;
			default:
				System.out.println("Please select valid Option");
				break;
			}
			
		}while(choice != 7);
	}

}
