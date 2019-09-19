.model small
.data
        n1 db 04h
        n2 db 05h
        n3 db 02h
        n4 dw 08h
        msg db 10,13, 'Addition Is: ' ,'$'
        msg1 db 10,13, 'Substraction Is: ','$'

        msg2 db 10,13,'Multiplication Is:','$'
        msg3 db 10,13,'Division Is with ','$'
        msg4 db ' Quotiont = ','$'
        msg5 db  ' and Remainder =','$'

.code
        mov ax,@data
        mov ds,ax

        mov al,n1
        ADD al,n2

        ADD al,30h

        mov dx,OFFSET msg
        mov ah,09h
        INT 21h

        mov dl,al
        mov ah,02h
        INT 21h

        mov al,n2
        SUB al,n1
        ADD al,30h

        mov dx,OFFSET msg1
        mov ah,09h
        INT 21h

        mov dl,al
        mov ah,02h
        INT 21h

        mov al,n1
        MUL n3
        ADD al,30h

        mov dx,OFFSET msg2
        mov ah,09h
        INT 21h

        mov dl,al
        mov ah,02h
        INT 21h

        mov ax,0000h
        mov al,n1
        DIV n3

        ADD al,30h
        ADD ah,30h

        mov dx,OFFSET msg3
        mov ah,09h
        INT 21h

        mov dx,OFFSET msg4
        mov ah,09h
        INT 21h
        
        mov dl,al
        mov ah,02h
        INT 21h

        mov dx,OFFSET msg5
        mov ah,09h
        INT 21h

        mov dh,ah 
        mov ah,02h
        INT 21h


        mov ah,4ch
        INT 21h
 end
                   
