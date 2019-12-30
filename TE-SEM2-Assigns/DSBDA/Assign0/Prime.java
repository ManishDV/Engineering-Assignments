import java.util.Scanner;

public class Prime {
	
	public Prime() {
		// TODO Auto-generated constructor stub
		
		
	}
	private void checkPrime() {
		int a;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Number For Prime Check: ");
		a = sc.nextInt();
		
		
		
		int count = 1;
		for(int i=2;i<(a/2);i++) {
			if(a % i == 0) {
				count++;
			}
		}
		
		if(count < 2) {
			System.out.println("Number "+a+" Is Prime Nmber");
		}else {
			System.out.println("Number "+a+" Is Not Prime Nmber");
		}

	}
	
	
	private void generatePrime() {
		int a;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Number Upto Which Prime Numbers Should be Generated: : ");
		a = sc.nextInt();
		
		System.out.println("Prime Numbers Are: ");
		for(int i=1;i<=a;i++) {
			int count = 2;
			for(int j=2;j<i;j++) {
				if(i%j == 0) {
					count++;
				}
			}
			
			if(count<3) {
				System.out.print(i+" | ");
			}
		}
		
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Prime prime = new Prime();
		int choice = 0;
		Scanner sc = new Scanner(System.in);
		
		do {
			System.out.println("\n--------------------------------");
			System.out.println("\tMENU");
			System.out.println("--------------------------------");
			System.out.println("1. Check Prime Number");
			System.out.println("2. Generate Prime Number");
			System.out.println("3. Exit");
			System.out.println("--------------------------------");
			System.out.println("Enter Your Choice: ");		
			choice = sc.nextInt();
			
			switch(choice) {
			case 1:
					prime.checkPrime();
					break;
			case 2:
					prime.generatePrime();
					break;
			case 3:
					return;
			default:
					System.out.println("Please Enter Valid Choice");
			}
		}while(choice != 3);
				
	}

}
