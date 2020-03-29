#include <iostream>
using namespace std;

/*
Grammer Rules
E  -->  TE'
E' -->  +TE' | -TE' | e
T  -->  FT'
T' -->  *FT' | /FT' | e
F  -->  digit 

*/

string input;
int i = 0;


void F(){
	if(isdigit(input[i])){
		i = i + 1;
	}
}
void T_(){
	if(input[i] == '*' || input[i] == '/'){
		i = i + 1;
		
		if(input[i] == '$'){
			i = i - 1;
			return;
		}
		
		F();
		T_();
	}
}

void T(){
	F();
	T_();
}


void E_(){
	if(input[i] == '+' || input[i] == '-'){
		i = i + 1;

		if(input[i] == '$'){
			i = i - 1;
			return;
		}
		T();
		E_();
	}
}


void E(){
	T();
	E_();	
}

int main(int argc, char const *argv[])
{

	cout<<"\nEnter Input String: ";
	cin >> input;

	input += '$';
	cout<<input<<"\n";
	E();

	cout<<input[i]<<"\n"<<i;
	if(input[i] == '$'){
		cout<<"\nString Accepted";
	}else{
		cout<<"\nString Rejected";
	}
	cout<<"\n";
	return 0;
}
