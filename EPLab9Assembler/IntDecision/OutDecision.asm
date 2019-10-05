.686 
public @OutDecision@8
.model flat 
.code 

EXTRN  _outDivisionBy0 : proc
EXTRN  _outNum : proc

@OutDecision@8 proc

	cmp ecx, edx
	jg _gr
	je _equal

	cmp ecx, -1
	je _nul

	mov eax, edx
	inc ecx
	cdq
	idiv ecx
	mov ecx, eax

	push ecx
	call _outNum
	pop ecx

	jmp _end

_equal:
	
	mov ecx, 4
	push ecx
	call _outNum
	pop ecx

	jmp _end

_gr:
	cmp edx, 0
	je _nul

	mov eax, ecx
	imul eax, ecx
	imul eax, ecx
	mov ecx, 5
	sub eax, ecx
	mov ecx, edx
	cdq
	idiv ecx
	mov ecx, eax

	push ecx
	call _outNum
	pop ecx

	jmp _end

_nul:

	call _outDivisionBy0

_end:
	
	ret

@OutDecision@8 endp
End 