; TEXT
segment	.text._func0
; ALIGN
align	4
; LABEL _func0
_func0:
; ENTER 0
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
; LOCAL 8
	lea	eax, [ebp+8]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; INT 1
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; STFVAL32
	pop	eax
; JMP _L1
	jmp	dword _L1
        ;; after body 
; LABEL _L1
_L1:
; LEAVE
	leave
; RET
	ret
; DATA
segment	.data
; ALIGN
align	4
; GLOBAL f, :object
global	f:object
; LABEL f
f:
; SADDR _func0
	dd	_func0
; TEXT
segment	.text._func1
; ALIGN
align	4
; LABEL _func1
_func1:
; ENTER 0
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
; LOCAL 8
	lea	eax, [ebp+8]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; CALL 
	call	
; TRASH 4
	add	esp, 4
; LDFVAL32
	push	eax
; STFVAL32
	pop	eax
; JMP _L2
	jmp	dword _L2
        ;; after body 
; LABEL _L2
_L2:
; LEAVE
	leave
; RET
	ret
; DATA
segment	.data
; ALIGN
align	4
; GLOBAL g, :object
global	g:object
; LABEL g
g:
; SADDR _func1
	dd	_func1
; TEXT
segment	.text
; ALIGN
align	4
; GLOBAL _main, :function
global	_main:function
; LABEL _main
_main:
; ENTER 0
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
; ADDR f
	push	dword $f
; LDINT
	pop	eax
	push	dword [eax]
; INT 3
	push	dword 3
; CALL _func1
	call	_func1
; TRASH 8
	add	esp, 8
; LDFVAL32
	push	eax
; CALL printi
	call	printi
; TRASH 4
	add	esp, 4
; CALL println
	call	println
; INT 0
	push	dword 0
; STFVAL32
	pop	eax
; JMP _L3
	jmp	dword _L3
        ;; after body 
; LABEL _L3
_L3:
; LEAVE
	leave
; RET
	ret
; EXTERN printi
extern	printi
; EXTERN println
extern	println
