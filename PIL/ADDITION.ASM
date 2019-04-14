.model small
.data
        n1 DW 230
        n2 DW 320
        n3 DW ?
.code
        mov ax,@data
        mov ds,ax
        mov ax,n1
        ADD ax,n2

        mov n3,ax
        mov ah,02h
        INT 21h

        mov ah,4ch
        INT 21h

END
