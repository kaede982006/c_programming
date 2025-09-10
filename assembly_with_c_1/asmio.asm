section .text
	;global settings
	global asm_print
	global asm_inptr

	;asm_print
	asm_print:
	push rdi
	call get_length

	mov rdx, rax
	pop rsi
	mov rdi, 1
	mov rax, 1
	syscall
	
	ret

	get_length:
	xor rax, rax
	.print_loop:
	cmp byte [rdi+rax], 0x00
	je .print_end
	inc rax
	jmp .print_loop
	.print_end:
	ret

	;asm_inptr
	asm_inptr:
	mov rax, 0
	mov rbx, rsi
	
	push rsi
	lea rsi, [rdi]
	mov rdi, 0
	pop rbx
	mov rdx, rbx
	syscall

	xor rbx, rbx
	.inptr_loop:
	cmp byte [rsi+rbx], 0x0A
	je .inptr_end
	inc rbx
	jmp .inptr_loop
	.inptr_end:
	mov byte [rbx+rsi], 0x00
	ret
