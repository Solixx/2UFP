.data
MSG0:	.asciiz "Indique um numero inteiro positivo: \n"
MSG1:	.asciiz "O fatorial (iterativo) de "
MSG1_2:	.asciiz " é "
MSG2:	.asciiz "\nO fatorial (recursivo) de "
MSG2_2:	.asciiz " é "

.text
.globl main
main:
# t1 - n
# t2 - fati
# t3 - factr

add $t1, $0, $0
li $v0, 4
la $a0, MSG0
syscall
li $v0, 5
syscall
add $t1, $v0, $0
jal fact_iter
add $t2, $v0, $0
jal fact_recu
add $t3, $v0, $0

exit:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
add $a0, $t1, $0
syscall
li $v0, 4
la $a0, MSG1_2
syscall
li $v0, 1
add $a0, $t2, $0
syscall
li $v0, 4
la $a0, MSG2
syscall
li $v0, 1
add $a0, $t1, $0
syscall
li $v0, 4
la $a0, MSG2_2
syscall
li $v0, 1
add $a0, $t3, $0
syscall
li $v0, 10
syscall

fact_iter:
# a0 - n
# t4 - i
# t5 - s
add $a0, $t1, $0
addi $t5, $0, 1
add $t4, $a0, $0
for:	slt $t0, $0, $t4
	beq $t0, 0 exit_foor 
	mul $t5, $t5, $t4
	addi $t4, $t4, -1
	j for

exit_foor:
add $v0, $t5, $0
jr $ra

fact_recu:

add $a0, $t1, $0
recu:	add $sp, $sp, -8  # ra, n 
	sw $ra, 0($sp)
	beq $a0, $0 case0
	case1:
	sw $a0, 4($sp)
	add $a0, $a0, -1
	jal recu
	add $sp, $sp, 8
	lw $a0, 4($sp)
	mul $v0, $v0, $a0
	lw $ra, 0($sp)
	jr $ra
	case0:
	addi $v0, $0, 1
	lw $ra, 0($sp)
	jr $ra
