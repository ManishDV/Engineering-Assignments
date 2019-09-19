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

	void createTable(Test_Hash *ts1[30],unsigned int *size)
	{
		cout<<"\nEnter The Table Size: ";
		cin>>*size;

		for(unsigned int i = 0;i<*size;i++)
		{
			ts1[i] = new Test_Hash;
		}

	}

	void display(Test_Hash *ts1[30],unsigned int size)
	{

		cout<<"\n------------------------------------------------------------";
		cout<<"\nSr.No\t\tMobile Number\t\tName\t\tLink";
		cout<<"\n------------------------------------------------------------";

		for(unsigned int i=0;i<size;i++)
		{
			cout<<"\n"<<i<<"\t\t"<<ts1[i]->mobile<<"\t\t"<<ts1[i]->name<<"\t\t"<<ts1[i]->link;
			cout<<"\n-------------------------------------------------------------";
		}
	}

	void insertReplace(Test_Hash *ts1[30],unsigned int size)
	{
		unsigned long int mobile;

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

		unsigned int key = mobile % size;
		flag = 0;
		if(ts1[key]->mobile == 0)
		{
			ts1[key]->mobile = mobile;
			ts1[key]->name = name;
			ts1[key]->link = -1;
			cout<<"\nInsertion Successful";
		}
		else
		{
//			if(ts1[key]->mobile != 0 && ts1[key]->mobile % size != key)
//			{
//				Test_Hash *test = new Test_Hash;
//
//				test->mobile = ts1[key]->mobile;
//				test->name = ts1[key]->name;
//
//				ts1[key]->mobile = mobile;
//				ts1[key]->name = name;
//				ts1[key]->link = -1;
//
//				while(ts1[key]->mobile != 0)
//				{
//					key++;
//					if(key == size)
//					{
//						key = 0;
//					}
//				}
//				ts1[key]->mobile = test->mobile;
//				ts1[key]->name = test->name;
//				ts1[key]->link = -1;
//
//
//				int dummyKey = test->mobile % size;
//				ts1[dummyKey]->link = key;
//				do{
//					if(ts1[dummyKey]->link == -1)
//					{
//						ts1[dummyKey]->link = -1;
//						flag = 1;
//					}
//
//					else
//					{
//
//						dummyKey = ts1[dummyKey]->link;
//					}
//				}while(!flag);
//
//				cout<<"\nInsertion Successful";
//			}
			if(ts1[mobile%size]->mobile != 0 && ts1[mobile%size]->link != -1)
			{
				unsigned int fake = ts1[mobile%size]->mobile % size;
				unsigned int j = 0;
				for(j = 0;j<size;j++)
				{
					if(ts1[j]->mobile % size == fake && ts1[ts1[j]->link]->mobile == ts1[mobile % size]->mobile){
						break;
					}
				}

				cout<<"\nKey: "<<j;
				Test_Hash *test = new Test_Hash;
				test->mobile = ts1[mobile%size]->mobile;
				test->name = ts1[mobile%size]->name;
				test->link = ts1[mobile%size]->link;

				ts1[mobile%size]->mobile = mobile;
				ts1[mobile%size]->name = name;
				ts1[mobile%size]->link = -1;

				while(ts1[key]->mobile != 0)
				{
					key++;
					if(key == size)
					{
						key = 0;
					}
				}

				ts1[key]->mobile = test->mobile;
				ts1[key]->name = test->name;
				ts1[key]->link = -1;


				ts1[j]->link = test->link;

				while(ts1[j]->link != -1)
					j = ts1[j]->link;

				ts1[j]->link = key;
			}
			else
			{


				int dummyKey = ts1[key]->mobile % size;
				key++;
				while(ts1[key]->mobile != 0)
				{
					key++;
					if(key == size)
					{
						key = 0;

					}

				}
				ts1[key]->mobile = mobile;
				ts1[key]->name = name;
				ts1[key]->link = -1;

				cout<<"\nInsertion Successful";
				do{
					if(ts1[dummyKey]->link == -1)
					{
						ts1[dummyKey]->link = key;
						flag = 1;
					}

					else
					{
						dummyKey = ts1[dummyKey]->link;
					}
				}while(!flag);
			}
		}

	}

	void displaySingle(Test_Hash *ts1)
	{
		cout<<"\n------------------------------------------------------------";
		cout<<"\nMobile Number\t\tName";
		cout<<"\n------------------------------------------------------------";
		cout<<"\n"<<ts1->mobile<<"\t\t"<<ts1->name;
		cout<<"\n-------------------------------------------------------------";

	}
	void search(Test_Hash *ts1[30],int size)
	{
		unsigned long int mobile;
		cout<<"\n\nEnter The Number You Want To Search: ";
		cin>>mobile;
		int flag = 0;
		int key = mobile % size;

		do{
			if(ts1[key]->mobile == mobile)
			{
				displaySingle(ts1[key]);
				flag = 1;
			}
			else if(ts1[key]->link == -1)
			{
				cout<<"\n\nRecord of Mobile Number "<<mobile<<" is Not Present. ";
				flag = 1;
			}
			else
			{
				key = ts1[key]->link;
			}
		}while(!flag);
	}


	void insertWithoutReplacement(Test_Hash *ts1[30],unsigned int size)
	{
		unsigned long int mobile;

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

			unsigned int key = mobile % size;
			flag = 0;

			if(ts1[key]->mobile == 0)
			{
				ts1[key]->mobile = mobile;
				ts1[key]->name = name;
				ts1[key]->link = -1;
				cout<<"\nInsertion Successful";
			}
			else
			{
				if(ts1[key]->mobile != 0)
				{
					Test_Hash *test = new Test_Hash;
					test->link = ts1[key]->link;
					test->mobile = ts1[key]->mobile;
					test->name = ts1[key]->name;

//					cout<<"Link: "<<test->link;
					while(ts1[key]->mobile != 0)
					{
						key++;
						if(key == size)
						{
							key = 0;
						}
					}

					ts1[key]->mobile = mobile;
					ts1[key]->name = name;
					ts1[key]->link = -1;


					unsigned int dummyKey = test->mobile % size;
					unsigned int dupKey = mobile % size;
					int count = 0;
					unsigned int  i = 0,first = 0,counter = 1;
					for(i=0;i<size;i++){
						if(ts1[i]->mobile % size == dupKey)
						{
							count++;

							if(counter)
							{
								first = i;
								counter--;
							}
						}

					}

					while(1){
						if(ts1[first]->link == -1)
						{
							if(count == 1)
								ts1[first]->link = -1;
							else
								ts1[first]->link = key;
								break;
						}else{
							first = ts1[first]->link;
						}
					}


				}
			}

	}
};



int main() {

	int choice = 0,choice1 = 0,choice2 = 0;
	Test_Hash ts,*ts1[30],*ts2[30];

	unsigned int size1 = 0,size2 = 0;
	do
		{
			cout<<"\n\n-------------- MENU ----------------";
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
									ts.createTable(ts1,&size1);
									break;
								case 2:
									if(size1 == 0)
									{
										cout<<"\nTable Is Not Created";
									}
									else{
										ts.insertReplace(ts1,size1);
									}
									break;
								case 3:
									if(size1 == 0)
									{
										cout<<"\nTable Is Not Created";
									}
									else{

											ts.display(ts1,size1);
									}
									break;
								case 4:
									if(size1 == 0)
									{
										cout<<"\nTable Is Not Created";
									}
									else{

											ts.search(ts1,size1);
									}
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
						cin>>choice2;

						switch(choice2)
						{
						case 1:
							ts.createTable(ts2,&size2);
							break;
						case 2:
							if(size2 == 0)
							{
								cout<<"\nTable Is Not Created";
							}
							else{
								ts.insertWithoutReplacement(ts2,size2);
							}
							break;
						case 3:
							if(size2 == 0)
							{
								cout<<"\nTable Is Not Created";
							}
							else{

								ts.display(ts2,size2);
							}
							break;
						case 4:
							if(size2 == 0)
							{
								cout<<"\nTable Is Not Created";
							}
							else{

									ts.search(ts2,size2);
							}

							break;
						case 5:
							break;
						}
					}while(choice2 != 5);

					    break;
				case 3:
						return 0;
				default:
						cout<<"\n\nPlease Enter Valid Choice";

			}

}while(choice != 3);
return 0;
}
