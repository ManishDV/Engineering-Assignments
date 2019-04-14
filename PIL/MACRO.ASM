.model small

;------Macro For Displaying String----------

displ macro msg
     mov dx,offset msg
     mov ah,09h
     INT 21h
ENDM

;------Macro For Displaying Single Digit Result-----

disp macro result
     mov dl,result
     mov ah,02h
     INT 21h
ENDM

disp2 macro 
        loop1:
              rol bl,cl
              mov dl,bl
              and dl,0Fh

              CMP dl,09h
              jbe loop2
              add dl,07h

        loop2:
               add dl,30h
               disp dl
               dec ch
               jnz loop1

ENDM



.data
        ;-----Variable Declaration-----

        n1 db 12
        n2 db 05h
        n3 db 02h
        n4 db 08h
        msg db 10,13, 'Addition Is: ' ,'$'
        msg1 db 10,13, 'Substraction Is: ','$'

        msg2 db 10,13,'Multiplication Is:','$'
        msg3 db 10,13,'Division Is with ','$'
        msg4 db ' Quotiont = ','$'
        msg5 db  ' and Remainder =','$'

.code
        mov ax,@data
        mov ds,ax

        mov cx,0204h
       
        mov ax,0000h

        mov al,n1

        add al,n2

        daa

        mov bl,al


        disp2 
       ;ADD al,30h


      ;  displ msg

       ; disp dl

       ; mov al,n2
       ; SUB al,n1
       ; ADD al,30h

       ; displ msg1
       ; disp al

       ; mov al,n1
       ; MUL n3
       ; ADD al,30h

        ;displ msg2

       ; disp al

       ; mov ax,0000h
       ; mov al,n1
       ; DIV n3

       ; ADD al,30h
       ; ADD ah,30h

       ; displ msg3

       ; displ msg4

       ; disp al

       ; displ msg5

       ; disp al


        mov ah,4ch
        INT 21h
 end
                   
