#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector> 
#include <cmath>
#include <stdlib.h>
using namespace std;
int symcnt=0;
int litcnt = 0;
	
struct symbolTable{
	int sr.no;
	string symbol;
	int address;
	int length;
}symbolT[20];

struct symbolTable{
	int sr.no;
	string literal;
	int address;
}literalT[20];

void readSymbolTable(){

	vector<string> temp;
	ifstream sym;
	sym.open("symbolTable.txt",ios::in);
	char ch;
	string word;

	if(!sym){
		cout<<"\nNO SUCH FILE EXISTS\n";
	}else{
		while(!sym.eof()){
			sym.get(ch);

			if(ch == '\n'){

			}else if(ch == '\t'){

			}else{
				word+=ch;
			}
		}
	}
}

void readLiteralTable(){

	vector<string> temp;
	ifstream sym;
	sym.open("literalTable.txt",ios::in);
	char ch;
	string word;

	if(!sym){
		cout<<"\nNO SUCH FILE EXISTS\n";
	}else{
		while(!sym.eof()){
			sym.get(ch);

			if(ch == '\n'){

			}else if(ch == '\t'){

			}else{
				word+=ch;
			}
		}
	}	
}

int main(int argc, char const *argv[])
{
	readSymbolTable();
	readLiteralTable();
	
	return 0;
}
