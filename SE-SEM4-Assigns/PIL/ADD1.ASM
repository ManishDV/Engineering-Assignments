.model small
.data
a db 02
b db 03
c db ?


.code
mov ax,@data
mov ds,ax
mov al,a
add al,b
add al,30h
mov c,al
mov dl,c
mov ah,02h
int 21h
mov ah,4ch
int 21h

end
