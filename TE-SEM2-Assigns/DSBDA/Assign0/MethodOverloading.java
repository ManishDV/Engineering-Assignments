
public class MethodOverloading {
	int a,b;
	public MethodOverloading() {
		// TODO Auto-generated constructor stub
		System.out.println("In Default Constructor");
	}
	
	
	private void area(int a,int b) {
		this.a = a;
		this.b = b;
		System.out.println("Area Of Triangle Is: "+(0.5*a*b));
	}
	public void area(int r) {
		
		System.out.println("Area Of Circle Is: "+(Math.PI*r*r));
	}
	
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MethodOverloading methodOverloading = new MethodOverloading();
		methodOverloading.area(20);
		methodOverloading.area(20,20);
		
	}

}
