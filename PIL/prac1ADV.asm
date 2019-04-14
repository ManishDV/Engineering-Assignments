.model small

dispStr macro msg
    lea dx,msg
    mov ah,09h
    int 21h
endm 

.data
    original db 10 dup(0)
    firststr db 10,10,13,'Enter Total Number: $'
    multiplier db 000Ah,0001h

    secstr db 10,10,13,'Enter Number: $'
    thrd db 10,10,13,'Numbers Are: $'
    count db 0

    addres db 10,10,13,'Addition Is: $'
    result db 00h
    count2 db 0h
.code   

    mov ax,@data
    mov ds,ax

    dispStr firststr

    mov ah,01h
    int 21h

    sub al,30h
    mov ch,al
    mov count,ch
    mov bx,0000h
    lea di,original
    loop1:
        dispStr secstr
        mov cl,02h 
        lea si,multiplier
        loop2:
            mov ah,01h
            int 21h
            mov ah,00h
            sub al,30h
            das
            mov dl,[si]
            mul dl
            add bl,al
            daa
            inc si
            dec cl
            jnz loop2
        mov [di],bl
        mov bl,00h
        inc di   
        dec ch
        jnz loop1  

        dispStr thrd
        mov ah,count
        mov count2,ah
        lea di,original
        mov cx,0204h
        for1:
            mov bx,0000h
            mov ch,02h
            mov bl,[di]
            loop4:
                rol bl,cl
                mov dl,bl
                and dl,0fh
                cmp dl,09h
                jbe loop5
                add dl,07h
            loop5:
                add dl,30h
                mov ah,02h 
                int 21h
                dec ch
                jnz loop4 

            mov dl,20h
            mov ah,02h 
            int 21h   
            inc di
            dec count
            jnz for1      

            dispStr addres
            mov ch,count2
            
            lea si,original
            loop6:
                 mov al,[si]
                 add result,al
                 inc si
                 dec ch
                 jnz loop6   
            mov bx,0000h
            mov bl,result
            mov cx,0204h
            mov dx,0000h
            loop7:
                  rol bl,cl
                  mov dl,bl
                  and dl,0fh
                  cmp dl,09h
                  jbe loop8
                  add dl,07h
            loop8:
                  add dl,30h
                  mov ah,02h 
                  int 21h
                  dec ch
                  jnz loop7        

        mov ah,04ch
        int 21h

end