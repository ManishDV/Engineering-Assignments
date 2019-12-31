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
}symbolTable[20];

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

int main(int argc,char const*argv[]){
	ifstream fin;
	ofstream fout;
	fout.open("file1.txt",ios::app);
	fin.open("file.txt", ios::in);
	
	char ch;
	
	string ad[] ={"EQU","ORG","DS","INCLUDE","LTORG","END","START"};
	string IS[] ={"READ","PRINT","MOVER","ADD","MOVEM","STOP"};
	string reg[] ={"AREG","BREG","CREG","DREG"};
	string word;
	vector<string> g1;
	int adSize = sizeof(ad) / sizeof(ad[0]);
	int isSize = sizeof(IS) / sizeof(IS[0]);
	

	std::vector<string> directives;

	std::vector<string> imperative;
	int isSymbol = 1;
	int i=0;
	int k = 0;
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

							if(g1.at(i).compare(ad[j]) == 0){
								directives.push_back(ad[j]);
								isSymbol = 0;
								fout << "(IS,04)";
								break;
							}else{
								continue;
							}

						}

						for(int j=0;j<isSize;j++){
							if(g1.at(i).compare(IS[j]) == 0){
								imperative.push_back(IS[j]);
								isSymbol = 0;
								break;
							}else{
								continue;
							}							
						}




						 if(isSymbol){
						 	if(!isNumber(g1.at(i)) && !isReg(g1.at(i))){
						 		if(!isPresent(symbolTable,symcount,g1.at(i))){
						 				symbolTable[symcount].sr = symcount+1;
								 		symbolTable[symcount].symbol = g1.at(i);
								 		symbolTable[symcount].address = LC;
								 		symcount++;	
								 	}
							} 	

							if(g1.size() == 2 && isNumber(g1.at(1)) && !g1.at(0).compare("START")){
								LC = stringToI(g1.at(i));
								
							}

							if(isNumber(g1.at(i))){
								fout<<" (C,"<<g1.at(i)<<")";
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
	
	cout<<"\n------------------------------------------------";
	cout<<"\nSR\t\tSYMBOL\t\tADDRESS";
	cout<<"\n------------------------------------------------";
	for (int i = 0; i < symcount; ++i)
	{
		cout<<"\n"<<symbolTable[i].sr<<"  \t\t "<<symbolTable[i].symbol<<"  \t\t "<<symbolTable[i].address;
	}
	cout<<"\n------------------------------------------------";
	

	// cout<<"\n------------------------------------------------";
	// cout<<"\n\tIMPERATIVE STATEMENT IN GIVEN FILE";
	// cout<<"\n------------------------------------------------";
	// for (int i = 0; i < imperative.size(); ++i)
	// {
	// 	cout<<"\n\t"<<i+1<<". "<<imperative.at(i);

	// }


	printf("\n");	
	
}

