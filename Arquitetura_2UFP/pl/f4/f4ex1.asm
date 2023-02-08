.data
MSG1: .asciiz "The final value is "

.text
.globl main
main:
add $t0, $0, $0
add $s0, $0, $0
for:	beq $t0, 10 exit
	add $s0, $t0, $s0	
	addi $t0, $t0, 1
	j for
exit:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
add $a0, $s0, $0
syscall
li $v0, 10
syscall