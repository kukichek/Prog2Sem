.386
public @getLength@4
public @delBraces@8
.model flat
.data

maxL dd 100000

.code

@getLength@4 proc

mov esi, ecx
mov al, 0
mov ecx, maxL
cld

nullCmp:

lodsb
cmp al, 0

jz outLoop

loop nullCmp

outLoop:

mov eax, maxL
sub eax, ecx

ret

@getLength@4 endp

@delBraces@8 proc

cmp ecx, 0
jne notNull

ret

notNull:

mov edi, edx
add edi, ecx
dec edi
mov edx, edi

.while ecx > 0
	mov al, 29h
	std
	repne scasb

	cmp ecx, 0
	je outW

	inc edi
	inc ecx
	sub edx, edi
	add edx, 2

	mov al, 28h
	mov esi, edi
	repne scasb

	add edi, 2
	add ecx, 2

	cld
	mov ebx, edx
	xchg edx, ecx
	rep movsb
	mov ecx, edx
	mov edx, ebx
	dec edi
	mov ebx, edx
	mov edx, edi
	dec edx
	sub edi, ebx
	dec ecx

.endw

outW:

cld

ret

@delBraces@8 endp

end