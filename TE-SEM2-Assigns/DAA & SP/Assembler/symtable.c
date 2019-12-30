#include <stdio.h>
#include <string.h>


int main(int argc,char const*argv[]){
	FILE *filePointer; 
	filePointer = fopen("file.txt","r");
	char ch;
	char ad[][21] = {"EQU","ORG","DS","INCLUDE","LTORG","END","START"};
	char IS[][21] = {"READ","PRINT","MOVER","ADD","MOVEM","STOP"};
	char reg[][6] = {"AREG","BREG","CREG","DREG"};

	int adSize = sizeof(ad)/sizeof(ad[0]);
	int isSize = sizeof(IS)/sizeof(IS[0]);
	int i = 0;
	int k = 0;
	char word[10];
	char *splits[10];	 
	while ((ch = fgetc(filePointer)) != EOF)
    {
    	if(ch == ' ' || ch == ',' || ch == '\n'){
    		word[i] = '\0';
    		splits[k] = word;

    		printf("%s\n",splits[k]);
    		k++;
    		// printf("%d\n",k);
    		if(ch == '\n'){
    			
    			splits[k] = "EMPTY";
    			k = 0;
    			printf("\n");
    			// int splitSize = sizeof(splits)/ sizeof(splits[0]);
    			// for(int j=0;strcmp(splits[j],"EMPTY") != 0;j++){
    			// 	printf("%s\t",*(splits+j));
    			// }

    			printf("%s\t%s",splits[0],splits[1] );


    		}
    		word[0] = '\0';
    		i = 0;
    	}else{
    		word[i] = ch;
    		i++;
    	}
    }
	// string ad[] ={"EQU","ORG","DS","INCLUDE","LTORG","END","START"};
	// string IS[] ={"READ","PRINT","MOVER","ADD","MOVEM","STOP"};
	// string reg[] ={"AREG","BREG","CREG","DREG"};
	// string word;
	// vector<string> g1;
	// int adSize = sizeof(ad) / sizeof(ad[0]);
	// int isSize = sizeof(IS) / sizeof(IS[0]);
	

	// std::vector<string> directives;

	// std::vector<string> imperative;

	// int i=0;
	// int k = 0;
	// if(!fin){
	//    cout<<"\nFILE DOES NOT EXISTS";	
	// }else{
	//    while(!fin.eof()){
	// 		fin.get(ch);
	// 		if(ch == ' ' || ch == ',' || ch == '\n'){
	// 			g1.push_back(word);
	// 			if(ch == '\n'){

	// 				for(int i=0;i<g1.size();i++){
	// 					for(int j = 0;j<adSize;j++){

	// 						if(g1.at(i).compare(ad[j]) == 0){
	// 							directives.push_back(ad[j]);
	// 							break;
	// 						}else{
	// 							continue;
	// 						}

	// 					}

	// 					for(int j=0;j<isSize;j++){
	// 						if(g1.at(i).compare(IS[j]) == 0){
	// 							imperative.push_back(IS[j]);
	// 							break;
	// 						}else{
	// 							continue;
	// 						}							
	// 					}	
	// 				}

	// 				g1.clear();
				
	// 			}
	// 			word = "";

	// 		}else{
	// 			word+=ch;
	// 		}
			
						
	// 	}
			 		
	// }
	
	// cout<<"\n------------------------------------------------";
	// cout<<"\n\tASSEMBLER DIRECTIVES IN GIVEN FILE";
	// cout<<"\n------------------------------------------------";
	// for (int i = 0; i < directives.size(); ++i)
	// {
	// 	cout<<"\n\t"<<i+1<<". "<<directives.at(i);
	// }

	// cout<<"\n------------------------------------------------";
	// cout<<"\n\tIMPERATIVE STATEMENT IN GIVEN FILE";
	// cout<<"\n------------------------------------------------";
	// for (int i = 0; i < imperative.size(); ++i)
	// {
	// 	cout<<"\n\t"<<i+1<<". "<<imperative.at(i);

	// }


	printf("\n");	
}
