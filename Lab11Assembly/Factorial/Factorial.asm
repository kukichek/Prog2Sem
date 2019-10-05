.386
public @isOne@4
public @decrement@4
public @multiply@8
.model flat
.code

@isOne@4 proc

mov eax, [ecx]
cmp eax, 1
jne notOne

add ecx, 4
mov eax, [ecx]
cmp eax, 1
jne notOne

mov eax, 1
jmp procEnd

notOne:

mov eax, 0

procEnd:

ret

@isOne@4 endp

@decrement@4 proc

mov edx, 4
mov eax, [ecx + edx]
dec eax
mov [ecx + edx], eax

whileBegin:

cmp eax, 0
jge whileEnd

add eax, 10
mov [ecx + edx], eax
add edx, 4

mov eax, [ecx + edx]
dec eax
mov [ecx + edx], eax

jmp whileBegin

whileEnd:

mov edx, [ecx]
shl edx, 2
mov eax, [ecx + edx]

cmp eax, 0
jne procEnd

mov eax, [ecx]
dec eax
mov [ecx], eax

procEnd:

ret

@decrement@4 endp

@multiply@8 proc

mov eax, [ecx]
add eax, [edx]

push ebp
mov ebp, esp
sub esp, 3
sub esp, eax		; резервирование локальных переменных

mov [ebp - 4], ecx
mov [ebp - 8], edx

mov dword ptr [ebp - 12], eax 
mov ecx, eax
add eax, 3
shl eax, 2
neg eax

xor ebx, ebx

nullLoop:

mov [ebp + eax], ebx
add eax, 4

loop nullLoop		; обнуление локального массива переменных

mov ecx, [ebp - 8]
mov ecx, [ecx]

outLoop:

mov ebx, ecx
mov ecx, [ebp - 4]
mov ecx, [ecx]

inLoop:

mov eax, [ebp - 4]
mov eax, [eax + ecx*4]
cdq
mov edi, [ebp - 8]
mul dword ptr [edi + ebx*4]

mov esi, ecx
add esi, ebx
add esi, 2
shl esi, 2
neg esi

add [ebp + esi], eax

loop inLoop

mov ecx, ebx

loop outLoop		; перемножение массивов

mov ecx, [ebp - 12]
dec ecx
mov ebx, -16

normalLoop:

mov eax, [ebp + ebx]
cmp eax, 10
jl lastLoopStr

cdq
mov edi, 10
div edi
add [ebp + ebx - 4], eax
mov [ebp + ebx], edx

lastLoopStr:

sub ebx, 4

loop normalLoop		; нормализация массива

mov ecx, [ebp - 12]
add ecx, 4
shl ecx, 2
neg ecx

xor ebx, ebx

carry:

dec dword ptr [ebp - 12]
add ecx, 4
cmp [ebp + ecx], ebx
je carry		

inc dword ptr [ebp - 12]
					; перенос

mov ecx, [ebp - 12]
inc ecx
mov esi, 0
mov edi, -12

copyLoop:

mov eax, [ebp - 4]
mov ebx, [ebp + edi]
mov [eax + esi], ebx
add esi, 4
sub edi, 4

loop copyLoop		; копирование массивов

leave

ret

@multiply@8 endp

End