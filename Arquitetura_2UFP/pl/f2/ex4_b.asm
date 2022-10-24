.data 
MSG1: .asciiz "O valor final e \n"

.align 2
A: .word 1,3,5,7,9,11,13,15

.text
.globl main
main: 
addi $t1, $0, 1
add $t2, $0, $0

la $t4, A

while: slti $t0, $t1, 8
beq $t0, $0, exit

lw $t5, 0($t4)
addi $t4, $t4, 4
lw $t5, 0($t4)

add $t2, $t2, $t5
addi $t1, $t1, 1
j while

exit:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
move $a0, $t2
syscall

li $v0, 10
syscall