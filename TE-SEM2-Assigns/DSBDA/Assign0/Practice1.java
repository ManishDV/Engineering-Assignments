import java.util.Scanner;

public class Practice1 {
	
	public Practice1() {
		// TODO Auto-generated constructor stub
		int a,b;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter The Value Of a: ");
		a = sc.nextInt();

		System.out.println("Enter The Value Of b: ");
		b = sc.nextInt();
		sc.close();
		try {
			System.out.println("Division Is: "+a/b);
		}catch (Exception e) {
			// TODO: handle exception
			System.out.println(e.getMessage());
		}
	}
	
	
	public static void main(String[] args) {
		Practice1 p = new Practice1();
		}
}
