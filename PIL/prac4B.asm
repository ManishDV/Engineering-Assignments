.model small

dispStr macro msg
    lea dx,msg
    mov ah,09h
    int 21h
endm


.data
       extrn mainStr   
       concatIn  db 25 dup('$')
       concatStr db 25 dup('$')
       compareMsg1 db 10,10,13,'Enter The String To Compare: $'
       compareMsg2 db 10,10,13,'Strings Are Equal $'
       compareMsg3 db 10,10,13,'Strings Are NOT Equal $'
       
       concatmsg1 db 10,10,13,'Enter String To Be Concatenated: $'
       originalStrMsg db 10,10,13,'Original String Is: $'
       concatmsg2 db 10,10,13,'Concatenated String is: $'
       
       substrMsg1 db 10,10,13,'Enter Substring To be Find: $'
       substrMsg2 db 10,10,13,'Length Of Substring Cannot Be Equal To or Greather Than Length Of Original String$'
       substrMsg3 db 10,10,13,'Substring Is Present In Original String$'
       substrMsg4 db 10,10,13,'Substring Is Not Present In Original String$'

       len db 0
        
.code

        mov ax,@data
        mov ds,ax
        public concat    
        proc concat far

            dispStr concatmsg1
            lea dx,concatIn
            mov ah,0Ah
            int 21h 

            dispStr originalStrMsg
            dispStr mainStr+2

            dispStr concatmsg2

            lea si,mainStr+2
            lea di,concatStr

            loop1:
                mov al,[si]
                mov [di],al
                inc si
                inc di
                mov al,[si]
                cmp al,24h
                jne nextCheck                 
                nextCheck:
                cmp al,13
                jne loop1

                lea si,concatIn+2
                do:
                    mov al,[si]
                    mov [di],al
                    inc si
                    inc di
                    mov al,[si]
                cmp al,24h
                jne nextCheck1                 
                nextCheck1:
                cmp al,13
                jne do
                mov al,'$'
                mov [di],al

                mov ax,0000h
                mov bx,0000h
                mov cx,0000h
                mov dx,0000h
                    
                dispStr concatStr    
            ret
        concat endp

        public compare
        proc compare far
        
        dispStr compareMsg1
        lea dx,concatIn
        mov ah,0Ah
        int 21h
        lea si,mainStr
        lea di,concatIn
        mov al,[si+1]
        mov dl,[di+1]
        cmp al,dl
        je GoAhead
        dispStr compareMsg3
        jmp end1    
        GoAhead:
            lea si,mainStr+2
            lea di,concatIn+2
            mov ch,al    
            loop3:
                mov al,[si]
                mov dl,[di]
                cmp al,dl
                jne nequal
                inc si
                inc di
                dec ch
                jnz loop3
                dispStr compareMsg2
                jmp end1
            nequal:
                dispStr compareMsg3
                jmp end1 

        end1:
        ret
        compare endp


        public substrProc
        
        proc substrProc far
        mov ax,0000h
        mov bx,0000h
        mov cx,0000h
        mov dx,0000h
        
        dispStr substrMsg1
        lea dx,concatIn
        mov ah,0Ah
        int 21h

        lea si,mainStr
        lea di,concatIn

        mov al,[si+1]
        mov dl,[di+1]
        mov len,dl
        cmp dl,al
        jge error1
        mov bx,0000h
            
        lea si,mainStr+2
        lea di,concatIn+2
          
        loop2:
            mov ch,len
            inc bx 
            lea si,mainStr+bx
            lea di,concatIn+2
            loop4:
                mov al,[si]
                mov dl,[di]
                cmp al,dl
                jne loop2
                inc si
                inc di
                dec ch

                mov al,[si]
                cmp al,13
                je stop
                jnz doAgain
                doAgain:
                    dec ch
                    jnz loop4
            stop:
                cmp ch,00h
                jne print
                dispStr substrMsg3
                jmp end2
            print:
                dispStr substrMsg4
                jmp end2

        error1:
             dispStr substrMsg2
             jmp end2   
        end2:    
        ret
        substrProc endp



end
