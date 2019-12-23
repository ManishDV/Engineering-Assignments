#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;


int main(int argc, char const *argv[])
{
	ifstream fin;
	fin.open("/home/oslab-17/file.txt", ios::in);

	string keys[] = {"auto" ,	"break" ,	"case" ,"char",

					"const" ,"continue" ,"default" ,"	do",
					"double" ,	"else", "	enum" ,"	extern",
					"float" ,	"for", "	goto", "	if",
					"int" ,"	long" ,"	register" ,"	return",
					"short" ,"	signed" ,"	sizeof"," 	static",
					"struct" ,	"switch" ,"	typedef", "	union",
					"unsigned" ,"	void"," 	volatile"," 	while"};

	 int size = sizeof(keys)/sizeof(keys[0]);
	 int count[size];
	 for(int i=0;i<size;i++){
		count[i] = 0;
	 }
	 char ch;
	 string words;
	 int j=0;
	 if(fin == NULL){
		cout<<"\nFILE DOES NOT EXISTS";	
	}else{

		while(!fin.eof()){
			fin.get(ch);
			
			if(isdigit(ch) || ch == ' ' || ch == '<' || ch == '>' || ch == ':'|| ch == '\n' || ch == '(' || ch == '[' || ch == '{' || ch =='\t' || ch == ';' || ch == ')'||ch==',' || ch == '}' || ch== ']' || ch =='='){
				cout<<words<<" ";
				for(int i=0;i<size;i++){
					if(!strcmp(words.c_str(),keys[i].c_str())){
						count[i]++;
					}

					
				}
					words = "";
				}
				else{
					words+=ch;
			}
		}
		
		cout<<"\nKEYWORD"<<"\t\t"<<"COUNT";
		for(int i=0;i<32;i++){

			if(count[i] != 0){
				cout<<"\n"<<keys[i]<<"\t\t"<<count[i];
			}
		}	
		cout<<"\n";
	} 				 
	return 0;
}