.data
MSG1: .asciiz "O Valor final e = "

.text
.globl main
main:

# $s0 - i
# $s1 - s

add $s0, $0, $0
add $s1, $0, $0

loop: slti $t0, $s0, 10
beq $t0, 0 exit
jal sumsquare
add $s1, $s1, $v0
addi $s0, $s0, 1
j loop

exit: 
li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
move $a0, $s1
syscall

li $v0, 10
syscall

sumsquare:
addi $sp, $sp, -4
sw $s0, 0($sp)
addi $t0, $s0, 1
sw $t0, 4($sp)
lw $a0, 0($sp)
lw $a1, 4($sp)
mul $t2, $a0, $a0
mul $t3, $a1, $a1
add $v0, $t2, $t3
addi $sp, $sp, 4
jr $ra