import java.util.Scanner;

public class EvenOdd {
	
	public EvenOdd() {
		// TODO Auto-generated constructor stub

		int a;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter The Number To Check: ");
		a = sc.nextInt();
		
		if(a % 2 == 0) {
			System.out.println("The Number "+a+" Is EVEN ");
		}else {

			System.out.println("The Number "+a+" Is ODD ");
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		EvenOdd evenOdd = new EvenOdd();
	}

}
