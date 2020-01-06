#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector> 
#include <cmath>
using namespace std;

int LC = 0;
struct symTable{
	int sr;
	string symbol;
	int address;
	int length;
}symbolTable[20];

struct literalTable{
	int sr;
	string literal;
	int address;
}litTable[20];

bool isLiteral(string literal){

	if(literal[0] == '\'' && literal[1] == '='){
		// cout<<"literal[0] : "<<literal[0]<< "\n literal[1] : "<<literal[1];
		return true;
	}
	return false;
}

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
bool isNumber(string s) 
{ 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
    return true; 
} 
bool isReg(string reg){
	if(!reg.compare("AREG") || !reg.compare("BREG") || !reg.compare("CREG") || !reg.compare("DREG")){
		return true;
	}else{
		return false;
	}
}
bool isPresent(struct symTable symbolTable[20],int symcount,string symbol){
	for(int i=0;i<symcount;i++){
		if(!(symbolTable[i].symbol).compare(symbol)){
			return true;
		}
	}
	return false;
}


bool isLiteralPresent(string lit,int n){
	for(int i=0;i<n;i++){
		if(!lit.compare(litTable[i].literal)){
			return true;
		}

	}
	return false;
}
int main(int argc,char const*argv[]){
	ifstream fin;
	ofstream fout;
	fout.open("Intermediate.txt",ios::out);
	fin.open("file.txt", ios::in);
	char ch;
	string ad[] ={"EQU","ORG","DS","DC","INCLUDE","LTORG","END","START"};
	string IS[] ={"READ","PRINT","MOVER","ADD","MOVEM","STOP","BC"};
	string reg[] ={"AREG","BREG","CREG","DREG"};
	string word;


	int poolTab[10];
	vector<string> g1;
	int adSize = sizeof(ad) / sizeof(ad[0]);
	int isSize = sizeof(IS) / sizeof(IS[0]);
	std::vector<string> directives;
	std::vector<string> imperative;
	std::vector<string> pool;

	int isSymbol = 1;
	int i=0;
	int k = 0;
	int poolcnt = 0;
	int litcnt = 0;
	int symcount = 0;
	if(!fin){
	   cout<<"\nFILE DOES NOT EXISTS";	
	}else{
	   while(!fin.eof()){
			fin.get(ch);
			if(ch == ' ' || ch == ',' || ch == '\n'){
				g1.push_back(word);
				if(ch == '\n'){
					LC++;
					for(int i=0;i<g1.size();i++){
						for(int j = 0;j<adSize;j++){
							if(!g1.at(i).compare("END") || !g1.at(i).compare("LTORG")){
								LC--;
								if(pool.size()){
									poolTab[poolcnt] = litcnt+1;
								}
								for(int z=0;z<pool.size();z++){
									litTable[litcnt].sr = litcnt+1;
									litTable[litcnt].literal = pool[0];
									litTable[litcnt].address = LC;
									LC++;
									litcnt++;

								}
								if(pool.size()){
									poolcnt++;
								}
								pool.clear();
							}
								

							if(g1.at(i).compare(ad[j]) == 0){
								directives.push_back(ad[j]);
								isSymbol = 0;
								if(!g1.at(i).compare("START")){
									fout<<"(AD,01) | ";	
								}
								else if(!g1.at(i).compare("END")){
									fout<<"(AD,02) | ";	
								}
								else if(!g1.at(i).compare("ORIGIN")){
									fout<<"(AD,03) | ";	
								}
								else if(!g1.at(i).compare("EQU")){
									fout<<"(IS,04) | ";	
								}
								else if(!g1.at(i).compare("LTORG")){
									fout<<"(AD,05) | ";	
								}
								else if(!g1.at(i).compare("DS")){
									fout<<"(DL,02) | ";	
								}
								else{
									fout<<"(DL,01) | ";	
								}
								
								break;
							}else{
								continue;
							}
						}
						for(int j=0;j<isSize;j++){
							if(g1.at(i).compare(IS[j]) == 0){
								imperative.push_back(IS[j]);
								isSymbol = 0;
								if(!g1.at(i).compare("READ")){
									fout<<"(IS,09) | ";	
								}
								else if(!g1.at(i).compare("MOVER")){
									fout<<"(IS,04) | ";	
								}
								else if(!g1.at(i).compare("MOVEM")){
									fout<<"(IS,05) | ";	
								}
								else if(!g1.at(i).compare("MULT")){
									fout<<"(IS,03) | ";	
								}
								else if(!g1.at(i).compare("ADD")){
									fout<<"(IS,01) | ";	
								}
								else if(!g1.at(i).compare("COMP")){
									fout<<"(IS,06) | ";	
								}
								else if(!g1.at(i).compare("BC")){
									fout<<"(IS,07) | ";	
								}
								else if(!g1.at(i).compare("PRINT")){
									fout<<"(IS,10) | ";	
								}
								else if(!g1.at(i).compare("STOP")){
									fout<<"(IS,00) | ";	
								}
								else if(!g1.at(i).compare("SUB")){
									fout<<"(IS,02) | ";	
								}
								else if(!g1.at(i).compare("STORE")){
									fout<<"(IS,11) | ";	
								}
								else {
									fout<<"(IS,12) | ";	
								}
								break;
							}else{
								continue;
							}							
						}
						 if(isSymbol){
						 		
						 	if(isReg(g1.at(i))){	
 							 	if(!g1.at(i).compare("AREG")){
 										fout<<"(1)";	
 								}
 								else if(!g1.at(i).compare("BREG")){
 										fout<<"(2)";	
 								}
 								else if(!g1.at(i).compare("CREG")){
 										fout<<"(3)";	
 								}
 								else if(!g1.at(i).compare("DREG")){
 										fout<<"(4)";	
 								}
 								else if(!g1.at(i).compare("LT")){
 										fout<<"(1)";	
 								}
 								else if(!g1.at(i).compare("LE")){
 										fout<<"(2)";	
 								}
 								else if(!g1.at(i).compare("EQ")){
 										fout<<"(3)";	
 								}
 								else if(!g1.at(i).compare("GT")){
 										fout<<"(4)";	
 								}
 								else if(!g1.at(i).compare("GE")){
 										fout<<"(5)";	
 								}
 								else{
 										fout<<"(6) | ";	
 								}
							}
										
						 	if(!isNumber(g1.at(i)) && !isReg(g1.at(i)) && !isLiteral(g1.at(i))){
						 		// cout<<" \n "<<g1.at(i);
						 		if(!isPresent(symbolTable,symcount,g1.at(i))){
						 				int length = 1;
						 				symbolTable[symcount].sr = symcount+1;
										symbolTable[symcount].symbol = g1.at(i);
										// cout<<"\n"<<g1.at(1);
								 		if(g1.size() == 3){
								 			length = stringToI(g1.at(2));
								 			symbolTable[symcount].address = LC;
								 			symbolTable[symcount].length = length;
								 			LC = LC+length;
								 			// cout<<"\nLC: "<<LC;	
								 		}else{
								 			symbolTable[symcount].address = 888888;
								 			symbolTable[symcount].length = length;
								 		}
								 		if(i != 0){
								 			fout<<"(S,0"<<symcount+1<<")";
								 		}
										symcount++;	
								}else{
									int count = 0;
									for(int k =0;k<symcount;k++){

										if(!(symbolTable[k].symbol).compare(g1.at(i))){
											count = k;
											break;
										}
									}
									// cout<<"\nG1: "<<g1.at(i)<<"\tSymbol: "<<symbolTable[count].symbol;
									if(i != 0){
										fout<<"(S,0"<<count+1<<")";
									}
									if(symbolTable[count].address == 888888){
										// cout<<"\n"<<g1.size();
										if(g1.size() == 3 && !(g1.at(1)).compare("DS")){
											// cout<<"\nLENGHT: "<<g1.size();
								 			int length = stringToI(g1.at(2));
								 			// cout<<"\nLENGTH: "<<length;
								 			symbolTable[count].address = LC;
								 			symbolTable[count].length = length;
								 			LC = LC+length;
									}
								}

								}		
							 }
							if(g1.size() == 2 && isNumber(g1.at(1)) && !g1.at(0).compare("START")){
								LC = stringToI(g1.at(i));
							}
							if(isNumber(g1.at(i))){
								fout<<"(C,"<<g1.at(i)<<")";
							}
							if(isLiteral(g1.at(i))){
								pool.push_back(g1.at(i));								
								
							}
							if(isLiteral(g1.at(i)) && !isLiteralPresent(g1.at(i),litcnt)){
								fout<<"(L,0"<<litcnt+1<<")";
							}


						 }
						isSymbol = 1;
					}
					g1.clear();
				}
				fout<<"\n";
				word = "";
			}else{
				word+=ch;
			}
		}
	}
	cout<<"\n\t\tSYMBOL TABLE";
	cout<<"\n------------------------------------------------";
	cout<<"\nSR\t\tSYMBOL\t\tADDRESS\t\tLENGTH";
	cout<<"\n------------------------------------------------";
	for (int i = 0; i < symcount; ++i)
	{
		cout<<"\n"<<symbolTable[i].sr<<"  \t\t "<<symbolTable[i].symbol<<"  \t\t "<<symbolTable[i].address<<"  \t\t "<<symbolTable[i].length;
	}
	cout<<"\n------------------------------------------------";
	
	cout<<"\n\n\t\tLITERAL TABLE";
	cout<<"\n------------------------------------------------";
	cout<<"\nSR\t\tLITERAL\t\tADDRESS";
	cout<<"\n------------------------------------------------";
	for (int i = 0; i < litcnt; ++i)
	{
		cout<<"\n"<<litTable[i].sr<<"  \t\t "<<litTable[i].literal<<"  \t\t "<<litTable[i].address;
	}
	cout<<"\n------------------------------------------------";
	
	cout<<"\n\n\t\tPOOL TABLE";
	cout<<"\n------------------------------------------------";
	cout<<"\n\t\tLITERAL NO";
	cout<<"\n------------------------------------------------";
	for (int i = 0; i < poolcnt; ++i)
	{
		cout<<"\n\t\t  #"<<poolTab[i];
	}
	cout<<"\n------------------------------------------------";
	
	

	printf("\n");	
}

