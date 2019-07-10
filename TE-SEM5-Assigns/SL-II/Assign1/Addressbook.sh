#!/bin/bash
#Defining Function for Printing Blank Lines on Terminal
space(){

	echo
	echo
}

#Function to Print Line On Terminal
line(){
	
	echo "--------------------------------------------------------------------------------------------------------------------------------------------"
		
}

#Funtion To Add Record in Database
add_record(){
	space 
	read -p 'Enter Total Records You Want To Add: ' no #Taking User Input For Number Of Records
	i=0 #Counter For Controlling While Loop
	flag=0
	re='^[0-9]+$' #defining Regular Expression

	while [ "$i" -lt "$no" ]
	do	
		space
		echo "---------------------------------------------"

		read -p 'Enter Name: ' name #Reading Name 
	
	
		while [ "$flag" -eq 0 ]; do
			flag=0	
			echo
        		read -p 'Enter Phone Number: ' phone #Reading Phone Number
	
        		if [ ${#phone} -ne 10 ] || ! [[ $phone =~ $re ]]; then #Checking if Phone Number length is 10 or not or Phone Number Contains Any Character
					echo            			
					echo "Enter Valid Phone Number" #Printing Error Message if Above Condition is true
					flag=0
				else 
					flag=1
					break;	
            	fi
			done
					 
		flag=0
		echo
		read -p 'Enter Address(Flat No/Building): ' apts #Reading Address
	
		echo
		read -p 'Enter Locality: ' loc #Reading Address
	
		echo
		read -p 'Enter City Name: ' city #Reading City
	
		
		while [ "$flag" -eq 0 ]
		do	
			echo
			read -p 'Enter Pin Number: ' pin #Reading Pin Code Number
	
			if [ ${#pin} -ne 6 ] || ! [[ $pin =~ $re ]]; then #Checking If the Pin Code length is 6 or not or if Pin Code Number Contains Characters
					echo            			
					echo "Enter Valid Pin Code Number" #Printing Error Message If Pin Code Is Invalid
					flag=0
				else 
					flag=1
					break;	
            	fi
		done
		
		
		initial="$(echo $name | head -c 1)" #taking Initial letter of Name To Create ID

		RANDOM="$(shuf -i 1-1000 -n 1)" #generating Random Number For ID
		
		id="$initial$RANDOM" #Concatinating Initial letter and Random Number to generate unique id
		echo "$id\t\t$name\t\t$phone\t\t$apts\t\t$loc\t\t$city\t\t$pin">>address.dat #Writing record In file Using Redirection
	
	 	i=$((i+1)) #incrementing The Counter
	done
	return
	
	#End Of Add Record Function
}

#Defining Function To Display Record Id wise
display(){

	if [ -s "address.dat" ] #checking if file is empty or exists or not
	then 
   		echo -e "\n\t\t\tRECORDS BY ID" 
		line 
		echo -e "\n ID\t\t NAME\t\t\tPHONE NUMBER\t\t\tApartment\t\tLocality\t\tCity\t\tPin Code"
		line
		echo -e "$(cat address.dat)" # Command for Displaying Record
		line	
	else
   		echo -e "\nfile does not exist, or is empty " #printing Error Message if File Doesn't Exists ot is empty
	fi	
	return 	
	
	#End Of Display Function
}

#defining Function to Display Record Name Wise
display_name(){

	if [ -s "address.dat" ] #checking if file is empty or exists or not
	then 

		echo -e "\n\t\t\tRECORDS BY NAME\n\n"
		line
		echo -e "\n ID\t\t NAME\t\t\tPHONE NUMBER\t\t\tApartment\t\tLocality\t\tCity\t\tPin Code"
		line
		echo -e "$(cat address.dat | sort -n -t ' ' -k 2,2 -k 3,3)" #Displaying Record In Sorted order
		line	
	else
   		echo -e "\nfile does not exist, or is empty " #printing Error Message if File Doesn't Exists ot is empty
	fi	
	return 
		
		#End Of Function
}

#Defining Function For Search By Id	
search(){
	echo	
	read -p 'Enter ID To Be Searched: ' ID #Taking ID To Search In File

	fileName="address.dat" 

	if grep -q "$ID" "$fileName"; #Checking If Record With Entered Id Is Present Or Not In file 
	then
		line
		echo -e "\n ID\t\t NAME\t\t\tPHONE NUMBER\t\t\tApartment\t\tLocality\t\tCity\t\tPin Code"
		echo
		line
		echo -e "\n$(grep -F $ID address.dat)" #Printing Record If Exists
		line
	else
		echo -e "\nNo Record Present With Id $ID" #Printing Error Message If Record Is Not Present in File	 
		
	fi	
	return
	
	#End Of Function
}

#Defining Function For Searching Records Name wise 	
search_name(){
	echo
        read -p 'Enter Name To Be Searched: ' name #Reading Name To Be Searched
	fileName="address.dat"

	if grep -q "$name" "$fileName";  #Checking if Record Present Or Not In File
	then
		line	
		echo -e "\n ID\t\t NAME\t\t\tPHONE NUMBER\t\t\tApartment\t\tLocality\t\tCity\t\tPin Code"
		echo
		line
		echo -e "\n$(grep -F $name address.dat)" #Displaying Records If Present
		line
	else
		echo -e "\nNo Record Present With Name $name"	#Printing Error Message If No Record Present
		
	fi	
	return
}

#Defining Function For Deleting Record ID wise
delete(){
		echo
	        read -p 'Enter ID To Be Deleted: ' rno #Reading ID whose Record to be deleted
		fileName="address.dat"
		lineNum="$(grep -n "$rno" "$fileName" | head -n 1 | cut -d" "  -f1)" #getting Line Number of Record
		
		line=${lineNum%:*}	#Seperating Line Number above query o/p=line:ID extracting line	
		#echo "$(>temp.dat)"
		
		if grep -q "$rno" "$fileName"; #Checking If Record Is Present With Id Or Not
		then
			echo -e "$(sed -i $line'd' $fileName)"	#deleting Record If Present
			echo -e "\nRecord Successfully Deleted"				
		else
			echo -e "No Record Present With ID $rno"	#Printing Warning Message If Record Is Not Present
		
		fi	
		return
}

#Defining Function To Delete Records With Phone Numbers
delete_phone(){
		echo
	        read -p 'Enter Phone Number To Be Deleted: ' phone #Reading Phone Number Whose Record To Be Deleted
		fileName="address.dat"
		lineNum="$(grep -n "$phone" "$fileName" | head -n 1 | cut -d" "  -f1)" #getting Line Number Of Record Containing Entered Phone Number
		
		line=${lineNum%:*}	#Seperating Linenum From Phone Number	
		#echo "$(>temp.dat)"
		
		if grep -q "$phone" "$fileName";  #Checking If Record Is Present Or Not
		then
			echo -e "$(sed -i $line'd' $fileName)"	#Deleting If Present 
			echo -e "\nRecord Successfully Deleted"				
		else
			echo -e "No Record Present With Phone Number $phone"	#Printing Error Message
		
		fi	
		return

		#End Of Function
}	

#Defining Function To Delete Records With Phone Numbers
delete_pin(){
		echo
	        read -p 'Enter Pin Number To Be Deleted: ' pin #Reading Phone Number Whose Record To Be Deleted
		fileName="address.dat"
		if grep -q "$pin" "$fileName";  #Checking If Record Is Present Or Not
		then
			awk '!/'"$pin"'/' "$fileName" > "temp.dat" && mv "temp.dat" "$fileName" #Deleting All Entries With Specific Pin Code
			echo -e 'Record Deleted Successfully'
		else
			echo -e "Record Is Not Present With Pin Number $pin" #Printing Error Message
		fi	
}		

#Defining Function For Modifying Record
modify()
{

		echo
        read -p 'Enter ID To Modify Record: ' rno #Reading Id Whose Record Is To Be Modified
		i=1
		flag=0
		re='^[0-9]+$'
		fileName="address.dat"
		lineNum="$(grep -n "$rno" $fileName | head -n 1 | cut -d" "  -f1)" 
		
		line=${lineNum%:*}	
		
		if grep -q "$rno" "$fileName"; #Checking If Record Is Present Or Not
		then
				read -p 'Enter Name: ' name #Taking New Name
				while [ "$flag" -eq 0 ]; do
					flag=0	
					echo
        			read -p 'Enter Phone Number: ' phone #Taking New Phone 
	
	        		if [ ${#phone} -ne 10 ] || ! [[ $phone =~ $re ]]; then #Checking Validity Of Phone Number
						echo            			
						echo "Enter Valid Phone Number"
						flag=0
					else 
						flag=1
						break;	
            		fi
				done
				flag=0
			echo
				echo			
				read -p 'Enter Address(Building/Flat No/Locality): ' loc #Taking New Address
				echo
				read -p 'Enter City Name: ' city #Taking City Name

				while [ "$flag" -eq 0 ]
				do	
					flag=0
					echo
					read -p 'Enter Pin Number: ' pin #Taking Pin Code From User
					if [ ${#pin} -eq 6 ] #Checking Validity Of Pin Number
					then
						break
						flag=1
					else 
						echo
						echo 'Pin Number Should Be Of 6 Digits'
						flag=0
					fi
				done
			
			echo
			echo -e "$(sed -i "/$rno/c\ $rno\t\t  $name\t\t$phone\t\t$loc\t\t$city\t\t$pin" address.dat)" #Writing Modified Data In File
			echo -e "\nRecord Successfully Modified"				
		else
			echo
			echo "No Record Present With ID $rno"	 #Printing Error Message If No Record Present With Entered ID
		fi	
		
		#End Of Function
}
#Starting Of Program 
choice=0 #initialize counter to control while
while [ "$choice" -ne 6 ] #iterate while choice is not equal to 6
do
	space #calling function for printing blank space
	
	#creating Menu For Input
	echo "----------- MENU ------------"
		echo "1) Add Record"
    	echo "2) Display"
    	echo "3) Search"
        echo "4) Delete"
    	echo "5) Modify"
    	echo "6) Exit"
	echo "----------------------------"
    	read -p 'Enter Your Choice : ' choice #reading User Choice
	case $choice in #switching According to User Choice
	
		1) add_record ;; #Calling Function add_record() to add record in file
		2) 
			choice1=0 #Initializing Counter to Control Below While Loop
			while [ "$choice1" -ne 3 ]
			do
				space ##calling function for printing blank space
				#Creating and Displaying Display Menu
				echo "--------- Display MENU -----------"
				echo "1.Display By Id"
				echo "2.Display By Name"
				echo "3.Back To Main Menu"
				echo "----------------------------------"
				read -p 'Enter Your Choice : ' choice1 #reading User Choice For Display Menu
				case $choice1 in #switching according to Users choice
					1) display ;; #calling Function display If Choice is 1
					2) display_name ;; #calling Function display If Choice is 2
					3) ;; #going back to main Menu
					*) echo "\nPlease Enter Valid Choice" #printing Message If Choice is Invalid
				esac
			done ;; #End of Second Case 
		3) 		choice2=0 #Initializing Counter to Control Below While Loop
			while [ "$choice2" -ne 3 ]
			do
				space ##calling function for printing blank space
				
				#Creating And Displaying Search Menu
				echo "--------- SEARCH MENU -----------"
				echo "1.SEARCH By Id"
				echo "2.SEARCH By Name"
				echo "3.Back To Main Menu"
				echo "----------------------------------"
				read -p 'Enter Your Choice : ' choice2 #reading User Choice For Search Menu
				case $choice2 in  #switching according to Users choice
					1) search ;; #calling Function search If Choice is 1
					2) search_name ;; #calling Function search_name If Choice is 2
					3) ;; #going back to main Menu
					*) echo "\nPlease Enter Valid Choice" #printing Message If Choice is Invalid
				esac
			done ;; #End Of Choice 3
	
		4) 
			choice4=0 #Initializing Counter to Control Below While Loop
			while [ "$choice4" -ne 4 ]
			do
				space ##calling function for printing blank space
				#Creating And Displaying Delete Menu
			
				echo "--------- DELETE MENU -----------"
				echo "1.DELETE By Id"
				echo "2.DELETE By Phone"
				echo "3.DELETE By Pin Code"	
				echo "4.Back To Main Menu"
				echo "----------------------------------"
				read -p 'Enter Your Choice : ' choice4 #Reading User Choice
				case $choice4 in #switching according to Users choice
					1) delete ;; ##calling Function delete If Choice is 1
					2) delete_phone ;; #calling Function delete_phone If Choice is 2
					3) delete_pin ;; #calling Function delete_pin If Choice is 2
					4) ;;	#going back to main Menu
					*) echo "\nPlease Enter Valid Choice"  #printing Message If Choice is Invalid
				esac
			done ;; #End Of Choice 4
	
		5) modify ;; #Calling Function Modify if User Choice is 5
		6) exit ;; #Terminating Program if User Choice is 6
		*) echo -e '\nInvalid Option' ;; #Printing Error Message If User Choice Is Invalid
	esac
done #End Of Program

