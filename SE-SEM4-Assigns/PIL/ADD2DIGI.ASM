;FInal Program

.model small
input macro
 mov ah,01h
 int 21h
endm

displayMsg macro msg
 lea dx,msg
 mov ah,09h
 int 21h
endm

.data
   num1 db ?
   sum db ?
   msg1 db 10,13,'Enter no. of element : $'
   msg2 db 10,13,'Enter element : $'
   msg3 db 10,13,'Addition of array elements is $'
   count db ?
   array db 10 dup(?)
   carry db 0
.code
  mov ax,@data
  mov ds,ax
  displayMsg msg1
  input
  sub al,30h
  mov count,al
  mov ch,count
  ;---Input--
  lea si,array
  up1 : displayMsg msg2
        input
        sub al,30h
        jbe up2
        
 up2 : mov cl,04
       rol al,cl
       mov bl,al

       input
       sub al,30h
       jbe up3
      
  up3 : add al,bl
        mov [si],al
        inc si
        dec count
        jnz up1


  ;---------addition----
   mov sum,00h
   lea si,array
   mov count,ch
 ;----Display-----
 displayMsg msg3
 
   d1: mov al,[si]
       add al,sum
       daa
       mov sum,al
       inc si
       jnc d4
        add carry,01h
    d4:
        dec count
        jnz d1
       

    mov dl,carry
    add dl,30h
    mov ah,02h
    int 21h


 mov bl,sum
 mov cx,0204h
 d2: rol bl,cl
     mov dl,bl
     and dl,0fh
     cmp dl,09h
     jbe d3
     add dl,07h
  d3: add dl,30h
      mov ah,02h
      int 21h
      dec ch
      jnz d2


  mov ah,4ch
  int 21h
end
