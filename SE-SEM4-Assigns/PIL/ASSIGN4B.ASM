
.model small

.data
    extrn str1:byte
    extrn str2:byte
    con db 25 dup('$')
    
    outStr1 db 10,10,13,'Concatenated String is: $'
    outStr2 db 10,10,13,'First String Is: $'
    outStr3 db 10,10,13,'Second String is: $'
    opStr db 10,10,13,'Entered String Is: $'
    cmpRes1 db 10,10,13,'Strings are  Not Equal$'
    cmpRes db 10,10,13,'Strings Are Equal$'
    subRes db 10,10,13,'Substring is present $'
    subError db 10,10,13,'Length Of Substring Should Be Less Than Original String$'
    subError1 db 10,10,13,'SubString Is Not Present$'
.code

    mov ax,@data
    mov ds,ax
    mov es,ax


    mov ah,04ch
    int 21h


    public displayStr

    displayStr proc far

    mov dx,offset opStr
    mov ah,09h
    int 21h


    mov dx,offset str1+2
    mov ah,09h
    int 21h
    ret
    displayStr endp



    public concatStr

    concatStr proc far

     mov dx,0000h
     mov ax,0000h
     mov bx,0000h
     mov cx,0000h
    	
     lea si,str1+2
     
     mov cl,[str1+1]
     mov bl,[str2+1]
     add dl,bl
     add dl,cl
     add dl,30h
     mov [con+1],dl
     lea di,con+2
     mov dl,00h
     mov al,00h
     mov ah,00h
     loop1:
        
        mov al,[si]
        mov [di],al
        inc si
        inc di
        dec cl
        jnz loop1
   
    lea si,str2+2
   
    loop2:
        
       mov al,[si]
       mov [di],al
       inc si
       inc di

       dec bl
       jnz loop2
  
    
    lea dx,outStr2
    mov ah,09h
    int 21h

    lea dx,str1+2
    mov ah,09h
    int 21h
            	
    lea dx,outStr3
    mov ah,09h
    int 21h
  
    lea dx,str2+2
    mov ah,09h
    int 21h
   
   lea dx,outStr1
    mov ah,09h
    int 21h
 
    lea dx,con+2
     mov ah,09h
    int 21h
   	

    ret
    concatStr endp

    public compare

    compare proc far
         mov al,[str1+1]
         mov dl,[str2+1]

         cmp al,dl
         je  check
         jne printError


      check:

           mov cl,al
           mov ch,00h

           lea si,str1+2
           lea di,str2+2

           repe cmpsb
           jz Result
           jnz printError

     printError:
         lea dx,outStr2
         mov ah,09h
         int 21h

        lea dx,str1+2
         mov ah,09h
         int 21h
            	
         lea dx,outStr3
         mov ah,09h
         int 21h
  
         lea dx,str2+2
         mov ah,09h
         int 21h

          mov dx,offset cmpRes1
          mov ah,09h
          int 21h
          jmp go
      Result:
         lea dx,outStr2
         mov ah,09h
         int 21h

        lea dx,str1+2
         mov ah,09h
         int 21h
            	
         lea dx,outStr3
         mov ah,09h
         int 21h
  
         lea dx,str2+2
         mov ah,09h
         int 21h

          mov dx,offset cmpRes
          mov ah,09h
          int 21h
          jmp go

     go:
        ret
    compare endp


    public subString

    subString proc far
         mov al,[str1+1]
         mov dl,[str2+1]

         cmp al,dl
         jg  check1
         jng printError1


      check1:

           mov dx,offset str1+1
           loop05:
                
                inc dx

                mov si,dx
                lea di,str2+2
                mov dl,[si]
                cmp dl,24h
                je print
                jne perform


           perform:
                mov cl,[str2+1]
                mov ch,00h

                repe cmpsb
                jnz loop05
                jz  Result1

      print:
            
         lea dx,subError1
         mov ah,09h
         int 21h

          jmp go1

     printError1:
         lea dx,subError
         mov ah,09h
         int 21h

          jmp go1
      Result1:
         lea dx,outStr2
         mov ah,09h
         int 21h

        lea dx,str1+2
         mov ah,09h
         int 21h
            	
         lea dx,outStr3
         mov ah,09h
         int 21h
  
         lea dx,str2+2
         mov ah,09h
         int 21h

          mov dx,offset subRes
          mov ah,09h
          int 21h
          jmp go1

     go1:
        ret
      subString endp
 

end
