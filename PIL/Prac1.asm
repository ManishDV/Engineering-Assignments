.model small

print macro
    mov ah,09h
    int 21h
endm

input macro
    mov al,00h
    mov ah,01h
    int 21h
endm

disp macro

    mov ah,02h
    int 21h

endm


.data
    
    arr db 10 dup(0)
    outstr1 db 10,10,13,'Enter Count Of Numbers You Want For Addition: $'
    outstr2 db 10,10,13,'Enter Number: $'
    outstr3 db 10,10,13,'Result Is: $'
    count db 0
    result db 0
.code

    mov ax,@data
    mov ds,ax

    lea dx,outstr1
    print

    input

    sub al,30h
    mov ch,al

    lea si,arr
    mov count,ch

    loop1:
        lea dx,outstr2
        print
        input
        cmp al,61h
        jl cont
        sub al,51h
        mov [si],al
        inc si
        dec ch
        jnz loop1
        jmp from    
        cont:
            cmp al,41h
            jl cont1
            sub al,31h
            mov [si],al
            inc si
            dec ch
            jnz loop1
            jmp from
        cont1:
            sub al,30h
            mov [si],al
            inc si
            dec ch
            jnz loop1
    from:
    mov ch,count
    
    lea si,arr
    lea dx,outstr3
    print
    mov ax,0000h
    mov bx,0000h
    mov dx,0000h
    mov al,00h
    loop2:
        mov dl,[si]
        add al,dl
        ;daa
        inc si
        dec ch
        jnz loop2
    
    ; mov result,al    
    mov bl,al
    mov cx,0204h

    do:
       rol bl,cl
       mov dl,bl 
       and dl,0fh
       cmp dl,09h
       jbe do1
       add dl,07h
    do1:
        add dl,30h
        disp
        dec ch  
        jnz do

    mov ah,04ch
    int 21h    

end