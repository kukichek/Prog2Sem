.686 
public _OutDecision
.model flat 
.code 

EXTRN  _outEmptySet : proc
EXTRN  _outR : proc
EXTRN  _outNum : proc

_OutDecision proc

	push ebp
	mov ebp,esp
	mov eax,[ebp+8] ;адрес первого числа
	mov ecx,[ebp+12] ;адрес второго числа

	cmp eax, 0
	je nullA

	fild dword ptr [ebp + 12]
	fild dword ptr [ebp + 8]
	fdivp 
	fchs

	fstp dword ptr [ebp+8]
	push [ebp+8]
	call _outNum
	pop eax

	jmp ifEnd

nullA:

	cmp ecx, 0
	je nullB

	call _outEmptySet
	
	jmp ifEnd

nullB:

	call _outR

ifEnd:

	pop ebp
	ret

_OutDecision endp
End 