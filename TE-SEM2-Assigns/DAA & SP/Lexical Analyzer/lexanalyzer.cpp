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

int isConstant(string str){

	std::vector<int> count;
	for(int i=0;i<str.length();i++){
		if(isdigit(str[i]) == false){
			return 0;
		}
	}

	return 1;
}

int isIdentifier(string s){
	int flag = 0;
	if(s.length() == 1){
		if(s[0]=='_' || (s[0] >= 65 && s[0] <= 90) || (s[0] >= 97 && s[0] <= 122)){
		return 1;			
	}
	}
	if(s[0] == '_' || s[0] >= 65 && s[0] <= 90 || s[0] >= 97 && s[0] <= 122){
		for(int i=1;i<s.length();i++){
			if(s[i] == '_' || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i]<=57)){
				flag = 1;
			}else{
				flag = 0;
				break;
			}

		}

	}
		
	if(flag == 1){
		return 1;
	}	
	return 0;
}

int isConstant1(char str){

		if(isdigit(str) == false){
			return 0;
		}

	return 1;
}

int isIdentifier1(char s){
	if(s == '_' || (s >= 65 && s <= 90) || (s >= 97 && s <= 122)){
		return 0;			
	}
	return 1;
}

int isOperator(char ch){
	if(ch == '+' || ch == '-' || ch == '/'|| ch == '%'|| ch == '*' || ch == '=' || ch == '<' ||ch == '>' || ch == '!' ){
		return 1;
	}
	return 0;
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
			if(ch == '\n'|| ch == ' '|| ch == '+' || ch == '-' || ch == '/'|| ch == '%'|| ch == '*' || ch == '=' || ch == '<' ||ch == '>' || ch == '!' || ch =='#' || ch == '\t' || ch == ' ' || ch == '(' || ch == '|' || ch == ')' || ch == ',' || ch == '='|| ch == ';' || ch == '[' || ch == '{' || ch == ']' || ch == '}' || ch == '.'){
				
				if( ch == '(' || ch == ' ' || ch == '|' || ch == ')' || ch =='#'|| ch == ',' || ch == '[' || ch == '{' || ch == ']' || ch == '}' || ch == '.' || ch == ';'){
					// cout<<"\n"<<word<<" Is Not Special Symbol";
					// cout<<"\n"<<ch<<" Is Special Symbol";
						if(ch == ' '){
							temp.push_back(word);
						}else{
							temp1.push_back(ch);
							temp.push_back(word);		
						}
					
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
							if(!isConstant(temp.at(i))){
								if(isIdentifier(temp.at(i))){
									cout<<"\n"<<temp.at(i) <<" Is Identifer";
								}else{
									// cout<<"\n"<<temp.at(i);
									if(temp.at(i)[0] == '"'){
										cout<<"\n"<<temp.at(i) <<" Is Constant";
									}else{
										cout<<"\nSpecial Thing";
									}
								}
							}else{
									if(!temp.at(i).compare("")){

									}else{
										cout<<"\n"<<temp.at(i) <<" Is constant";	
									}
									
							}
						}else{
							cout<<"\n"<<temp.at(i) <<" Is Keyword";
						}

					}
					for(int i=0;i<temp1.size();i++){
							if(!isConstant1(temp1.at(i))){
								if(!isOperator(temp1.at(i))){
									if(!isIdentifier1(temp1.at(i))){
										cout<<"\n"<<temp1.at(i) <<" Is Identifer";
									}else{
										cout<<"\n"<<temp1.at(i) <<" Is Special Symbol";
									}	
								}else{
									cout<<"\n"<<temp1.at(i) <<" Is Operator";
								}
								
							}else{
								if(temp1.at(i) == ' '){

								}else{
									cout<<"\n"<<temp1.at(i) <<" Is constant";
								
								}
							}						
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