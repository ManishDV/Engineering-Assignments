#include <iostream>
using namespace std;

/*
Grammer Rules

L= {wcw^R | w € (a, b)*} 

S->aSa | bSb | c

*/

string input;
int i = 0;

void S(){
	if(input[i] == 'a'){
		
		i = i + 1;
		S();
		if(input[i] == 'a'){
			i = i+1;
			return;
		}else{
			return;
		}
	}
	if(input[i] == 'b'){
		i = i + 1;
		S();
		if(input[i] == 'b'){
			i = i+1;
			return;
		}else{
			return;
		}
	}
	if(input[i] == 'c'){
		i = i+1;
		return;
	}

	
}

int main(int argc, char const *argv[])
{

	cout<<"\nEnter Input String: ";
	cin >> input;

	input += '$';
	cout<<input<<"\n";
	S();

	cout<<input[i]<<"\n"<<i;
	if(input[i] == '$'){
		cout<<"\nString Accepted";
	}else{
		cout<<"\nString Rejected";
	}
	cout<<"\n";
	return 0;
}
