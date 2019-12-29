
#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int s =0;

void initializeChessBoard(int *chess,int n){
	for(int i=0;i<n;i++){
 		for(int j = 0;j<n;j++){
 			*(chess+i*n+j) = 0;
 		}
 	}

}

void printChess(int *chess,int n){
	cout<<"\n";
	for(int i=0;i<n;i++){
		cout<<"\t";
		for(int j = 0;j<n;j++){
			
			if(*(chess+i*n+j)){
			   cout<<" Q ";	
			}else{
			   cout<<" - ";	
			}
		}
		cout<<"\n";
	}
}

int canPlace(int *chess,int row,int col,int n){
	int i,j;
	for(i=0;i<col;i++){
		if(*(chess+row*n+i) == 1){
			return 0;
		}
	}

	for(i=row,j=col;i>=0 && j>=0;i--,j--){
		if(*(chess+i*n+j)){
			return 0;
		}
	}

	for(i=row,j=col;j>=0 && i<n;j--,i++){
		if(*(chess+i*n+j)){
			return 0;
		}
	}
	
	return 1;
}

int placeQueens(int *chess,int col,int n){
	int flag = 0;
	if(col >= n){
		cout<<"\n\nSolution: "<<s+1;
		s = s+1;
		printChess(chess,n);
	}

	for(int i =0 ;i<n;i++){
		if(canPlace(chess,i,col,n)){
			*(chess+i*n+col) = 1;
		}else{
			continue;	
		}
		
		if(placeQueens(chess,col+1,n)){

			return 1;
		}
		
		
		*(chess+i*n+col) = 0;
		
	}
	return 0;
}

int main(int argc, char const *argv[])
{
 	int n;
 	cout<<"\nEnter Number Of Queens: ";
 	cin>>n;
 	cout<<"\n";

 	int *chess;

 	chess = new int[n*n];
 	
 	initializeChessBoard(chess,n);
 	
 	
 	if(placeQueens(chess,0,n)){
 	
 		cout<<"\n\tSolution Found\n";
 	}else{
 		exit(0);
 	}
	
		
 	printChess(chess,n);
	
 	cout<<"\n";
 	return 0;
}
