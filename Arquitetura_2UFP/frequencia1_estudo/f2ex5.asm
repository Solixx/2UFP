.data 
SOMA1: .asciiz "Soma par = "
SOMA2: .asciiz "Soma impar = "
RES1: .asciiz "Resultado = "

.align 2
Vector: .space 80

.text
.globl main
main:
# $t1 - valor de N
# $t2 - endereço de Vector
# $t3 - valor de Vector
# $t4 - soma impar
# $t5 - soma par
# $t6 - endereços do Vetor
# $t7 - i
add $t7, $0, $0
la $t2, Vector
add $t6, $t2, $0
li $v0, 5
syscall
slti $t0, $v0, 20
beq $t0, 0 exit
add $t1, $v0, $0
loop_guardar:	slt $t0, $t7, $t1
		beq $t0, 0 exit_loop_guardar
		li $v0, 5
		syscall
		sw $v0, 0($t6)
		addi $t6, $t6, 4
		addi $t7, $t7, 1
		j loop_guardar
exit_loop_guardar:
add $t6, $t2, $0
add $t7, $0, $0
loop_par:	slt $t0, $t7, $t1
		beq $t0, 0 exit_loop_par
		lw $t3, 0($t6)
		add $t4, $t4, $t3
		addi $t6, $t6, 8
		addi $t7, $t7, 2
		j loop_par
exit_loop_par:
add $t6, $t2, $0
add $t7, $0, $0
loop_impar:	slt $t0, $t7, $t1
		beq $t0, 0 exit_loop_impar
		lw $t3, 4($t6)
		add $t5, $t5, $t3
		addi $t6, $t6, 8
		addi $t7, $t7, 2
		j loop_impar
exit_loop_impar:
exit:
li $v0, 4
la $a0, SOMA1
syscall
li $v0, 1
add $a0, $t4, $0
syscall
li $v0, 4
la $a0, SOMA2
syscall
li $v0, 1
add $a0, $t5, $0
syscall
li $v0, 4
la $a0, RES1
syscall
sub $t5, $t4, $t5
li $v0, 1
add $a0, $t5, $0
syscall
li $v0, 10
syscall
