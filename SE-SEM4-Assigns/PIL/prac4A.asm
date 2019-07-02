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
    mainStr db 25 dup('$')
    public mainStr
    menu db 10,10,13,'----------- MENU ------------',10,10,13,'1.CONCAT',10,13,'2.COMPARE',10,13,'3.SUBSTRING',10,13,'4.SPECIAL CHARACTER',10,13,'5.EXIT',10,10,13,'---------------------------- $'
    choiceMsg db 10,10,13,'Enter Your Choice: $'
    strMsg db 10,10,13,'Enter String: $'
    CERROR db 10,10,13,'Please Enter Valid Choice$'
.code

    mov ax,@data
    mov ds,ax

    dispStr strMsg
    mov dx,0000h
    lea dx,mainStr
    mov ah,0Ah
    int 21h


    menu1:
            dispStr menu
            dispStr choiceMsg

            input

            cmp al,31h
            jne next
            extrn concat:FAR    
            call concat
            jmp menu1

            next: 
                 cmp al,32h
                 jne next1
                 extrn compare:FAR
                 call compare
                 jmp menu1
            next1:
                 cmp al,33h
                 jne next2
                 extrn substrProc:FAR
                 call substrProc
                 jmp menu1
            next2:
                 cmp al,34h
                 jne exitCheck
                 ;call SPECIAL
                 jmp menu1
            exitCheck:
                  cmp al,35h
                  jne ChoiceError
                  mov ah,04Ch
                  int 21h

            ChoiceError:
                dispStr CERROR
                jmp menu1


end
