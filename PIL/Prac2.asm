.model small
.stack 500h
dispStr macro 

    mov ah,09h
    int 21h

endm 

inputHex macro

mov ax,0000h
mov bx,0000h
mov cx,0404h
mov dx,0000h
lea si,originalHex
lea dx,HexIn
dispStr
loop5:

        mov ah,01h
        int 21h
        
        cmp al,30h
        jl valErr
        cmp al,39h
        jg nextCheck
        mov [si],al
        sub al,30h
        mov ah,00h
        rol bx,cl
        add bx,ax
        jmp nextIter
nextCheck:
        cmp al,41h
        jl valErr
        cmp al,46h
        jg nextCheck1
        mov [si],al
        sub al,37h
        mov ah,00h
        rol bx,cl
        add bx,ax
        jmp nextIter
nextCheck1:
        cmp al,61h
        jl valErr
        cmp al,66h
        jg valErr
        mov [si],al
        sub al,57h
        mov ah,00h
        rol bx,cl
        add bx,ax
        jmp nextIter
nextIter:
        inc si
        dec ch
        jnz  loop5
        jmp convert
valErr: 
    lea dx,HexInputErr
    dispStr
    jmp startAgain
endm 




.data
    multiplier dw 2710h,03E8h,0064h,000Ah,0001h
    originalBCD db 5 dup(0)
    originalHex db 4 dup(0)
    menu db 10,10,13,'----- MENU ------',10,10,13,'1.BCD TO HEX',10,13,'2.HEX TO BCD',10,13,'3.EXIT',10,10,13,'--------------- $'
    choice db 10,10,13,'Enter Your Choice: $'
    invalidchoice db 10,10,13,'Please Enter Valid Choice $'
    bcd db 10,10,13,'Enter 5 Digit BCD Number: $'
    limit db 10,10,13,'BCD Number Starting With 7 is Not Allowed $'
    result dw 0
    count db 0
    invalidBCD db 10,10,13,'Invalid BCD Number $'
    BCDstr db 10,10,13,'Original BCD Is: $'
    HexStr db 10,10,13,'Corresponding Hex Equivalent: $'
    HexIn db 10,10,13,'Enter Hex Number: $'
    HexDisp db 10,10,13,'Original Hex Number Is: $'
    HexRes db 10,10,13,'Corresponding BCD Conversion Is: $'
    HexInputErr db 10,10,13,'HEX number should be between (A-Z,a-z,0-9) $'
.code
    mov ax,@data
    mov ds,ax

    menu1:
        lea dx,menu
        dispStr

        lea dx,choice
        dispStr

        mov ah,01h
        int 21h

        cmp al,31h
        jne next
        call BtoH
        jmp menu1

        next:
            cmp al,32h
            jne next1
            call HtoB
            jmp menu1
        next1:
            cmp al,33h
            jne invalid
            mov ah,04ch
            int 21h
        invalid:
            lea dx,invalidchoice
            dispStr
            jmp menu1


        proc BtoH near

            mov ax,0000h
            mov bx,0000h
            mov cx,0000h
            mov dx,0000h
               
            again:
            lea dx,bcd
            dispStr
            mov ch,05h 
            lea di,originalBCD
            lea si,multiplier
            
                mov ah,01h
                int 21h
                dec ch
                jl err1    
                cmp al,36h
                jbe first
                lea dx,limit
                dispStr
                jmp again
                err1:
                    lea dx,invalidBCD
                    dispStr
                    jmp again
            first:
                sub al,30h
                mov ah,00h
                mov [di],al
                mov dx,[si]
                mul dx
                add bx,ax
                inc di
                inc si
                inc si
                
            loop1:
                mov ah,01h
                int 21h
                sub al,30h
                mov [di],al
                
                mov ah,00h
                mov dx,[si]
                mul dx

                add bx,ax
                inc si
                inc si
                inc di
                dec ch
                jnz loop1


                lea di,originalBCD
                lea dx,BCDstr
                dispStr
                mov ch,05h
                loop2:
                    mov dl,00h 
                    mov dl,[di]
                    add dl,30h
                    mov ah,02h
                    int 21h
                    inc di
                    dec ch
                    jnz loop2

                lea dx,HexStr
                dispStr
                mov cx,0404h
                ; mov bx,result    

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

                ret    
         BtoH endp

        proc HtoB near
            startAgain:
            inputHex
            convert:
            lea dx,HexDisp
            dispStr

            mov ch,04h
            lea si,originalHex
            loop6:
                mov dl,[si]
                mov ah,02h
                int 21h
                inc si
                dec ch
                jnz loop6
            mov cx,0404h
            mov ax,0000h
            lea si,originalHex
            
            ; mov bl,10h
            mov ch,04h
            lea dx,HexRes
            dispStr  
            mov ax,bx
            mov bx,0010
            mov ch,00    
            loop8:
                
                mov dx,0000h
                div bx
                push dx
                inc ch  
                cmp ax,0000h
                jne loop8
            loop10:
            
                mov dx,0000h
                pop dx
                add dl,30h 
                mov ah,02h
                int 21h 
                dec ch
                jnz loop10
        ret
        HtoB endp    
end