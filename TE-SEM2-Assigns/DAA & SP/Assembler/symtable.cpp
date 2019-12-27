#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector> 
using namespace std;


int main(int argc,char const*argv[]){
	ifstream fin;
	fin.open("/home/oslab-17/Desktop/33370/Assembler/file.txt", ios::in);
	char ch;
	string keys[] ={"START","READ","MOVER","ADD","MOVEM","PRINT","STOP","DS","DC","LTORG","ORIGIN"};
	string word;
	int size = sizeof(keys)/sizeof(keys[0]);
	vector<string> g1;
	
	int i=0;
	int k = 0;
	if(fin == NULL){
	   cout<<"\nFILE DOES NOT EXISTS";	
	}else{
	   while(!fin.eof()){
			fin.get(ch);
			if(ch == ' ' || ch == ','){
				g1.insert(g1.begin()+i,word);
				word = "";
				i++;
				
			}else if(ch == '\n'){
				
				
				cout<<"\nSplits Length: "<<g1.size();
				for(int k=0;k<g1.size();k++){
				   cout<<g1.at(k)<<"\t";	
				}
				//for(int j=0;j<size;j++){
				//	if(!(splits[0].compare(keys[j]))){
				//	     cout<<splits[0];
				//	}
				//}
				i=0;
			}else{
				cout<<"\n";
				word+=ch;
			}
			
						
		}
			 		
	}
	
	
	
	cout<<"\n";
	
}
