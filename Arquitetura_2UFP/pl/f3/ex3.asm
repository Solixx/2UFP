.data
MSG1: .asciiz "Indique um número inteiro positivo: "
RES1: .asciiz "o factorial (iterativo) "
RES1_cont: .asciiz " é "
RES2: .asciiz "o factorial (recursivo) "
RES2_cont: .asciiz " é "

.text
.globl main
main:
# $s0 - n
# $s1 - facti
# $s2 - factr

add $s0, $0, $0
add $s1, $0, $0
add $s2, $0, $0

li $v0, 4
la $a0, MSG1
syscall
li $v0, 5
syscall
add $s0, $0, $v0
jal fact_iter
add $s1, $0, $v0
jal fact_recu
add $s2, $0, $v0

Exit:
li $v0, 4
la $a0, RES1
syscall
li $v0, 1
move $a0, $s0
syscall
li $v0, 4
la $a0, RES1_cont
syscall
li $v0, 1
move $a0, $s1 
syscall

li $v0, 4
la $a0, RES2
syscall
li $v0, 1
move $a0, $s0
syscall
li $v0, 4
la $a0, RES2_cont
syscall
li $v0, 1
move $a0, $s2 
syscall

li $v0, 10
syscall

fact_iter:
# $t1 - i
# $t2 - s
add $sp, $sp, -4
sw $ra, 0($sp)
add $a0, $0, $s0
addi $t2, $0, 1
add $t1, $0, $a0
for: 
slt $t0, $0, $t1
beq $t0, 0 for_exit
	mul $t2, $t2, $t1
	add $t1, $t1, -1
j for
for_exit:
add $sp, $sp, 4
add $v0, $0, $t2
jr $ra

fact_recu:
add $a0, $0, $s0
add $v0, $0, $0

recu: addi $sp, $sp, -8
sw $ra, 0($sp)
beq $a0, 0 case0
case1:
#add $v0, $0, $v0
sw $a0, 4($sp)
addi $a0, $a0, -1
#addi $sp, $sp, 8
jal recu
lw $a0, 4($sp)
mul $v0, $a0, $v0
#add $v0, $a0, $0
lw $ra, 0($sp)
addi $sp, $sp, 8
jr $ra
case0:
addi $v0, $0, 1
lw $ra, 0($sp)
addi $sp, $sp, 8
jr $ra