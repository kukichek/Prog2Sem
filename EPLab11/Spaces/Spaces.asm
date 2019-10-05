.386
public @getLength@4
public @delFSpaces@8
public @delLSpaces@8
public @delSpaces@8
public @countWords@8
.model flat
.data

maxL dd 100000
tempStr db 100000 dup (?)

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

@delFSpaces@8 proc

cld
mov esi, edx
mov edi, edx
mov edx, ecx

spaceLoop:

lodsb
cmp al, 20h

jne outLoop

loop spaceLoop

outLoop:

mov eax, ecx

cmp ecx, 0
jne notNull

mov byte ptr [edi], 0
mov eax, 0
ret

notNull:

cmp edx, ecx
jne delSpaces

ret

delSpaces:

dec esi

mov ecx, eax
inc ecx

rep movsb

ret

@delFSpaces@8 endp

@delLSpaces@8 proc

cmp ecx, 0
jne notNull

mov eax, 0
ret

notNull:

std
mov esi, edx
mov edi, edx
add edi, ecx
dec edi
mov al, 20h
repe scasb
add edi, 2
cld
mov byte ptr [edi], 0
mov eax, edi
sub eax, esi

ret

@delLSpaces@8 endp

@delSpaces@8 proc

cmp ecx, 0
jne notNull

ret

notNull:

mov al, 20h

mov edi, edx
add edi, ecx
dec edi
mov edx, edi

.while ecx > 0
	std
	repne scasb

	cmp ecx, 0
	je outW

	inc edi
	sub edx, edi
	add edx, 2
	inc ecx

	mov esi, edi
	repe scasb
	
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

@delSpaces@8 endp

@countWords@8 proc

mov edi, edx
xor ebx, ebx
mov al, 20h
cld

.while ecx > 0

repne scasb
inc ebx

.endw

mov eax, ebx
ret

@countWords@8 endp

end