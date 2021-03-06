#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector> 
#include <cmath>
#include <stdlib.h>
using namespace std;

int LC = 0;
int linecount = 0;
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
char splChar;
string ad[] ={"EQU","ORG","DS","DC","INCLUDE","LTORG","END","START","ORIGIN"};
string IS[] ={"READ","PRINT","MOVER","ADD","MOVEM","STOP","BC","MULT","COMP"};
string reg[] ={"AREG","BREG","CREG","DREG"};
int adSize = sizeof(ad) / sizeof(ad[0]);
int isSize = sizeof(IS) / sizeof(IS[0]);
	
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


bool isMnemonic(string str){
	for(int i=0;i<(sizeof(IS)/sizeof(IS[0]));i++){
		if(!IS[i].compare(str)){
			cout<<"\n"<<IS[i];
			return true;
		}
	}
	return false;
}

bool isAd(string str){
	for(int i=0;i<(sizeof(ad)/sizeof(ad[0]));i++){
		if(!ad[i].compare(str)){
			cout<<"\n"<<ad[i];
			return true;
		}
	}
	return false;
}

bool isPresentLiteral(string literal,int size){
	for(int i=0;i<size;i++){
		if(!litTable[i].literal.compare(literal)){
			return true;
		}
	}
	return false;
}

bool digitCheck(string s){
	int i=0;
	for(;i<s.length();i++){
		if(isdigit(s[i])){
			continue;
		}
	}
	if(i == s.length()){
		return true;
	}
	return false;
}
int opcodeError(vector<string> g1){
	int adcnt = 0;
	int opcodecnt = 0;
	for(int g=0;g<g1.size();g++){
		for(int h = 0;h<adSize;h++){
			if(!g1.at(g).compare(ad[h])){
				adcnt = 1;
				// cout<<"\nADCNT: "<<g1.at(g);
				break;
			}
		}
		if(adcnt == 1){
			break;
		}
		for(int h = 0;h<isSize;h++){
			if(!g1.at(g).compare(IS[h])){
				opcodecnt = 1;
				break;
			}
		}
		if(opcodecnt == 1){
			break;
		}
	}
	// cout<<"\nADCNT : "<<adcnt<<"\t\t"<<"OPCODECNT: "<<opcodecnt;
		
	if(adcnt == 0 && opcodecnt == 0){
		// cout<<"\nADCNT : "<<adcnt<<"\t\t"<<"OPCODECNT: "<<opcodecnt;
		cout<<"\nInvalid OPCODE on Line "<<linecount<<"\n";
		return -1;
	}			
	return 1;	
}

void seperateTwo(string splits[2],string word){
	int j =0;
	string temp="";
	for(int i=0;i<word.length();i++){
		if(word[i] =='+' ||  word[i] =='-' ||  word[i] =='\0'){
			 splits[j] =temp;
			 temp="";
			 j++; 
			 if(word[i] =='+' ||  word[i] =='-'){
			 	splChar = word[i];
			 }
		}
		temp+=word[i];
	}
}

int main(int argc,char const*argv[]){
	ifstream fin;
	ofstream fout,tout;
	fout.open("Intermediate(Variant 1).txt",ios::out);
	tout.open("Intermediate(Variant 2).txt",ios::out);
	
	fin.open("file.txt", ios::in);
	char ch;
	string word;

	int endflg = 0;
	int poolTab[10];
	vector<string> g1;
	std::vector<string> directives;
	std::vector<string> imperative;
	std::vector<string> pool;

	int isSymbol = 1;
	int i=0;
	int k = 0;
	int poolcnt = 0;
	int litcnt = 0;
	int opcodecnt = 0;
	int adcnt = 0;
	int symcount = 0;
	if(!fin){
	   cout<<"\nFILE DOES NOT EXISTS";	
	}else{
	   while(!fin.eof()){

			fin.get(ch);
			if(ch == ' ' || ch == ',' || ch == '\n'){

				g1.push_back(word);
				if(ch == '\n'){

					
					if(linecount > 2){
						LC++;
					}
					linecount++;
					if(!g1.at(0).compare("END")){
						continue;
					}else{
						int v = opcodeError(g1);
						if(v < 0){
							return 0;
						}else{

						}	
					}
					// cout<<"\nGOING FOR SYNTAX CHECKING";
					for(int i=0;i<g1.size();i++){
						for(int j = 0;j<adSize;j++){
							if(!g1.at(i).compare("END") || !g1.at(i).compare("LTORG")){
								LC--;
								if(pool.size()){
									poolTab[poolcnt] = litcnt+1;
								}
								for(int z=0;z<pool.size();z++){
									if(!isPresentLiteral(pool.at(i),litcnt)){
										litTable[litcnt].sr = litcnt+1;
										litTable[litcnt].literal = pool[0];
										litTable[litcnt].address = LC;
										LC++;
										litcnt++;
		
									}else{
										continue;
									}	
									
								}
								if(pool.size()){
									poolcnt++;
								}
								pool.clear();

							}
								

							if(g1.at(i).compare(ad[j]) == 0){
								adcnt = 1;
								directives.push_back(ad[j]);
								isSymbol = 0;
								if(!g1.at(i).compare("START")){
									fout<<"(AD,01) | ";
									tout<<"(AD,01) | ";
									if(g1.size() > 2){
										cout<<"\nThere is Extra Symbol On Line "<<linecount<<"\n";
										return 0;
									}	
								}
								else if(!g1.at(i).compare("END")){
									fout<<"(AD,02) | ";
									tout<<"(AD,02) | ";
									endflg = 1;
									if(g1.size() > 1){
										cout<<"\nThere Should Not Be Anything Followed or Precceded By END On Line "<<linecount<<"\n";
										return 0;	
									}	
								}
								else if(!g1.at(i).compare("ORIGIN")){
									fout<<"(AD,03) | ";	
									tout<<"(AD,03) | ";
									int address = 0;
									if(digitCheck(g1.at(1))){
										LC = stringToI(g1.at(1));
									}else{
										string splits[2] = {"",""};
										seperateTwo(splits,g1.at(i+1));
										if(isPresent(symbolTable,symcount,splits[0]))
										{
											int add = 0;
											for(int k =0;k<symcount;k++){
												if(!symbolTable[i].symbol.compare(splits[0])){
													add = symbolTable[i].address;
												}

											}
											if(splChar == '+'){
												LC = add + stringToI(splits[1]); 
											}

											if(splChar == '-'){
												LC = add - stringToI(splits[1]); 
											}
										}
									}

								
								}
								else if(!g1.at(i).compare("EQU")){
									fout<<"(IS,04) | ";
									tout<<"(IS,04) | ";	
									if(g1.size() > 3){
										cout<<"\nThere Is Extra Symbol On Line "<<linecount<<"\n";
										return 0;
									}
								}
								else if(!g1.at(i).compare("LTORG")){
									fout<<"(AD,05) | ";
									tout<<"(AD,05) | ";
									
									if(g1.size() > 1){
										cout<<"\nThere Should Not Be Anything Followed or Precceded By END On Line "<<linecount<<"\n";
										return 0;
									}	
								}
								else if(!g1.at(i).compare("DS")){
									fout<<"(DL,02) | ";
									tout<<"(DL,02) | ";
									if(g1.size() > 3){
										cout<<"\nThere Is Extra Symbol On Line "<<linecount<<"\n";
										return 0;
									}	
								}
								else{
									fout<<"(DL,01) | ";	
									tout<<"(DL,01) | ";
									if(g1.size() > 3){
										cout<<"\nThere Is Extra Symbol On Line "<<linecount<<"\n";
										return 0;
									}	
								}
								
								break;
							}else{
								continue;
							}
						}
						for(int j=0;j<isSize;j++){
							if(g1.at(i).compare(IS[j]) == 0){
								opcodecnt = 1;
								imperative.push_back(IS[j]);
								isSymbol = 0;
								if(!g1.at(i).compare("READ")){
									fout<<"(IS,09) | ";
									tout<<"(IS,09) | ";
										
									if(!isMnemonic(g1.at(i+1))){
										if(!isReg(g1.at(i+1))){
											if(!isAd(g1.at(i+1))){

											}else{
												cout<<"\nThere Should Be Symbol After READ and Not Assembler directive on line "<<linecount <<"\n";
												return 0;
											}
										}else{

												cout<<"\nThere Should Be Symbol After READ and Not Register on Line "<<linecount <<"\n";
												return 0;
										}
									}else{

												cout<<"\nThere Should Be Symbol After READ and Not Mnemonic on Line "<<linecount <<"\n";
												return 0;
									}
								}
								else if(!g1.at(i).compare("MOVER")){
									fout<<"(IS,04) | ";
									tout<<"(IS,04) | ";
									
									if(g1.size() >= 3){

											if(!isMnemonic(g1.at(i+1))){
												if(!isAd(g1.at(i+1))){
													if(isReg(g1.at(i+1))){;
													}else{

														cout<<"\nThere Must Be Register After MOVER on Line "<<linecount<<"\n";
														return 0;
													}
												}else{

													cout<<"\nThere Must Be Register After MOVER on Line "<<linecount<<"\n";
													return 0;
												}
											}else{
												cout<<"\nThere Must Be Register After MOVER on Line "<<linecount<<"\n";
												return 0;
											}

											if(!isMnemonic(g1.at(i+2))){
												if(!isAd(g1.at(i+2))){
													if(!isReg(g1.at(i+2))){;
													}else{

														cout<<"\nThere Must Be Symbol Or Literal After Register in MOVER on Line "<<linecount<<"\n";
														return 0;
													}
												}else{

														cout<<"\nThere Must Be Symbol Or Literal After Register in MOVER on Line "<<linecount<<"\n";
														return 0;												
												}
											}else{

													cout<<"\nThere Must Be Symbol Or Literal After Register in MOVER on Line "<<linecount<<"\n";
													return 0;
											}
									

									}
								}
								else if(!g1.at(i).compare("MOVEM")){
									fout<<"(IS,05) | ";
									tout<<"(IS,05) | ";
									
										if(g1.size() >= 3){

											if(!isMnemonic(g1.at(i+1))){
												if(!isAd(g1.at(i+1))){
													if(isReg(g1.at(i+1))){;
													}else{

														cout<<"\nThere Must Be Register After MOVEM on Line "<<linecount<<"\n";
														return 0;
													}
												}else{

													cout<<"\nThere Must Be Register After MOVEM on Line "<<linecount<<"\n";
													return 0;
												}
											}else{
												cout<<"\nThere Must Be Register After MOVEM on Line "<<linecount<<"\n";
												return 0;
											}

											if(!isMnemonic(g1.at(i+2))){
												if(!isAd(g1.at(i+2))){
													if(!isReg(g1.at(i+2))){;
													}else{

														cout<<"\nThere Must Be Symbol Or Literal After Register in MOVEM on Line "<<linecount<<"\n";
														return 0;
													}
												}else{

														cout<<"\nThere Must Be Symbol Or Literal After Register in MOVEM on Line "<<linecount<<"\n";
														return 0;												
												}
											}else{

													cout<<"\nThere Must Be Symbol Or Literal After Register in MOVEM on Line "<<linecount<<"\n";
													return 0;
											}
									

									}

								}
								else if(!g1.at(i).compare("MULT")){
									fout<<"(IS,03) | ";
									tout<<"(IS,03) | ";
									
									if(g1.size() == 2){
									if(!isMnemonic(g1.at(i+1))){
										if(!isAd(g1.at(i))){
											if(isReg(g1.at(i+1))){

											}else{

												cout<<"\nThere Must Be Register AFTER MULT on Line "<<linecount<<"\n";
												return 0;	
											}
										}else{
											cout<<"\nThere Must Be Register AFTER MULT on Line "<<linecount<<"\n";
											return 0;	
										
										}
									}else{
										cout<<"\nThere Must Be Register AFTER MULT on Line "<<linecount<<"\n";
											return 0;	
										
									}	
								}
								}
								else if(!g1.at(i).compare("ADD")){
									fout<<"(IS,01) | ";
									tout<<"(IS,01) | ";
									
									if(g1.size() >= 3){
									if(!isMnemonic(g1.at(i+1))){
										if(!isAd(g1.at(i+1))){

										}else{

											cout<<"\nIllegal Use Of Assembler Directive on Line "<<linecount<<"\n";
											return 0;	
											
										}
									}else{

										cout<<"\nIllegal Use Of Mnemonic on Line "<<linecount<<"\n";
										return 0;	
										
									}


									if(!isMnemonic(g1.at(i+2))){
										if(!isAd(g1.at(i+2))){

										}else{

											cout<<"\nIllegal Use Of Assembler Directive on Line "<<linecount<<"\n";
											return 0;	
											
										}
									}else{

										cout<<"\nIllegal Use Of Mnemonic on Line "<<linecount<<"\n";
										return 0;	
										
									}

									
										
									}
								}
								else if(!g1.at(i).compare("COMP")){
									fout<<"(IS,06) | ";
									tout<<"(IS,06) | ";
									
									if(g1.size() >= 3){
										if(!isMnemonic(g1.at(i+1))){
											if(!isAd(g1.at(i+1))){
												if(isReg(g1.at(i+1))){

												}else{
													cout<<"\nThere Must Be Register Followed by COMP on Line "<<linecount<<"\n";
													return 0;
												}
											}else{

													cout<<"\nThere Must Be Register Followed by COMP on Line "<<linecount<<"\n";
													return 0;
											}
										}else{

													cout<<"\nThere Must Be Register Followed by COMP on Line "<<linecount<<"\n";
													return 0;
										}


										if(!isMnemonic(g1.at(i+2))){
											if(!isAd(g1.at(i+2))){

											}else{
												cout<<"\nIllegal Use Of Assembler Directive on Line "<<linecount<<"\n";
												return 0;	
													
											}
										}else{
											cout<<"\nIllegal Use Of Mnemonic on Line "<<linecount<<"\n";
											return 0;	
										
										}
									}	
								}
								else if(!g1.at(i).compare("BC")){
									fout<<"(IS,07) | ";
									tout<<"(IS,07) | ";	
								}
								else if(!g1.at(i).compare("PRINT")){
									
									fout<<"(IS,10) | ";
									tout<<"(IS,10) | ";
									
									if(g1.size() >=2 ||g1.size() <=3 ){
										if(!isMnemonic(g1.at(i+1))){
											if(!isAd(g1.at(i+1))){
												if(!isLiteral(g1.at(i+1))){

												}else{
													cout<<"\nIllegal Use Of Literal on Line "<<linecount<<"\n";
													return 0;
												}
											}else{
												
													cout<<"\nIllegal Use Of Assembler Directive on Line "<<linecount<<"\n";
													return 0;
											}
										}else{

												cout<<"\nIllegal Use Of Mnemonic on Line "<<linecount<<"\n";
												return 0;
										}
									}	
								}
								else if(!g1.at(i).compare("STOP")){
									fout<<"(IS,00) | ";
									tout<<"(IS,00) | ";
									
									if(g1.size() > 1){
										cout<<"\nThere Should be Nothing Followed or Precceded By STOP statement on line "<<linecount<<"\n";
										return 0;
									}
								}
								else if(!g1.at(i).compare("SUB")){
									fout<<"(IS,02) | ";
									tout<<"(IS,02) | ";
									
									if(g1.size() >= 3){
									if(!isMnemonic(g1.at(i+1))){
										if(!isAd(g1.at(i+1))){

										}else{

											cout<<"\nIllegal Use Of Assembler Directive on Line "<<linecount<<"\n";
											return 0;	
											
										}
									}else{

										cout<<"\nIllegal Use Of Mnemonic on Line "<<linecount<<"\n";
										return 0;	
										
									}


									if(!isMnemonic(g1.at(i+2))){
										if(!isAd(g1.at(i+2))){

										}else{

											cout<<"\nIllegal Use Of Assembler Directive on Line "<<linecount<<"\n";
											return 0;	
											
										}
									}else{

										cout<<"\nIllegal Use Of Mnemonic on Line "<<linecount<<"\n";
										return 0;	
										
									}
								}
	
								}
								else if(!g1.at(i).compare("STORE")){
									fout<<"(IS,11) | ";
									tout<<"(IS,11) | ";	
								}
								else {
									fout<<"(IS,12) | ";
									tout<<"(IS,12) | ";	
								}
								break;
							}else{
								continue;
							}							
						}
						 if(isSymbol){
						 		
						 	if(isReg(g1.at(i)) || !g1.at(i).compare("BC")){	
 							 	if(!g1.at(i).compare("AREG")){
 										fout<<"(1)";
 										tout<<"AREG , ";	
 								}
 								else if(!g1.at(i).compare("BREG")){
 										fout<<"(2)";
 										tout<<"BREG , ";	
 								}
 								else if(!g1.at(i).compare("CREG")){
 										fout<<"(3)";
 										tout<<"CREG , ";	
 								}
 								else if(!g1.at(i).compare("DREG")){
 										fout<<"(4)";
 										tout<<"DREG , ";	
 								}
 								else if(!g1.at(i+1).compare("LT")){
 										fout<<"(1)";
 										tout<<"LT ," ;	
 								}
 								else if(!g1.at(i+1).compare("LE")){
 										fout<<"(2)";
 										tout<<"LE ,";	
 								}
 								else if(!g1.at(i+1).compare("EQ")){
 										fout<<"(3)";
 										tout<<"EQ , ";	
 								}
 								else if(!g1.at(i+1).compare("GT")){
 										fout<<"(4)";
 										tout<<"GT ,";	
 								}
 								else if(!g1.at(i+1).compare("GE")){
 										fout<<"(5)";
 										tout<<"GE ,";	
 								}
 								else{
 										fout<<"(6)";
 										tout<<"ANY , ";	
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
								 			tout<<symbolTable[symcount].symbol;
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
										tout<<symbolTable[count].symbol;
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
							if(g1.size() == 2 && isNumber(g1.at(1)) && !g1.at(0).compare("START") && linecount == 1){
								LC = stringToI(g1.at(1));
							}else{
								
								if(g1.size() == 3 && !g1.at(0).compare("START")){
									cout<<"\nThere Is An Extra Symbol On Line "<<linecount;
									return 0;
								}else{
									if(!g1.at(0).compare("START")){
										cout<<"\nThere Should Be Number After START On Line "<<linecount<<"\n";
										return 0;
									}
								}
							}

							if(isNumber(g1.at(i))){
									if(!endflg){
										fout<<"(C,"<<g1.at(i)<<")";
										tout<<"(C,"<<g1.at(i)<<")";
										
									}
								
							}
							if(isLiteral(g1.at(i))){
								pool.push_back(g1.at(i));								
								
							}
							if(isLiteral(g1.at(i)) && !isLiteralPresent(g1.at(i),litcnt)){
								fout<<"(L,0"<<litcnt+1<<")";
								tout<<"(L,0"<<litcnt+1<<")";
							}


						 }

						isSymbol = 1;
					}
					g1.clear();
						
					fout<<"\n";
					tout<<"\n";
				  }
				
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