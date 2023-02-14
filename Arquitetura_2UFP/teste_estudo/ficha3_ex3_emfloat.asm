.data
MSG1:	.asciiz "Indique um número inteiro positivo: "
MSG2:	.asciiz "O factorial (iterativo) de "
MSG3:	.asciiz "O factorial (recursivo) de "
E:	.asciiz " e "
ENTER:	.asciiz "\n"
ZERO:	.float 0.0
UM:	.float 1.0

.text
.globl main
main:
# $s0 -> n
# $f4 -> facti
# $f6 -> factr
li $v0, 5
syscall
move $s0, $v0
move $a0, $s0
jal fact_iter
mov.s $f4, $f0
move $a0, $s0
mtc1 $a0, $f12
cvt.s.w $f12, $f12
jal fact_recu
mov.s $f6, $f0

li $v0, 4
la $a0, MSG2
syscall
li $v0, 1
move $a0, $s0
syscall
li $v0, 4
la $a0, E
syscall
li $v0, 2
mov.s $f12, $f4
syscall
li $v0, 4
la $a0, ENTER
syscall

li $v0, 4
la $a0, MSG3
syscall
li $v0, 1
move $a0, $s0
syscall
li $v0, 4
la $a0, E
syscall
li $v0, 2
mov.s $f12, $f6
syscall
li $v0, 4
la $a0, ENTER
syscall
li $v0, 10
syscall

fact_iter:
# t1 -> i
# f8 -> s
# f10 -> i (float)
addi $sp, $sp, -4
sw $s0, 0($sp)
lwc1 $f8, UM
add $t1, $0, $a0
for:	beq $t1, 0, exit_for
	mtc1 $t1, $f10
	cvt.s.w $f10, $f10
	mul.s $f8, $f8, $f10
	add, $t1, $t1, -1
	j for
exit_for:
mov.s $f0, $f8
lw $s0, 0($sp)
addi $sp, $sp, 4
jr $ra

fact_recu:
addi $sp, $sp, -8
sw $ra, 0($sp)
lwc1 $f8, UM
lwc1 $f10, UM
c.eq.s $f12, $f10
bc1t case0
case1:
swc1 $f12, 4($sp)
sub.s $f12, $f12, $f8
jal fact_recu
lwc1 $f12, 4($sp)
mul.s $f0, $f12, $f0
lw $ra, 0($sp)
addi $sp, $sp, 8
jr $ra
case0:
lwc1 $f0, UM
lw $ra, 0($sp)
addi $sp, $sp, 8
jr $ra