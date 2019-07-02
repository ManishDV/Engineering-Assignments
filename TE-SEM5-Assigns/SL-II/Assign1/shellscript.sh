#!/bin/sh

add_student(){
	echo '\nEnter Number Of Student: \c'
	read no
	i=0
	flag=0
	while [ "$i" -lt "$no" ]
	do	
		flag=0
		echo "\n---------------------------------------------"

		echo '\nEnter Person Name: \c'
		read name
	
		while [ "$flag" -eq 0 ]
		do
			echo '\nEnter Phone Number: \c'
			read phone
			patt='^[0-9]$'
			 if ! [[ "$phone" =~ ^[[:digit:]]+$ ]];  
			then
   				echo "\nCharacters Are Not Allowed In Phone Number"
   				flag=0
   				continue
			fi
			
			STRLENGTH=${#phone}
			echo "\n$STRLENGTH"
			if [ "$STRLENGTH" -eq 10 ]
			then
				break
				flag=1
			else 
				echo '\nPhone Number Should Be Of 10 Digits'
				flag=0
			fi
		done
					 
		
		echo "\nEnter Address: \c"
		read loc
		
		
		echo "\nEnter City Name: \c"
		read city
		
		while [ "$flag" -eq 0 ]
		do
			echo '\nEnter Pin Number: \c'
			read pin
			STRLENGTH=${#pin}
			echo "\n$STRLENGTH"
			if [ "$STRLENGTH" -eq 6 ]
			then
				break
				flag=1
			else 
				echo '\nPin Number Should Be Of 6 Digits'
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
   		echo '\n\t\t\tRECORDS BY ID\n'
		echo '\n------------------------------------------------------------------------------------------------------------------------------------------'
		echo '\nID\t\t\tNAME\t\tPHONE NUMBER\t\t\t\tADDRESS\t\t\t\tCity\t\tPin Code'
		echo '\n------------------------------------------------------------------------------------------------------------------------------------------'
		echo "$(cat address.dat)"
		echo '\n------------------------------------------------------------------------------------------------------------------------------------------'
			
	else
   		echo "\nfile does not exist, or is empty "
	fi	
	return 	
}

displayName(){

	if [ -s "address.dat" ]
	then 

		echo '\n\t\t\tRECORDS BY NAME\n\n'
	
		echo '\n------------------------------------------------------------------------------------------------------------------------------------------'
		echo '\nID\t\t\tNAME\t\tPHONE NUMBER\t\t\t\tADDRESS\t\t\t\tCity\t\tPin Code'
		echo '\n------------------------------------------------------------------------------------------------------------------------------------------'
		echo "$(cat address.dat | sort -n -t ' ' -k 2,2 -k 3,3)"
		echo '\n------------------------------------------------------------------------------------------------------------------------------------------'
			
	else
   		echo "\nfile does not exist, or is empty "
	fi	
	return 




}

	
search(){

	echo '\nEnter ID To Be Searched: '
	read ID

	fileName="address.dat"

	if grep -q "$ID" "$fileName"; 
	then
		echo '\n----------------------------------------------------------'
		echo '\nID\t\tNAME\t\tADDRESS'
		echo '\n----------------------------------------------------------'
		echo "\n$(grep -F $ID address.dat)"
		echo '\n----------------------------------------------------------'  		
	else
		echo "\nNo Record Present With Roll Number $ID"	
		
	fi	
	return
}


	
searchName(){

	echo '\nEnter Name To Be Searched: '
	read name

	fileName="address.dat"

	if grep -q "$name" "$fileName"; 
	then
		echo '\n----------------------------------------------------------'
		echo '\nID\t\tNAME\t\tADDRESS'
		echo '\n----------------------------------------------------------'
		echo "\n$(grep -F $name address.dat)"
		echo '\n---------------------------------------------'  		
	else
		echo "\nNo Record Present With Roll Number $name"	
		
	fi	
	return
}


delete(){


		echo '\nEnter Roll Number Which Data To Be Deleted: '
		read rno
		i=1
		fileName="address.dat"
		lineNum="$(grep -n "$rno" student.dat | head -n 1 | cut -d" "  -f1)"
		
		line=${lineNum%:*}		
		#echo "$(>temp.dat)"
		
		if grep -q "$rno" "$fileName"; 
		then
			echo "$(sed -i $line'd' student.dat)"	
			echo "\nRecord Successfully Deleted"				
		else
			echo "No Record Present With Roll Number $rno"	
		
		fi	
		return



}


modify(){


		echo '\nEnter Roll Number Which Record To Be Modified: '
		read rno
		i=1
		fileName="student.dat"
		lineNum="$(grep -n "$rno" student.dat | head -n 1 | cut -d" "  -f1)"
		
		line=${lineNum%:*}		
		#echo "$(>temp.dat)"
		
		if grep -q "$rno" "$fileName"; 
		then
			echo '\nEnter Student Name: '
			read name
		
			echo '\nEnter Subject 1 Marks: '
			read m1
			
			echo '\nEnter Subject 2 Marks: '
			read m2
		
			echo '\nEnter Subject 3 Marks: '
			read m3
		
			avg=$(((m1+m2+m3)/3))
	
			echo "$(sed -i "/$rno/c\ $rno \t $name \t $m1 \t $m2 \t $m3 \t $avg" student.dat)"
			echo "\nRecord Successfully Deleted"				
		else
			echo "No Record Present With Roll Number $rno"	
		
		fi	
		return



}
choice=0
while [ "$choice" -ne 6 ]
do
	echo '\n-------- MENU --------\n1.Insert Student Info\n2.Display Record\n3.Search In Program\n4.Delete Record\n5.Modify Record\n6.Exit\n---------------\nEnter Your Choice: \c' 
	read choice

	case $choice in
	
		1) add_student ;;
		2) 
			choice1=0
			while [ "$choice1" -ne 3 ]
			do
			
				echo "\n--------- Display MENU -----------\n\n1.Display By Id\n2.Display By Name\n3.Back To Main Menu\n----------------------------------\nEnter Your Choice: "
				read choice1
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
			
				echo "\n--------- Search MENU -----------\n\n1.Search By Id\n2.Search By Name\n3.Back To Main Menu\n----------------------------------\nEnter Your Choice: "
				read choice2
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
