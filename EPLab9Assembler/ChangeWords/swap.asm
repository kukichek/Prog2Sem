.386 
PUBLIC _WordSwap@8
.model flat 
.code 
_WordSwap@8 proc
	push ebp  
	mov ebp,esp  

	mov esi,[ebp+8] ;����� ������� �����  
	mov edi,[ebp+12] ;����� ������� �����  

	mov ax, word ptr [esi]  ;������ �����  
	xchg ax, word ptr [edi]    
	mov word ptr [esi], ax  

	pop ebp  
	ret 8
_WordSwap@8 endp
End 