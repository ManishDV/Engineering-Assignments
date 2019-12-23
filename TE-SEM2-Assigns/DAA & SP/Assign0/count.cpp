#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	
	ifstream fin;
	fin.open("/home/oslab-17/file.txt", ios::in);
	char ch;
	int lines = 0,spaces = 0,chars = 0;
	if(fin == NULL){
		cout<<"\nFILE DOES NOT EXISTS";	
	}else{

		while(!fin.eof()){
			fin.get(ch);
			if(ch == ' '){
				spaces++;
			}else if(ch == '\n'){
				lines++;
			}else{
				chars++;
			}
		}
		
		cout<<"\nNumber Of Lines In File: "<<lines;
		cout<<"\nNumber Of Spaces In File: "<<spaces;
		cout<<"\nNumber Of characters In File: "<<chars;
		cout<<"\nNumber Of words In File: "<<spaces+Lines;
		cout<<"\n";
	}
	
	return 0;
}