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
	int sr_no;
	string symbol;
	int address;
	int length;
}symbolT[20];

struct literalTable{
	int sr_no;
	string literal;
	int address;
}literalT[20];


int stringToI(string s){
	int num = 0;
	// cout<<"\nLENGTH "<<s.length();
	int thresh = pow(10,s.length()-1);
	for (int i = 0; i < s.length(); ++i)
	{
		int temp = int(s[i]) - 48;
		num += thresh * temp;
		thresh = thresh / 10;	
	}
	return num;
}

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

			if(ch == '\n' || ch == '\t'){
				
				temp.push_back(word);
				word="";
				if(ch == '\n'){
					// temp.erase(remove(temp.begin(), temp.end(), ""), temp.end());
					if(temp.size() >= 4){
						symbolT[symcnt].sr_no = stringToI(temp.at(1));
						symbolT[symcnt].symbol = temp.at(2);
						symbolT[symcnt].address = stringToI(temp.at(3));
						symbolT[symcnt].length = stringToI(temp.at(4));
						symcnt++;	
					}
					
					temp.clear();
				}
			}else{
				word+=ch;
			}
		}
	}
}

void readLiteralTable(){

	vector<string> temp;
	ifstream lit;
	lit.open("literalTable.txt",ios::in);
	char ch;
	string word;

	if(!lit){
		cout<<"\nNO SUCH FILE EXISTS\n";
	}else{
		while(!lit.eof()){
			lit.get(ch);

			if(ch == '\n' || ch == '\t'){
				
				temp.push_back(word);
				word="";
				if(ch == '\n'){
					
					// temp.erase(remove(temp.begin(), temp.end(), ""), temp.end());
					if(temp.size() >= 4){
						literalT[litcnt].sr_no = stringToI(temp.at(1));
						literalT[litcnt].literal = temp.at(2);
						literalT[litcnt].address = stringToI(temp.at(3));
						// literalT[symcnt].length = stringToI(temp.at(4));
						litcnt++;	
					}
					
					temp.clear();
				}
			}else{
				word+=ch;
			}
		}
	}	
}

int findSymbolAddress(int index){
	return symbolT[index-1].address;
}

int findLiteralAddress(int index){
	int add = literalT[index-1].address;
	cout<<"\nADD: "<<add<<"\n";
	return add;
}

int generateMachineCode(){
	vector<string> temp;
	ifstream ic;
	ofstream MC;
	MC.open("machinecode.txt",ios::out);
	ic.open("Intermediate.txt",ios::in);
	char ch;
	string word;

	MC<<"ADDRESS\t\tOPCODE\t\t  REGISTER\t\t    MEMORY\n\n";
	if(!ic){
		cout<<"\nNO SUCH FILE EXISTS\n";
		return -1;
	}else{
		while(!ic.eof()){
			ic.get(ch);

			if(ch == '('|| ch == '|' || ch == ' '){
				continue;
			}
			if(ch == '\n' || ch == '\t' || ch == '(' || ch == '|' || ch == ')' || ch == ','){
				
				temp.push_back(word);
				word="";
				if(ch == '\n'){
					// cout<<"\nSIZE : "<<temp.size()<<"\n";
					// cout<<"\n==========================================================================\n";
					// for(int i=0;i<temp.size();i++){
					// 	cout<<temp.at(i)<<"\t";
					// }	
					// cout<<"\n==========================================================================\n";
					if(temp.size() == 6){
						if(!temp.at(1).compare("AD")){
							MC<<"--------------------- NO CODE BECAUSE OF AD STATEMENT -----------------------\n\n";
						}else if(!temp.at(1).compare("IS")){
							int address = 0;
							if(!temp.at(3).compare("S")){
								address = findSymbolAddress(stringToI(temp.at(4)));
								MC<<temp.at(0)<<" \t\t "<<temp.at(2)<<" \t\t ___________ \t\t "<<address<<"\n\n";
							}else{
								address = findLiteralAddress(stringToI(temp.at(4)));
								MC<<temp.at(0)<<" \t "<<temp.at(2)<<" \t ___________ \t\t "<<address<<"\n\n";
							}
						}else{
							MC<<"--------------------- NO CODE BECAUSE OF DL STATEMENT -----------------------\n\n";
						}
					}

					if(temp.size() == 7){
						if(!temp.at(1).compare("AD")){
							MC<<"--------------------- NO CODE BECAUSE OF AD STATEMENT -----------------------\n";
						}else if(!temp.at(1).compare("IS")){
							int address = 0;
							if(!temp.at(4).compare("S")){
								address = findSymbolAddress(stringToI(temp.at(5)));
								MC<<temp.at(0)<<" \t\t "<<temp.at(2)<<" \t\t "<<temp.at(3)<<" \t\t\t\t\t "<<address<<"\n\n";
							}else{
								address = findLiteralAddress(stringToI(temp.at(5)));
								MC<<temp.at(0)<<" \t\t "<<temp.at(2)<<" \t\t "<<temp.at(3)<<" \t\t\t\t\t "<<address<<"\n\n";
							}
						}else{
							MC<<"--------------------- NO CODE BECAUSE OF DL STATEMENT -----------------------\n\n";
						}	
					}

					if(temp.size() == 4){
						if(!temp.at(1).compare("AD")){
							MC<<"--------------------- NO CODE BECAUSE OF AD STATEMENT -----------------------\n\n";
						}else if(!temp.at(1).compare("IS")){
							MC<<temp.at(0)<<" \t\t "<<temp.at(2)<<" \t\t ___________ \t\t ___________ \n\n";
							
						}else{
							MC<<"--------------------- NO CODE BECAUSE OF DL STATEMENT -----------------------\n\n";
						}		
					}					
					temp.clear();
				}
			}else{
				word+=ch;
			}
		}
	}

	return 1;	
}

int main(int argc, char const *argv[])
{
	readSymbolTable();
	readLiteralTable();
	int status = generateMachineCode();
	if(status == 1){
		cout<<"\nMachine Code Is Successfully Generated\n";
	}
	return 0;
}
