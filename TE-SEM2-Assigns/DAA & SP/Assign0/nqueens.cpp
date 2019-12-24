#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;


void initializeChessBoard(int *chess,int n){
	for(int i=0;i<n;i++){
 		for(int j = 0;j<n;j++){
 			*(chess+i*n+j) = 0;
 		}
 	}

}

void printChess(int *chess,int n){

	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<"  "<<*(chess+i*n+j);
		}
		cout<<"\n";
	}
}

int isSafe(int *chess,int row,int col,int n){

	for(int i=row;i<n;i++){
		if(*(chess+i*n+col) ==1){
			return 0;
		}
	}

	for(int i=row,j=col;i>=0&&j>=0;i--,j--){
		if(*(chess+i*n+j) ==1){
			return 0;
		}
	}

	for(int i=0,j=col;j>=0&&i<n;i++,j--){
		if(*(chess+i*n+j) ==1){
			return 0;
		}
	}
	
	return 1;
}

int placeQueens(int *chess,int col,int n){
	if(col >= n){
		return 1;
	}

	for(int i =0 ;i<n;i++){
		if(isSafe(chess,i,col,n)){
			*(chess+i*n+col) = 1;
		}

		if(placeQueens(chess,col+1,n)){
			return 1;
		}

		*(chess+i*n+col) = 0;
		
	}
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
 	
 	placeQueens(chess,0,n);

 	printChess(chess,n);
	
 	cout<<"\n";
 	return 0;
}
