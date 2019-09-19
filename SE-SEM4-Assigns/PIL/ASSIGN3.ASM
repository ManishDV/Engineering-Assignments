
;--- Manish Visave ----
;--- Roll: 23366 ----
;-- Program to Perform String Operation ----

.model small

disp macro
    mov ah,09h
    int 21h
endm

input macro
    lea dx,main
    mov ah,0Ah
    int 21h
endm

lenDisp macro

   mov ax,0000h
   mov bx,0000h
   mov dx,0000h


   mov al,[main+1]
   daa


   mov cx,0204h
   mov bl,al

   loop3:
         rol bl,cl
         mov dl,bl
         and dl,0Fh
         cmp dl,09h
         jbe loop4
         add dl,07h

   loop4:
         add dl,30h
         mov al,dl
         daa
         mov dl,al
         mov ah,02h
         int 21h
         dec ch
         jnz loop3



endm

printError macro


                lea dx,error1
                disp
                jmp menu1



endm

.data

           
           temp1 db '$'
           menu db 10,10,13,'--------- MENU -------',10,10,13,'1.INPUT',10,13,'2.DISPLAY',10,13,'3.LENGTH',10,13,'4.REVERSE',10,13,'5.PALINDROME',10,13,'6.EXIT',10,10,13,'---------------$'
           choice db  10,13,'Enter Your Choice: $'
           errorString db 10,13,'Please Enter Valid Choice$' 
           main db 25 dup('$')
           reverse db 25 dup('$')
           inp db 10,10,13,'Enter String: $'
           rev db 10,10,13,'Reverse String is: $'
           outp db 10,10,13,'Main String is: $'
           lenstr db 10,10,13,'Length Of String Is: $'
           palin db 10,10,13,'String Is Palindrome $'
           palin1 db 10,10,13,'String Is Not Palindrome $'
           error1 db 10,10,13,'Please Enter String First $'
.code
        ; --- INITIAL STEPS ----
          mov ax,@data
          mov ds,ax

        menu1:
             mov al,00h
             lea dx,menu
             disp
             lea dx,choice
             disp


             mov ah,01h
             int 21h

             cmp al,31h
             jne second
             je input1

            second:
             cmp al,32h
             jne third
             je  strdisplay

            third:
             cmp al,33h
             jne fouth
             call strlength
             jmp menu1

             fouth:
                cmp al,34h
                jne fifth
                call reverseS
                jmp menu1

             fifth:
                cmp al,35h
                jne exitC
                call palindrome
                jmp menu1

             exitC:
                   cmp al,36h
                   jne errorS
                   mov ah,04ch
                   int 21h
                 

             errorS:

             disp errorString
             jmp menu1


        input1:
             lea dx,inp
             disp

            
             input
             jmp menu1

         printError1:
              printError

       strdisplay:
             mov al,[main+1]
             cmp al,24h
             je printError1
            
             lea dx,outp
             disp

             lea dx,main+2
             disp
             
             jmp menu1

        strlength proc string
             mov al,[main+1]
             cmp al,24h
             je printError1
             

              lea dx,outp
              disp

             lea dx,main+2
             disp

              lea dx,lenStr
              disp

              lenDisp

             ret
        strlength endp

        reverseS proc string
             mov al,[main+1]
             cmp al,24h
             je printError1
               
               mov cx,0000h
               mov bx,0000h

               lea si,main

               lea di,reverse

               mov bl,[si+1]

               mov cl,bl
               add bl,01h
               mov bh,00h

               lea si,main+bx
               lea di,reverse
               mov [di+1],cl
               lea di,reverse+2

             lea dx,outp
             disp


             lea dx,main+2
             disp

             lea dx,rev
             disp
                    
                mov dx,0000h
               loop1:
                   
                  mov dx,[si]
                  mov [di],dx
                  inc di
                  dec si
                  dec cl
                  mov dl,'$'
                  mov [di],dl
                  jnz loop1

               

                mov dx,0000h
               lea dx,reverse+2
               disp
             


             ret
        reverseS endp

         printError2:
              printError

        palindrome proc string
                mov al,[main+1]
                cmp al,24h
                je printError2
                
                mov si,offset main+2
                mov di,offset reverse+2

                mov cl,[main+1]
                mov ch,00h

                loop2:
                        mov al,[si]
                        mov dl,[di]
                        cmp al,dl
                        jne print1
                        inc si
                        inc di
                        dec cl
                        jnz loop2
                   

             print2:
                lea dx,palin
                disp
                cld
                jmp menu1

               print1:
                    lea dx,palin1
                    disp
                    cld
                    jmp menu1


        
             ret
        palindrome endp



end
