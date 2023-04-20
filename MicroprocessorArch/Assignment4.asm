section .data
	
	msg db 10,10,"Assignment A-4 Conversion of BCD TO HEX AND HEX TO BCD"
	msg_len equ $-msg
	msg2 db 10,10,"1-HEX TO BCD 2-BCD TO HEX 3-EXIT"
	msg2_len equ $-msg2
	msg3 db 10,10,"HEX TO BCD"
	msg3_len equ $-msg3
	msg4 db 10,10,"BCD TO HEX"
	msg4_len equ $-msg4


section .bss

	string resb 50
	string1 equ $-string

section .text
	
	global _start
	
	
%macro Print 2

	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro Read 2

	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro exit 0
	mov rax,60
	mov rdi,0
	syscall
%endmacro

_start:
	Print msg,msg_len
	Print msg2,msg2_len
	Read string,string1
	
	mov bl,byte[string]
	cmp bl,'2'
	je l2
	
	mov bl,byte[string]
	cmp bl,'1'
	je l1
	
	
	
	l2:Print msg4,msg4_len
	exit
	l1:Print msg3,msg3_len
	   exit
	mov rax,60
	mov rdi,0
	syscall
	
