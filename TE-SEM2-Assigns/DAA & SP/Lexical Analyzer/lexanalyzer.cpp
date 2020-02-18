#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector> 
#include <cmath>
#include <stdlib.h>
using namespace std;

string keys[] = {"auto" ,	"break" ,	"case" ,"char",

				"const" ,"continue" ,"default" ,"do",
				"double" ,	"else", "enum" ,"extern",
				"float" ,	"for", "goto", "if",
				"int" ,"long" ,"register" ,"return",
				"short" ,"signed" ,"sizeof","static",
				"struct" ,	"switch" ,"typedef", "union",
				"unsigned" ,"void","volatile","while"};
int keySize = sizeof(keys) / sizeof(keys[0]);
int isKeyword(string key){

	for(int i=0;i<keySize;i++){
		if(!key.compare(keys[i])){
			return 1;
		}
	}

	return 0;

}

int isConstant(){

}

int isIdentifier(){

}
int main(int argc, char const *argv[])
{
	vector<string> temp;
	vector<char> temp1;
	
	ifstream ic;
	ofstream MC;
	ic.open("testing.cpp",ios::in);
	char ch;
	string word;
	if(!ic){
		cout<<"\nNO SUCH FILE EXISTS\n";
		return -1;
	}else{
		while(!ic.eof()){
			ic.get(ch);
			if(ch == '\n'|| ch == '+' || ch == '-' || ch == '/'|| ch == '%'|| ch == '*' || ch == '=' || ch == '<' ||ch == '>' || ch == '!' || ch =='#' || ch == '\t' || ch == ' ' || ch == '(' || ch == '|' || ch == ')' || ch == ',' || ch == '='|| ch == ';' || ch == '[' || ch == '{' || ch == ']' || ch == '}' || ch == '.'){
				
				if( ch == '(' || ch == '|' || ch == ')' || ch =='#'|| ch == ',' || ch == '[' || ch == '{' || ch == ']' || ch == '}' || ch == '.' || ch == ';'){
					// cout<<"\n"<<word<<" Is Not Special Symbol";
					// cout<<"\n"<<ch<<" Is Special Symbol";
					temp.push_back(word);
					temp1.push_back(ch);	
				}else if(ch == '+' || ch == '-' || ch == '/'|| ch == '%'|| ch == '*' || ch == '=' || ch == '<' ||ch == '>' || ch == '!' ){
					// cout<<"\n"<<word<<" Is Not Special Symbol";
					temp.push_back(word);
					temp1.push_back(ch);
				}else{
					temp.push_back(word);
				}
				// temp.push_back(word);
				word="";
				if(ch == '\n'){

					for(int i=0;i<temp.size();i++){
						if(!isKeyword(temp.at(i))){
							if(!isConstant()){
								if(isIdentifier()){
									cout<<"\n"<<temp.at(i) <<" Is Identifer";
								}
							}else{
								cout<<"\n"<<temp.at(i) <<" Is constant";
							}
						}else{
							cout<<"\n"<<temp.at(i) <<" Is Keyword";
						}

					}
					for(int j=0;j<temp1.size();j++){
						cout<<"\n"<<temp1.at(j);
					}
					temp1.clear();
					temp.clear();
				}
			}else{
				word+=ch;
			}
		}
	}

	return 0;
}