.data
MSG1: .asciiz "Insira o valor "
MSG2: .asciiz "Insira o pow "
RES1: .asciiz "Resultado "

.text
.globl main
main:
# $s0 - val
# $s1 - pow
# $s2 - result
li $v0, 4
la $a0, MSG1
syscall
li $v0, 5
syscall
move $s0, $v0
li $v0, 4
la $a0, MSG2
syscall
li $v0, 5
syscall
move $s1, $v0
jal power
add $s2, $v0, $0

Exit:
li $v0, 4
la $a0, RES1
syscall
li $v0, 1
move $a0, $s2 
syscall
li $v0, 10
syscall

power:
# $a0 - val
# $a1 - pow
add $sp, $sp, -8
sw $ra, 0($sp)
add $a0, $0, $s0
add $a1, $0, $s1
add $v0, $0, $a1
power_recur:
add $sp, $sp, -8
sw $ra, 0($sp)
beq $v0, 0 if
sw $v0, 4($sp)
add $v0, $v0, -1
jal power_recur
mul $v0, $v0, $a0
lw $ra, 0($sp)
add $sp, $sp 8
jr $ra
if:
addi $v0, $0, 1
lw $ra, 0($sp)
addi $sp, $sp, 8
jr $ra
