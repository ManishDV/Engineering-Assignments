//============================================================================
// Name        : Assign9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test_Hash{
	unsigned long int mobile;
	string name;
	int link;

public:
	Test_Hash(){
		mobile = 0;
		name = " ";
		link = -1;
	}

	void createTableForWithReplacement(Test_Hash *ts1[30],int *size)
	{
		cout<<"\nEnter The Table Size: ";
		cin>>*size;

		for(int i = 0;i<*size;i++)
		{
			ts1[i] = new Test_Hash;
		}

	}

	void display(Test_Hash *ts1[30],int size)
	{

		cout<<"\n------------------------------------------------------------";
		cout<<"\nSr.No\t\tMobile Number\t\tName\t\tLink";
		cout<<"\n------------------------------------------------------------";

		for(int i=0;i<size;i++)
		{
			cout<<"\n"<<i<<"\t\t"<<ts1[i]->mobile<<"\t\t"<<ts1[i]->name<<"\t\t\t"<<ts1[i]->link;
			cout<<"\n-------------------------------------------------------------";
		}
	}

	void insert(Test_Hash *ts1[30],int size)
	{
		unsigned long int mobile;
		int link;
		string name;
		int flag = 0;
		do{
			cout<<"\nEnter Mobile Number: ";
			cin>>mobile;
			if(mobile >= 1000000000 && mobile <= 9999999999)
			{
				flag = 1;
			}
			else
			{
				cout<<"\n\nMobile Number Should Be 10 Digit long";
				flag = 0;
			}

		}while(!flag);

		cout<<"\nEnter Name: ";
		cin>>name;

		int key = mobile % size;
	}


};



int main() {

	int choice = 0,choice1 = 0,choice2 = 0;
	Test_Hash ts,*ts1[30],*ts2[30];

	int size1 = 0;
	do
		{
			cout<<"\n-------------- MENU ----------------";
			cout<<"\n1. WITH REPLACEMENT";
			cout<<"\n2. WITHOUT REPLACEMENT";
			cout<<"\n3. EXIT";
			cout<<"\n------------------------------------";

			cout<<"\nEnter Your Choice: ";
			cin>>choice;

			switch(choice)
			{
				case 1:
							do{
								cout<<"\n-------------- WITH REPLACEMENT ----------------";
								cout<<"\n1. CREATE HASH TABLE";
								cout<<"\n2. INSERT RECORD";
								cout<<"\n3. DISPLAY RECORD";
								cout<<"\n4. SEARCH RECORD";
								cout<<"\n5. EXIT";
								cout<<"\n------------------------------------";

								cout<<"\nEnter Your Choice: ";
								cin>>choice1;

								switch(choice1)
								{
								case 1:
									ts.createTableForWithReplacement(ts1,&size1);
									break;
								case 2:
									if(size1 == 0)
									{
										cout<<"\nTable Is Not Created";
									}
									else{
										ts.insert(ts1,size1);
									}
									break;
								case 3:
									ts.display(ts1,size1);
									break;
								case 4:
									break;
								case 5:
									break;
								}
							}while(choice1 != 5);
						break;
				case 2:
					do{
						cout<<"\n-------------- WITHOUT REPLACEMENT ----------------";
						cout<<"\n1. CREATE HASH TABLE";
						cout<<"\n2. INSERT RECORD";
						cout<<"\n3. DISPLAY RECORD";
						cout<<"\n4. SEARCH RECORD";
						cout<<"\n5. EXIT";
						cout<<"\n------------------------------------";

						cout<<"\nEnter Your Choice: ";
						cin>>choice1;

						switch(choice1)
						{
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						}
					}while(choice1 != 5);

					    break;
				case 3:
						return 0;
				default:
						cout<<"\n\nPlease Enter Valid Choice";

			}

		}while(choice != 3);

}
