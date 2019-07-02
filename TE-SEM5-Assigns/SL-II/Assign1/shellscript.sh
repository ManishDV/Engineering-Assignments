#!/bin/bash

space(){

	echo
	echo
}
add_student(){
	space
	read -p 'Enter Total Records You Want To Add: ' no
	i=0
	flag=0
	re='^[0-9]+$'

	while [ "$i" -lt "$no" ]
	do	
		space
		echo "---------------------------------------------"

		read -p 'Enter Name: ' name
	
	
		while [ "$flag" -eq 0 ]; do
			flag=0	
			echo
        		read -p 'Enter Phone Number: ' phone
	
        		if [ ${#phone} -ne 10 ] || ! [[ $phone =~ $re ]]; then
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
		read -p 'Enter Address: ' loc
	
		echo
		read -p 'Enter City Name: ' city
	
		
		while [ "$flag" -eq 0 ]
		do	
			echo
			read -p 'Enter Pin Number: ' pin
	
			STRLENGTH=${#pin}
			echo "\n$STRLENGTH"
			if [ "$STRLENGTH" -eq 6 ]
			then
				break
				flag=1
			else 
				echo
				echo 'Pin Number Should Be Of 6 Digits'
				flag=0
			fi
		done
		
		
		initial="$(echo $name | head -c 1)"

		RANDOM="$(shuf -i 1-1000 -n 1)"
		
		id="$initial$RANDOM"
		
		echo "$id\t\t  $name\t\t$phone\t\t$loc\t\t$city\t\t$pin">>address.dat
		i=$((i+1))
	done
	return
}


display(){

	if [ -s "address.dat" ]
	then 
   		echo -e "\n\t\t\tRECORDS BY ID"
		echo "--------------------------------------------------------------------------------------------------------------------------------------------"
		echo -e "\nID\t\t\tNAME\t\tPHONE NUMBER\t\t\t\tADDRESS\t\t\t\tCity\t\tPin Code"
		echo -e '\n------------------------------------------------------------------------------------------------------------------------------------------'
		echo -e "$(cat address.dat)"
		echo -e '\n------------------------------------------------------------------------------------------------------------------------------------------'
			
	else
   		echo -e "\nfile does not exist, or is empty "
	fi	
	return 	
}

displayName(){

	if [ -s "address.dat" ]
	then 

		echo -e "\n\t\t\tRECORDS BY NAME\n\n"
	
		echo -e '\n------------------------------------------------------------------------------------------------------------------------------------------'
		echo -e '\nID\t\t\tNAME\t\tPHONE NUMBER\t\t\t\tADDRESS\t\t\t\tCity\t\tPin Code'
		echo
		echo '--------------------------------------------------------------------------------------------------------------------------------------------'
		echo -e "$(cat address.dat | sort -n -t ' ' -k 2,2 -k 3,3)"
		echo -e  '\n------------------------------------------------------------------------------------------------------------------------------------------'
			
	else
   		echo -e "\nfile does not exist, or is empty "
	fi	
	return 




}

	
search(){
	echo	
	read -p 'Enter ID To Be Searched: ' ID

	fileName="address.dat"

	if grep -q "$ID" "$fileName"; 
	then
		echo -e '\n------------------------------------------------------------------------------------------------------------------------------------------'
		echo -e '\nID\t\t\tNAME\t\tPHONE NUMBER\t\t\t\tADDRESS\t\t\t\tCity\t\tPin Code'
		echo
		echo '--------------------------------------------------------------------------------------------------------------------------------------------'
		echo -e "\n$(grep -F $ID address.dat)"
		echo -e '--------------------------------------------------------------------------------------------------------------------------------------------'
	else
		echo -e "\nNo Record Present With Id $ID"	
		
	fi	
	return
}


	
searchName(){
	echo
        read -p 'Enter Name To Be Searched: ' name
	fileName="address.dat"

	if grep -q "$name" "$fileName"; 
	then
'\n------------------------------------------------------------------------------------------------------------------------------------------'
		echo -e '\nID\t\t\tNAME\t\tPHONE NUMBER\t\t\t\tADDRESS\t\t\t\tCity\t\tPin Code'
		echo
		echo '--------------------------------------------------------------------------------------------------------------------------------------------'
		echo -e "\n$(grep -F $name address.dat)"
		echo -e '--------------------------------------------------------------------------------------------------------------------------------------------'
	else
		echo -e "\nNo Record Present With Name $name"	
		
	fi	
	return
}


delete(){


		echo
	        read -p 'Enter ID To Be Deleted: ' rno
		fileName="address.dat"
		lineNum="$(grep -n "$rno" "$fileName" | head -n 1 | cut -d" "  -f1)"
		
		line=${lineNum%:*}		
		#echo "$(>temp.dat)"
		
		if grep -q "$rno" "$fileName"; 
		then
			echo -e "$(sed -i $line'd' $fileName)"	
			echo -e "\nRecord Successfully Deleted"				
		else
			echo -e "No Record Present With ID $rno"	
		
		fi	
		return



}


modify(){


		echo
        	read -p 'Enter ID To Modify Record: ' rno
		i=1
		fileName="address.dat"
		lineNum="$(grep -n "$rno" $fileName | head -n 1 | cut -d" "  -f1)"
		
		line=${lineNum%:*}	
		
		if grep -q "$rno" "$fileName"; 
		then
			read -p "Do You Want To Modify Name For ID $rno (1 or 0)" choice3
			if [ "$choice3" -eq 1 ];
			then
				echo -e '\nEnter Student Name: '
				read name
			fi
			choice3=0
			read -p "Do You Want To Modify Address For ID $rno (1 or 0)" choice3
			if [ "$choice3" -eq 1 ];
			then
							
				read -p '\nEnter Address(Building/Flat No/Locality): ' loc
			
				read -p '\nEnter City Name: ' city
		
				read -p '\nEnter Pin Code: ' pin
		
			echo -e "$(sed -i "/$rno/c\ $id\t\t  $name\t\t$phone\t\t$loc\t\t$city\t\t$pin" address.dat)"
			echo -e "\nRecord Successfully Modified"				
		else
			echo "No Record Present With ID $rno"	
		fi	
		return
}

choice=0
while [ "$choice" -ne 6 ]
do
	echo "----------- MENU ------------"
	echo "1) Add Record"
    	echo "2) Display"
    	echo "3) Search"
        echo "4) Delete"
    	echo "5) Modify"
    	echo "6) Exit"
	echo "----------------------------"
    	read -p 'Enter Your Choice : ' choice
	case $choice in
	
		1) add_student ;;
		2) 
			choice1=0
			while [ "$choice1" -ne 3 ]
			do
				space
				echo "--------- Display MENU -----------"
				echo "1.Display By Id"
				echo "2.Display By Name"
				echo "3.Back To Main Menu"
				echo "----------------------------------"
				read -p 'Enter Your Choice : ' choice1
				case $choice1 in 
					1) display ;;
					2) displayName ;;
					3) ;;
					*) echo "\nPlease Enter Valid Choice"
				esac
			done ;;
		3) 		choice2=0
			while [ "$choice2" -ne 3 ]
			do
				space
				echo "--------- SEARCH MENU -----------"
				echo "1.SEARCH By Id"
				echo "2.SEARCH By Name"
				echo "3.Back To Main Menu"
				echo "----------------------------------"
				read -p 'Enter Your Choice : ' choice2
				case $choice2 in 
					1) search ;;
					2) searchName ;;
					3) ;;
					*) echo "\nPlease Enter Valid Choice"
				esac
			done ;;
	
		4) delete ;;
		5) modify ;;
		6) exit ;;
		*) echo '\nInvalid Option' ;;
	esac
done
