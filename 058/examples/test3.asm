; DATA
segment	.data
; ALIGN
align	4
; LABEL j
j:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL _L1
_L1:
; SSTRING (value omitted -- see below)
	db	"ola", 0
; DATA
segment	.data
; SADDR _L1
	dd	_L1
; TEXT
segment	.text.func0
; ALIGN
align	4
; LABEL func0
func0:
; ENTER 0
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
; ADDR j
	push	dword $j
; LDINT
	pop	eax
	push	dword [eax]
; CALL prints
	call	prints
; TRASH 4
	add	esp, 4
; CALL println
	call	println
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
; GLOBAL f, :object
global	f:object
; LABEL f
f:
; SADDR func0
	dd	func0
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
; CALL func0
	call	func0
