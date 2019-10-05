.386
public @isPal@8
.model flat
.code

@isPal@8 proc

xor ebx, ebx
dec ecx

.while ebx < ecx
	mov esi, [edx + ebx*4]
	cmp esi, [edx + ecx*4]
	je _eq
		xor eax, eax
		ret
	_eq:
	inc ebx
	dec ecx
.endw

mov eax, 1

ret

@isPal@8 endp
end