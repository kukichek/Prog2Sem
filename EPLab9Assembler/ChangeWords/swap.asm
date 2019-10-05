.386 
PUBLIC _WordSwap@8
.model flat 
.code 
_WordSwap@8 proc
	push ebp  
	mov ebp,esp  

	mov esi,[ebp+8] ;адрес первого числа  
	mov edi,[ebp+12] ;адрес второго числа  

	mov ax, word ptr [esi]  ;первое число  
	xchg ax, word ptr [edi]    
	mov word ptr [esi], ax  

	pop ebp  
	ret 8
_WordSwap@8 endp
End 