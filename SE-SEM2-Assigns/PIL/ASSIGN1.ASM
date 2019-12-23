
.model small
;---- Declaring Macro For User Input ----

input macro msg1

        ;--- Loading Effective Address Of Array ----
        lea SI,arr
        mov ch,01h

        ;--- Loop For The Printing message and taking user Input
        loop1:
             
             mov dl,offset msg1
             mov ah,09h
             int 21h

             mov al,00h
             mov al,ch

             add al,30h
             mov dl,al
             
             mov ah,02h
             int 21h
             INC ch

             mov dl,20h
             mov ah,02h
             int 21h

             ;--- Taking Array Elements ---
             mov ah,01h
             int 21h
             mov [SI],al
             INC SI
             dec cl
             jnz loop1

endm


;----- Declaring Macro For Display -----
disp macro
        ;--- Initializing Counter with Content of BL register ---
        mov cl,bl
        lea SI,arr

        loop2:
             
             mov al,[SI]
             mov dl,al
             mov ah,02h
             int 21h
             INC SI

            
             mov dl,20h
             mov ah,02h
             int 21h
             
             dec cl
             jnz loop2

endm
;--- Declaring Macro For Addition ----
addition macro

                lea SI,arr
                mov cl,bl
                mov al,00h


    loop3:

        mov dl,[si]
        sub dl,30h
        add al,dl
        daa
        INC si
        dec cl

        jnz loop3
    
endm
;--- Initialising Data Segment ---- 
.data

   arr db 10 dup(?) 
   msg db 10,13,10,'Enter Number Of Elements: ','$'
   msg1 db 10,13,'Enter Element: ','$'
   msg2 db 10,10,13,'Elements are: ','$'
   msg3 db 10,10,13,'Addition is: ','$'

 ;---- Initialising Code Segment ----
.code
        mov ax,@data
        mov ds,ax
        mov ax,0000h
        mov dx,0000h

        mov dl,offset msg
        mov ah,09h
        int 21h

        mov ah,01h
        int 21h

        sub al,30h
        mov cl,al
        mov bl,al

        input msg1

        mov dl,offset msg2
        mov ah,09h
        int 21h
        disp

        mov dl,offset msg3
        mov ah,09h
        int 21h


        addition
        mov cx,0204h
        mov bl,al
        loop4:
           rol bl,cl
           mov dl,bl
           and dl,0Fh
           cmp dl,09h
           jbe loop5
           add dl,07h
        loop5:
           add dl,30h
           mov ah,02h
           int 21h
           dec ch
           jnz loop4

       

         mov ah,04ch
         int 21h

end
