.386
public @len@4
public _countRomNum
public _isCorStr@8
.model flat
.data

clue db 'IVXLCDM'
capacity dd 1, 5, 10, 50, 100, 500, 1000

.code

@len@4 proc

cld
mov edi, ecx
mov ecx, 0FFFFFFFFh
mov al, 0

repne scasb
jz count

count:
not ecx
dec ecx
mov eax, ecx

ret

@len@4 endp

_countRomNum proc

xor eax, eax
push ebp 
mov ebp, esp

dec esp
mov [ebp - 4], eax

std
mov ebx, [ebp + 8]
mov esi, [ebp + 12]
add esi, ebx
dec esi
mov ah, 'I'

.while ebx > 0
	lodsb

	cld
	lea edi, clue
	mov ecx, 7
	repne scasb
	neg ecx
	add ecx, 6
	lea edi, capacity
	mov edx, [edi + ecx*4]

	xchg al, ah

	lea edi, clue
	mov ecx, 7
	repne scasb
	neg ecx
	add ecx, 6
	lea edi, capacity

	cmp edx, [edi + ecx*4]
	jge notChange

	neg edx

	notChange:

	add [ebp - 4], edx

	dec ebx
	std
.endw

mov eax, [ebp - 4]
mov esp, ebp
pop ebp
ret

_countRomNum endp

_isCorStr@8 proc

push ebp 
mov ebp, esp

cld
mov ebx, [ebp + 8]
mov esi, [ebp + 12]

.while ebx > 0
	lodsb
	mov ecx, 7
	lea edi, clue

	repne scasb
	je catch

	xor eax, eax
	mov esp, ebp
	pop ebp 
	ret 8

	catch:

	dec ebx
.endw

mov eax, 1 
mov esp, ebp
pop ebp
ret 8

_isCorStr@8 endp

end