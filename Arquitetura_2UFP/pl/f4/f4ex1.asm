.data
MSG1: .asciiz "The final value is "

.text
.globl main
main:
add $t1, $0, $0
add $t2, $0, $0
for:	slti $t0, $t1, 10
	beq $t0, $0 exit
	add $t2, $t2, $t1
	addi $t1, $t1, 1
	j for
exit:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
add $a0, $t2, $0
syscall
li $v0, 10
syscall