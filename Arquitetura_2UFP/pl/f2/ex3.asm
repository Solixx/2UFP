.data
MSG1: .asciiz "Insira o valor \n"
Soma: .asciiz "Soma => "

.align 2
N: .space 4

.text
.globl main
main: 
add $t0, $zero, $zero
add $t2, $zero, $zero
li $v0, 4
la $a0, MSG1
syscall
li $v0, 5
syscall
la $t1, N
sw $v0, 0($t1)
#lw $t1, 0($t1)

Loop: 
addi $t0, $t0, 1
add $t2, $t2, $t0
bne $t0, $v0 Loop

li $v0, 4
la $a0, Soma
syscall
li $v0, 1
move $a0, $t2
syscall

Exit:
li $v0, 10
syscall
