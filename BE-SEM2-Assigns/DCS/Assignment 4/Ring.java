package com.dcs.election;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Ring {
	
	ArrayList<Integer> processIds;
	boolean processes[];
	int coordinator;
	int np;
	public Ring(int np) {
		processIds = new ArrayList<Integer>();
		coordinator = np;
		processes = new boolean[np];
		System.out.print("\nCreated Processes: ");
		for(int i = 0; i < np; i++) {
			System.out.print("P" + (i+1) + " ");
			processes[i] = true;
		}
		this.np = np;
		System.out.println("\n");
		System.out.println("Coordinator Process: P" + this.coordinator);
		System.out.println("");
	}
	
	void showActive() {
		System.out.print("\nActive Processes Are : ");
		for(int i = 0; i < processes.length; i++) {
			if(processes[i])
				System.out.print("P" + (i+1) + "\t");
		}
		System.out.println();
	}
	
	
	void down(int proc) {
		//if process is already down 
		if(!processes[proc-1])
			System.out.println("\nProcess " + proc + " is already down !");
		else{
			//Make process down
			processes[proc-1] = false;
			System.out.println("\nProcess P" + proc + " is down");
		}
	}
	
	void startElection(int proc) {
		if(processes[proc-1]) {
			processIds.add(proc);
			int i = proc;
			System.out.print("Process P"+proc+ " Sends Following List: [");
			for(Integer num : processIds)
				System.out.print(num+" ");
			System.out.print("] \n\n");
			while(i != proc-1) {
				if(processes[i]) {
					processIds.add(i+1);
					System.out.print("Process P"+(i+1)+ " Sends Following List: [");
					for(Integer num : processIds)
						System.out.print(num+" ");
					System.out.print("] \n\n");
				}else
					System.out.println("Process P"+(i+1) + " is down\n");
				i = (i+1)%np;
			}
			
			int maxim = Collections.max(processIds);
			System.out.println("Process P"+proc + " declares Process P"+(maxim) + " as coordinator");
			coordinator = maxim;
			processIds.clear();
		}else {
			System.out.println("\nProcess P"+proc + " is Down!");
		}
	}
	
	void showCoord() {
		System.out.println("\nProcess P"+coordinator+" is Coordinator Process");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int choice = 0;
		int proc = 0;
		Ring r = null;
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
				r = new Ring(np);
				break;
			case 2:
				r.showActive();
				break;
			case 3:
				proc = 0;
				System.out.print("\nEnter the Process Number to be down: ");
				proc = sc.nextInt();
				r.down(proc);
				break;
			case 4:
				break;
			case 5:
				System.out.print("\nEnter the Process Number which will Send Message: ");
				proc = sc.nextInt();
				r.startElection(proc);
				break;
			case 6:
				r.showCoord();
				break;
			case 7:
				break;
			default:
				System.out.println("Please select valid Option");
				break;
			}
			
		}while(choice != 7);
	}

}
