.386
public @findMaxRow@8
public @findMinRow@8
public _swapRows
.model flat
.code

@findMaxRow@8 proc

mov edi, edx
mov eax, ecx
cdq
mul ecx
mov ebx, eax

.while ebx > 0
	xor eax, eax
	dec ebx

	shl eax, 2
	shl ebx, 2

	mov esi, [edi + eax]
	cmp esi, [edi + ebx]
	jge _gr

	mov eax, ebx

	_gr:

	shr eax, 2
	shr ebx, 2
.endw

div ecx

ret

@findMaxRow@8 endp

@findMinRow@8 proc
@findMinRow@8 endp

_swapRows proc
_swapRows endp

end