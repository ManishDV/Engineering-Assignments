.model small
.data
       
        info DB 'Enter Char: ',10,13,'$'
.code
        mov ax,@data
        mov ds,ax

        mov dx,OFFSET info
        mov ah,09h
        INT 21h

       
        mov ah,01h
        INT 21h

        mov dl,al
        mov ah,02h
        INT 21h
       
        mov ah,4CH
        INT 21h
END
