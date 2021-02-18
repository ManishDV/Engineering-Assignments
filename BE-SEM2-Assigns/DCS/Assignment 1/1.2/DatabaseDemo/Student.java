import java.io.Serializable;
public class Student implements Serializable{
	int roll_no;
	String name;
	String _class;

	public Student(int roll,String name,String _class){
		this.roll_no = roll;
		this.name = name;
		this._class = _class;
	}

	int getRoll(){
		return this.roll_no;
	}

	String getName(){
		return this.name;
	}

	String getClassName(){
		return this._class;
	}

}