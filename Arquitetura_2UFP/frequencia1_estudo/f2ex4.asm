.data
MSG1: .asciiz "O valor final é "

.align 2
N: .word 1,3,5,7,9,11,13,15

.text
.globl main
main:
# $t1 - i
# $t2 - s
# t3 - endereço de N
# t4 - valor N[i]

add $t1, $0, $0
la $t3, N
for:	slti $t0, $t1, 8
	beq $t0, 0 exit
	lw $t4, 0($t3)
	add $t2, $t2, $t4
	add $t3, $t3, 4
	addi $t1,$t1 ,1
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