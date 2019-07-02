input macro
 mov ah,01h
 int 21h
endm

disp macro
 mov ah,02h
 int 21h
endm

dispstr macro msg
 lea dx,msg
 mov ah,09h
 int 21h
endm

.model small
.data
   array db 10 dup(?)
   msg1 db 10,13,'Enter number of elements : $'
   msg2 db 10,13,'Enter elements $'
   msg3 db 10,13,'Elements are : $'
   msg4 db 10,13,'Addition of array elements is : $'
   count db ?
   sum db 00h
.code

 mov ax,@data
 mov ds,ax

 ;Enter no. of elements
 dispstr msg1
 input
 mov count,al
 sub count,30h

 ;Elements 
 lea si,array
 mov ch,count

 dispstr msg2

 loop1:
        input
        mov [si],al
        inc si
        dec ch
        jnz loop1

  ;Display elements
  mov ch,count
  lea si,array

  dispstr msg3
  loop2 : mov dl,[si]
          disp
          mov dl,20h
          disp
          inc si
          dec ch
          jnz loop2

  mov ch,count
  lea si,array

  ;Additiion of array elements
  mov al,00h

  dispstr msg4
  loop3: mov al,[si]
         cmp al,39h
         jg up1
         sub al,30h
         jmp up4
     up1: cmp al,46h
          jg up2
          sub al,37h
          jmp up4
    up2 :
         sub al,57h
    up4: add al,sum
        ; daa
         mov sum,al
         inc si
         dec ch
         jnz loop3
         
  ;Diplaying 2 digit no.
  mov bl,sum
  mov cx,0204h
  loop4: rol bl,cl
         mov dl,bl
         and dl,0fh
         cmp dl,09h
         jbe data
         add dl,07h
   data: add dl,30h
         disp
         dec ch
         jnz loop4
         
 mov ah,4ch
 int 21h

end
