#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector> 
#include <cmath>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = "S";
	string s1 = "S";
	
	if(!s.compare(s1)){
		cout<<"\n\nEQUAL";
	}else{
		cout<<"\n\nUNEQUAL";
	}
	return 0;
}