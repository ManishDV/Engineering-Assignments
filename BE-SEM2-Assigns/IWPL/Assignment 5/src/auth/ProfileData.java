package auth;

public class ProfileData {
	
	private String first_name;
	private String last_name;
	private String address;
	private String pin;
	private String DOB;
	private char gender;
	private String email;
	private String phone;
	private String username;
	private String pass;
	
	public ProfileData() {
		
	}
	
	public ProfileData(String first_name,String last_name, String address,String pin,String DOB,char gender, String email,String phone, String username,String pass) {
		this.first_name = first_name;
		this.last_name = last_name;
		this.address = address;
		this.pin = pin;
		this.DOB = DOB;
		this.gender = gender;
		this.email = email;
		this.phone = phone;
		this.username = username;
		this.pass = pass;
		
	}


	public String getFirst_name() {
		return first_name;
	}


	public void setFirst_name(String first_name) {
		this.first_name = first_name;
	}


	public String getLast_name() {
		return last_name;
	}


	public void setLast_name(String last_name) {
		this.last_name = last_name;
	}


	public String getAddress() {
		return address;
	}


	public void setAddress(String address) {
		this.address = address;
	}


	public String getPin() {
		return pin;
	}


	public void setPin(String pin) {
		this.pin = pin;
	}


	public String getDOB() {
		return DOB;
	}


	public void setDOB(String dOB) {
		DOB = dOB;
	}


	public char getGender() {
		return gender;
	}


	public void setGender(char gender) {
		this.gender = gender;
	}


	public String getEmail() {
		return email;
	}


	public void setEmail(String email) {
		this.email = email;
	}


	public String getPhone() {
		return phone;
	}


	public void setPhone(String phone) {
		this.phone = phone;
	}


	public String getUsername() {
		return username;
	}


	public void setUsername(String username) {
		this.username = username;
	}


	public String getPass() {
		return pass;
	}


	public void setPass(String pass) {
		this.pass = pass;
	}
	
	
	
	
	
}
