//============================================================================
// Name        : Assign2.cpp
// Author      : Manish Visave (23366)
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Queue.cpp"
#include "Queue.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>
using namespace std;



class HospitalManagement
{
	int id;
	char  name[30],phone[11],disease[20];
	int priority;

public:
	void getData(Queue <HospitalManagement>q,int *status);
	HospitalManagement serve();
	void setPriority();
	void display(Queue <HospitalManagement>q);
	void displaySingle();

	int getPriority()
	{
		return priority;
	}

	bool validID(Queue <HospitalManagement>q);
	bool validPhone();
};


bool HospitalManagement:: validID(Queue <HospitalManagement>q)
{
	int count = q.NodeCount();
	HospitalManagement *pt = new HospitalManagement[count];

	pt = q.display();

	for(int i=0;i<count;i++)
	{
		if(id == pt->id)
		{

			return false;
		}
		pt++;
	}

	return true;

}

bool HospitalManagement:: validPhone()
{
	if(strlen(phone) == 10)
	{
		for(int i=0;i<10;i++)
		{
			if(!isdigit(phone[i]))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

 return true;

}


void HospitalManagement::getData(Queue <HospitalManagement>q,int *status)
{

	cout<<"\n-------------------------";
	cout<<"\nEnter Patient's ID: ";
	cin>>id;

	if(validID(q))
	{
		cout<<"\nEnter Patient's Name: ";
		cin>>name;

		cout<<"\nEnter Patient's Phone Number: ";
		cin>>phone;
		if(validPhone())
		{
			cout<<"\nSelect Disease: ";
			setPriority();
		}
		else
		{
			cout<<"\nPlease Enter Valid Phone Number.";
			*status = 0;
		}

	}
	else
	{

		cout<<"\nPatient With similar ID already Exists";
		*status = 0;
	}
}
void HospitalManagement::displaySingle()
{
	cout<<"\n----------------------------------------------------------------------";
	cout<<"\nID\tNAME\t\tCONTACT DETAILS\t\tDISEASE";
	cout<<"\n----------------------------------------------------------------------";

	cout<<"\n"<<id<<"\t"<<name<<"\t\t"<<setw(13)<<phone<<"\t"<<setw(18)<<disease;
	cout<<"\n----------------------------------------------------------------------";

}

void HospitalManagement::setPriority()
{

	int choice;
	do{
		cout<<"\n\n1.Heart Attack\t\t2.Cancer\t\t3.Malaria\n4.Bone Fracture\t\t5.Flue and Cold\t\t6.Others.";
			cout<<"\n\nEnter Choice Code: ";
			cin>>choice;


			switch(choice)
			{
				case 1:
						strcpy(disease,"Heart Attack");
						priority = 6;
						break;
				case 2:
						strcpy(disease, "Cancer");
						priority = 5;
						break;
						//return 5;
				case 3:
						strcpy(disease, "Malaria");
						priority = 4;
						break;
						//return 4;
				case 4:
						strcpy(disease, "Bone Fracture");
						priority = 3;
						break;
						//return 3;
				case 5:
						strcpy(disease, "Flue and Cold");
						priority = 2;
						break;
						//return 2;
				case 6:
						strcpy(disease, "Others");
						priority = 1;
						break;
						//return 1;
				default:
					cout<<"\nPlease Select Correct Choice: ";
			}


	}while(choice >=7);
				//return -1;
}

void HospitalManagement::display(Queue<HospitalManagement> q)
{

	int count = q.NodeCount();
	HospitalManagement *pt = new HospitalManagement[count];


	pt = q.display();

	cout<<"\n----------------------------------------------------------------------";
	cout<<"\nID\tNAME\t\tCONTACT DETAILS\t\tDISEASE";
	cout<<"\n----------------------------------------------------------------------";

	for(int i=0;i<count;i++)
	{

		cout<<"\n"<<pt->id<<"\t"<<pt->name<<"\t\t"<<setw(13)<<pt->phone<<"\t"<<setw(18)<<pt->disease;
		cout<<"\n----------------------------------------------------------------------";
		pt++;
	}

}

int main()
{
	HospitalManagement hp;
	int choice,status=1;
	Queue <HospitalManagement>q;


	do{

		cout<<"\n\n----------- MENU -------------";
		cout<<"\n1.ADD PATIENT DETAILS.\n2.DISPLAY PATIENT RECORDS.\n3.DISPLAY SERVED PATIENT.\n4.EXIT";
		cout<<"\n-------------------------------";
		cout<<"\nEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
					hp.getData(q,&status);

					if(status)
					{
						q.enQueue(hp,hp.getPriority());

						cout<<"\nRECORD IS ADDED.";

					}
					break;
			case 2:
					if(q.isEmpty()){
						cout<<"\nNO Records To Display";
					}
					else
					{
						hp.display(q);
					}
					break;
			case 3:
					if(q.isEmpty()){
						cout<<"\nNO Patient To Serve ";
					}
					else{
						hp = q.deQueue();
						hp.displaySingle();
					}
					break;
			case 4:
					return 0;
			default:
					cout<<"\nPlease Enter The Valid Choice.";
		}
	}while(choice != 4);




	return 0;
}
