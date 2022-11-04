.data 
MSG1: .asciiz "Insira o valor \n"
RES1: .asciiz "Soma => "

.align 2
N: .space 4

.text
.globl main
main:
# t1 - endereço N
# t2 - N
# t3 - Soma
# t4 - i
add $t3, $0, $0
addi $t4, $0, 1
li $v0, 4
la $a0, MSG1
syscall
li $v0, 5
syscall
la $t1, N
sw $v0, 0($t1)
lw $t2, 0($t1)
loop:	slt $t0, $t2, $t4
	beq $t0, 1 exit_loop
	add $t3, $t3, $t4
	addi $t4, $t4, 1
	j loop
exit_loop:
li $v0, 4
la $a0, RES1
syscall
li $v0, 1
add $a0, $t3, $0
syscall
exit:
li $v0, 10
syscall