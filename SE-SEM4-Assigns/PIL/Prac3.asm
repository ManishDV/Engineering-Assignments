.model small

dispStr macro msg

    lea dx,msg
    mov ah,09h
    int 21h

endm

input macro 

    mov ah,01h
    int 21h

endm



.data
    mainstr db 25 dup('$')
    revstr db 25 dup('$')
    mainInput db 10,10,13,'Enter The String: $'
    menu db 10,10,13,'------- MENU ------',10,10,13,'1.LENGTH',10,13,'2.REVERSE',10,13,'3.PALINDROME',10,13,'4.EXIT',10,10,13,'----------------$'
    lenDisp db 10,10,13,'Length Of String Is: $'    
    choiceDisp db 10,10,13,'Enter Your Choice: $'
    choiceerr db 10,10,13,'Please Enter Valid Choice$'
    strDisp db 10,10,13,'Main String Is: $'
    revDisp db 10,10,13,'Reverse String IS: $'
    count db 0
    palinDisp db 10,10,13,'String Is Palindrome $'
    NopalinDisp db 10,10,13,'String Is Not Palindrome $'

.code

    mov ax,@data
    mov ds,ax

    dispStr mainInput
    lea dx,mainstr
    mov ah,0Ah
    int 21h

    menu1:
            dispStr menu
            dispStr choiceDisp
            input
            cmp al,31h
            jne next
            dispStr strDisp
            dispStr mainstr+2
            dispStr lenDisp
            call LengthProc
            jmp menu1
            
            next:
                 cmp al,32h
                 jne next1
                 dispStr strDisp
                 dispStr mainstr+2
                 dispStr revDisp
                 call ReverseProc
                 dispStr revstr+2   
                 jmp menu1
            next1:
                 cmp al,33h
                 jne next2
                 call PalinProc
                 jmp menu1
            next2:
                  cmp al,34h
                  jne printError
                  mov ah,04Ch
                  int 21h
            printError:
                  dispStr choiceerr 
                  jmp menu1       


            proc LengthProc near
            
                lea si,mainstr
                mov dl,[si+1]
                add dl,30h
                mov ah,02h
                int 21h
            ret 
            LengthProc endp          

            proc ReverseProc near

                lea si,mainstr
                lea di,revstr
                
                mov ch,[si+1]
                mov [di+1],ch
                mov count,ch
                inc ch
                mov bl,ch
                mov bh,00h
                lea si,mainstr+bx
                lea di,revstr+2                      
                for:
                    mov dx,0000h
                    mov dl,[si]
                    mov [di],dl
                    inc di
                    dec si
                    mov dl,'$'
                    mov [di],dl
                    dec count
                    jnz for 
                    mov dl,'$'
                    mov [di],dl       
            ret 
            ReverseProc endp          

            proc PalinProc near
                cld
                call ReverseProc
                mov ax,0000h
                mov bx,0000h
                mov dx,0000h
                    
                lea si,mainstr
                ;mov dl,[si+1]
                
                mov ch,00h
                mov cl,[mainstr+1]
                lea di,revstr+2
                lea si,mainstr+2
                loop3:
                     mov al,[si]
                     mov dl,[di]
                     cmp al,dl
                     jne notEq
                     inc si
                     inc di
                     dec cl
                     jnz loop3 

                     dispStr palinDisp 
                     ret
                notEq:
                    dispStr NopalinDisp    

            ret 
            PalinProc endp          
            
end