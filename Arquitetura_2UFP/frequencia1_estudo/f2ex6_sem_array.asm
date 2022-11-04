.data
RES1: .asciiz "Resultado = "

.text
.globl main
main:
# $t1 - N
# $t2 - i
# $t3 - soma
li $v0, 5
syscall
add $t1, $v0, $0
add $t2, $0, $0
loop:	slt $t0, $t2, $t1
	beq $t0, 0 exit
	li $v0, 5
	syscall
	slti $t0, $v0, 0
	beq $t0, 1 skip
	add $t3, $t3, $v0
	skip:
	addi $t2, $t2, 1
	j loop
exit:
li $v0, 4
la $a0, RES1
syscall
li $v0, 1
add $a0, $t3, $0
syscall
li $v0, 10
syscall