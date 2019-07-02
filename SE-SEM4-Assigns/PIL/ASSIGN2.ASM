;-- Program to Convert BCD TO HEX number and HEX TO BCD
;-- Roll No: 23366


.model small
.stack 500h

;---- Macro To Display String ----
dispString macro

        mov ah,09h
        int 21h

endm

;---Taking BCD Input ----
input macro msg
           mov cl,05h
           lea si,multiplier
           lea di,original


           mov dx,offset msg
           dispString     
           loop1:
               mov ah,01h
               int 21h

               sub al,30h
               mov ah,00h

               mov [di],al
               daa

               inc di
              
               mov dx,[si]
               mul dx
               add ax,result
               mov result,ax
               inc si
               inc si
              
               dec cl
               jnz loop1

endm

;--- Taking Hex Input ----
inputhex macro

       mov ax,0000h
       mov bx,0000h
       mov cx,0000h
       mov dx,0000h
       mov cl,04h
       mov ch,04h
       mov dx,offset msg10
       mov ah,09h
       int 21h

       mov dx,0000h
       mov ax,0000h
       lea di,original1
       
       loop20:
              mov ah,01h
              int 21h

              ;--- Checking If Input Is Digit
              cmp al,30h 
              jl test3
              cmp al,39h
              jg test1
              mov [di],al
              inc di
              sub al,30h
              jmp task



     test1:
              ;---checking Input Between A to F  
              cmp al,41h
              jl test2
              cmp al,46h
              jg test2
              mov [di],al
              inc di
              sub al,37h
              jmp task
     test2:
              ;----- Checking Input Between a to f
              cmp al,61h
              jl test3
              cmp al,66h
              jg test3
              mov [di],al
              inc di
              sub al,57h
              jmp task
      test3:
              mov dx,offset msg11
              mov ah,09h
              int 21h
              jmp menu
            
endm



.data
      
        result dw 0h
        multiplier dw 2710h,03E8h,0064h,000Ah,0001h
        original db 5 dup(0)
        original1 db 4 dup(0)
        ;divide db 10
        msg1 db 10,10,13,'---- MENU ----',10,10,13,'1.BCD TO HEX',10,13,'2.HEX TO BCD',10,13,'3.EXIT',10,10,13,'-------------','$'
        msg2 db 10,13,'In BCD TO HEX $'
        msg3 db 10,13,'In HEX TO BCD $'
        msg4 db 10,13,'Enter Your Choice: $'
        msg5 db 10,10,13,'Please Enter Valid Choice$'
        msg6 db 10,10,13,'Enter BCD Number: $'
        msg10 db 10,10,13,'Enter Hex Number: $'
        msg11 db 10,10,13,'Enter Valid Hex Number $'
        msg12 db 10,10,13,'Original Hex Number $'
        msg7 db 10,10,13,'Conversion Result Is: $'
        msg8 db 10,10,13,'Original BCD Number Is: $'
        msg9 db 10,10,13,'First Number Should be Less Than 7 $'
.code

        mov ax,@data
        mov ds,ax

        menu:

             mov dx,offset msg1
             dispString


        mov dx,offset msg4

        dispString

        mov ah,01h
        int 21h

        cmp al,31h
        jne next1
        call bcdtohex
        jmp menu
        next1:
            cmp al,32h
            jne next2
            call hextobcd
            jmp menu


        next2:
             cmp al,33h
             jne next3
             mov ah,04ch
             int 21h

        next3:
             mov dx,offset msg5
             dispString
             jmp menu


        bcdtohex proc near

             input msg6

                lea di,original
                mov dl,[di]
                cmp dl,07h
                jge print
                jl  move
             print:
                mov dx,offset msg9
                mov ah,09h
                int 21h
                
                jmp menu
                
               

            move:
             mov dx,offset msg8
             dispString

             mov cl,05h

             lea di,original

             loop12:
                   mov dl,[di]
                   add dl,30h

                   mov ah,02h
                   int 21h
                   inc di
                   dec cl
                   jnz loop12

             mov dx,offset msg7

             dispString
          
             mov ax,0000h
             mov cx,0404h
             mov ax,result

             mov bx,ax

             loop3:
                rol bx,cl
                mov dl,bl
                and dl,0Fh

              cmp dl,09h
              jbe loop4
              add dl,07h

            loop4:
                  add dl,30h
                  mov ah,02h
                  int 21h
                  dec ch
                  jnz loop3


            mov result,0000h

           ret

        bcdtohex endp

        ;--- Procedure to Convert Hex To BCD
        hextobcd proc near
             ;-- Taking Input
             inputHex

             ;-- If Input Is Valid
           task:
              ;-- Taking a whole Number in a Register
              mov ah,00h
              rol bx,cl
              add bx,ax
              dec ch
              jnz loop20

                mov ax,0000h
                mov cx,0004h
                mov dx,0000h
                mov ax,bx
                mov bx,0010
            loop13:
                ; -- Pushing Remainder On Stack
                mov dx,0000h
                div bx
                push dx
                inc ch
                cmp ax,0000h
                jne loop13


             ; -- Displaying Original Hex Value
             mov dx,offset msg12
             dispString


             mov dx,000h
             lea di,original1


             mov cl,04h
             loop14:
                   mov dl,00h
                   mov dl,[di]

               
                   mov ah,02h
                   int 21h
                   inc di
                   dec cl
                   jnz loop14

             
             mov dx,offset msg7
             dispString
                
             loop15:
                   mov dx,0000h     
              
                   pop dx
                   add dl,30h
                   
                   mov ah,02h
                   int 21h
                   dec ch
                   jnz loop15
                        
                   ret
        hextobcd endp

end

