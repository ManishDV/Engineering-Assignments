//============================================================================
// Name        : Assign2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "queueADT.cpp"
#include "queueADT.h"
using namespace std;


class Hospital_Management{
	queueADT<Hospital_Management>q;
	char Name[40],Phone[11],disease[40];
	int priority;
public:


	void setPriority(){
		int choice = 0;
		cout<<"\nSelect The Disease From Below List: ";
		cout<<"\n\n1.Heart Attack";
		cout<<"\n2.Cancer ";
		cout<<"\n3.Maleria ";
		cout<<"\n4.Flue_Cold ";
		cout<<"\n\nEnter Choice: ";
		cin>>choice;
		bool flag = false;
		while(!flag)
		{
			if(choice == 1){
				strcpy(disease,"Heart Attack");
				priority = 5;
				flag = true;
			}else if(choice == 2){
				strcpy(disease,"Cancer");
				priority = 4;
				flag = true;
			}else if(choice == 3){
				strcpy(disease,"Maleria");
				priority = 3;
				flag = true;
			}else if(choice == 4){
				strcpy(disease,"Flue_Cold ");
				priority = 2;
				flag = true;
			}else{
				cout<<"\nPlease Enter Valid Choice";
				flag = false;
			}

		}

	}

	void getData(){
			cout<<"\nEnter Name Of Patient: ";
			cin>>Name;

			cout<<"\nEnter Contact Number Of Patient: ";
			cin>>Phone;

			setPriority();

	}

	void addPatient(){
		getData();
		q.enqueue(*this, this->priority);
	}

	int getPriority(){
		return priority;
	}


	void display(){

		if(q.isEmpty())
			cout<<"\nNo Records To Display";
		else{
			int count = q.nodeCount();
			cout<<"\nCOUNT: "<<count;
			Hospital_Management *list = new Hospital_Management[count];
			list = q.display();
			cout<<"\n-------------------------------------------------------------------";
			cout<<"\nName\t\tPhone Number\t\tDisease";
			cout<<"\n-------------------------------------------------------------------";
			for(int i = 0;i<count;i++){
				cout<<"\n"<<list->Name<<"\t\t"<<list->Phone<<"\t\t"<<list->disease;
				cout<<"\n---------------------------------------------------------------";
				list++;
			}
		}
	}


	void servePatient(){
		Hospital_Management data = q.dequeue();
		cout<<"\n-------------------------------------------------------------------";
		cout<<"\nName\t\tPhone Number\t\tDisease";
		cout<<"\n-------------------------------------------------------------------";
		cout<<"\n"<<data.Name<<"\t\t"<<data.Phone<<"\t\t"<<data.disease;
		cout<<"\n---------------------------------------------------------------";


	}
};
int main() {

	Hospital_Management hp;
	int choice;


	do{

		cout<<"\n\n----------- MENU -------------";
		cout<<"\n1.ADD PATIENT DETAILS.\n2.DISPLAY PATIENT RECORDS.\n3.DISPLAY SERVED PATIENT.\n4.EXIT";
		cout<<"\n-------------------------------";
		cout<<"\nEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
					hp.addPatient();
					break;
			case 2:
					hp.display();
					break;
			case 3:
					hp.servePatient();
					break;
			case 4:
					return 0;
			default:
					cout<<"\nPlease Enter The Valid Choice.";
		}
	}while(choice != 4);




	return 0;
}

