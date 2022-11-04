.data
RES1: .asciiz "Resultado = "

.align 2
Vector: .space 80

.text
.globl main
main:
# $t1 - N
# $t2 - i
# $t3 - endereço de Vector
# $t4 - endereços do Vector
# $t5 - soma
# $t6 - valor do Vector
la $t3, Vector
add $t4, $t3, $0
li $v0, 5
syscall
add $t1, $v0, $0
add $t2, $0, $0
loop_guardar:	slt $t0, $t2, $t1
		beq $t0, 0 exit_loop_soma
		li $v0, 5
		syscall
		sw $v0, 0($t4)
		addi $t4, $t4, 4
		addi $t2, $t2, 1
		j loop_guardar
exit_loop_soma:
add $t4, $t3, $0
add $t2, $0, $0
loop_soma:	slt $t0, $t2, $t1
		beq $t0, 0 exit
		lw $t6, 0($t4)
		slti $t0, $t6, 0
		beq $t0, 1 skip
		add $t5, $t5, $t6
		skip:
		addi $t4, $t4, 4
		addi $t2, $t2, 1
		j loop_soma
exit:
li $v0, 4
la $a0, RES1
syscall
li $v0, 1
add $a0, $t5, $0
syscall
li $v0, 10
syscall
