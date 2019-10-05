.686 
public @OutDecision@8
.model flat 
.code 

EXTRN  _outDivisionBy0 : proc
EXTRN  _outNum : proc

@OutDecision@8 proc

	cmp cx, dx
	jg _gr
	je _equal

	cmp cx, -1
	je _nul

	mov ax, dx
	inc cx
	cwd
	idiv cx
	mov cx, ax

	push cx
	call _outNum
	pop cx

	jmp _end

_equal:
	
	mov cx, 4
	push cx
	call _outNum
	pop cx


	jmp _end

_gr:
	cmp dx, 0
	je _nul

	mov ax, cx
	imul ax, cx
	imul ax, cx
	mov cx, 5
	sub ax, cx
	mov cx, dx
	cdq
	idiv cx
	mov cx, ax

	push cx
	call _outNum
	pop cx

	jmp _end

_nul:

	call _outDivisionBy0

_end:
	
	ret

@OutDecision@8 endp
End 