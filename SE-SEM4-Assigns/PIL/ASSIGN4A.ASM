.model small

getstr macro

    mov ah,0ah
    int 21h

endm

dispStr macro 
	
     mov ah,09h
     int 21h
endm

.data
   str1 db 25 dup('$')
   str2 db 25 dup('$')
   inpStr db 10,10,13,'Enter String: $'
   inpStr1 db 10,10,13,'Enter String To Concat: $'
   inpStr2 db 10,10,13,'Enter String To Compare: $'
   inpStr3 db 10,10,13,'Enter Substring to Find: $'
   
   public str1,str2
  errorMsg db 10,10,13,'Please Enter Valid Choice$'
  menustr db 10,13,10,13,'---------------MENU----------------',10,13,'1. INPUT STRING',10,13,'2. DISPLAY STRING',10,13,'3. CONCATENATE STRINGS',10,13,'4. COMPARE STRINGS',10,13,'5. OCCURENCE OF SUBSTRING ',10,13,'6. COUNT SPECIAL CHARACTERS',10,13,'7. EXIT',10,10,13,'-----------------------------------',10,13,'ENTER YOUR CHOICE - $'
   
.code

    mov ax,@data
    mov ds,ax
    mov es,ax

 m1:
        lea dx,menustr
        dispStr

        mov ah,01h
	int 21h

        cmp al,31h
        jne next1

        je input

        input:
          lea dx,inpStr
          mov ah,09h
          int 21h

          lea dx,str1
           getstr

          jmp m1



        next1:
	  cmp al,32h
          jne next2
	  extrn displayStr:far
	  call displayStr
	 	 
	   jmp m1
  
	next2:
	cmp al,33h
	jne next3
	 
	mov dx,offset inpStr1
        dispStr
        

        mov dx,offset str2
        getStr
  
	extrn concatStr:far
	call concatStr
        jmp m1
         
          
	next3:
          cmp al,34h
          jne next4

          mov dx,offset inpStr2
          dispStr
          

          mov dx,offset str2
          getStr

          extrn compare:far
          call compare
          jmp m1

	next4:
	
	   cmp al,35h
           jne next5

           mov dx,offset inpStr3
           dispStr
          

           mov dx,offset str2
           getStr

           extrn subString:far
           call subString

          jmp m1


	next5:
	    cmp al,36h
	    jne next6
            ;call strpali
	jmp m1

	next6:
	  cmp al,37h
	  jne printError
	  jmp finalnext  		  
	
 printError:
	mov dx,offset errorMsg
        dispStr
	jmp m1		
	
         
        ;------------ terminate the program ---------------
        finalnext:
        dispstr byestr
        mov ah,4ch
        int 21h;


   
    mov ah,04ch
    int 21h

end

