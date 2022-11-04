.data
MSG1: .asciiz "Insira um valor\n"
MSG2: .asciiz "Insira o pow\n"
RES1: .asciiz "Resultado "

.text
.globl main
main:
# t1 - val
# t2 - pow
# s0 - resultado

li $v0, 4
la $a0, MSG1
syscall
li $v0, 5
syscall
add $t1, $v0, $0
li $v0, 4
la $a0, MSG2
syscall
li $v0, 5
syscall
add $t2, $v0, $0
jal power
add $s0, $v0, $0

exit:
li $v0, 4
la $a0, RES1
syscall
li $v0, 1
add $a0, $s0, $0
syscall
li $v0, 10
syscall

power:
add $a0, $t1, $0
add $a1, $t2, $0
recu:	add $sp, $sp, -4  # ra
	sw $ra, 0($sp)
	beq $a1, 0 if_true
	else:
	addi $a1, $a1, -1
	jal recu
	
	add $sp, $sp, 4
	mul $v0, $v0, $a0
	lw $ra, 0($sp)
	jr $ra
	if_true:
	addi $v0, $0, 1
	lw $ra, 0($sp)
	jr $ra 