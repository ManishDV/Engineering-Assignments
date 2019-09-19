;-- Manish Visave(23366) --
.model small




;----- Declaring Macro For Display -----





disp macro myCount
        ;--- Initializing Counter with Content of BL register ---
        mov cl,04h
        mov ch,05h

        lea SI,arr

        loop2:
             
             mov al,[SI]
             daa
             INC SI

        mov bl,AL
        
        mov ch,02h
        loop7:
           rol bl,cl
           mov dl,bl
           and dl,0Fh
           cmp dl,09h
           jbe loop8
           add dl,07h
          
        loop8:
           add dl,30h
           
           mov ah,02h
           int 21h
           dec ch
           jnz loop7


            
             mov dl,20h
             mov ah,02h
             int 21h
             
             dec myCount
             jnz loop2

endm






;--- Declaring Macro For Addition ----
addition macro arr
                mov ax,0000h
                mov bx,0000h
                mov cx,0000h
                lea SI,arr
                mov cl,05h
                mov al,00h


    loop3:

        mov dl,[si]
        mov al,dl
        add al,sum
        daa
        mov sum,al
        
        INC si
        dec cl
       jnz loop3

  
endm
;--- Initialising Data Segment ---- 
.data

   arr db 11,11,11,11,11
   myCount db 05h
   sum db 00h
   msg db 10,13,10,'Enter Number Of Elements: ','$'
  ; msg1 db 10,13,'Enter Element: ','$'
   msg2 db 10,10,13,'Elements are: ','$'
   msg3 db 10,10,13,'Addition is: ','$'

 ;---- Initialising Code Segment ----
.code
        mov ax,@data
        mov ds,ax
        mov ax,0000h
        mov dx,0000h
        mov cx,0000h
                




       disp myCount

        mov dl,offset msg3
        mov ah,09h
        int 21h


        addition arr
        mov cx,0204h
        mov bl,sum

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
