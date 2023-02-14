.data
ZERO:	.float 0.0
UM:	.float 1.0
QUATRO:	.float 4.0
CINCO:	.float 5.0
MSG1:	.asciiz "Resultado: "

.text
.globl main
main:
# $f2 -> i
# $f4 -> s
lwc1 $f2, ZERO
lwc1 $f4, ZERO
lwc1 $f6, QUATRO
lwc1 $f8, UM
lwc1 $f10, CINCO
while:	c.le.s $f2, $f6
	bc1f Exit
	lwc1 $f12, ZERO
	lwc1 $f14, ZERO
	sub.s $f12, $f10, $f2
	add.s $f14, $f14, $f2
	jal funct
	add.s $f4, $f4, $f0
	add.s $f2, $f2, $f8
	j while
	
Exit:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 2
mov.s $f12, $f4
syscall
li $v0, 10
syscall


funct:
# $f0 -> s
addi $sp, $sp, -16
sw $ra, 12($sp)
swc1 $f12, 0($sp)
swc1 $f14, 4($sp)
lwc1 $f0, ZERO
jal square
mul.s $f12, $f12, $f0
swc1 $f12, 8($sp)
lwc1 $f12, 4($sp)
jal square
lwc1 $f12, 8($sp)
mul.s $f14, $f14, $f0
sub.s $f0, $f12, $f14
lw $ra, 12($sp)
lwc1 $f14, 4($sp)
lwc1 $f12, 0($sp)
addi $sp, $sp, 16
jr $ra

square:
addi $sp, $sp, -4
swc1 $f12, 0($sp)
mul.s $f0, $f12, $f12
lwc1 $f12, 0($sp)
addi $sp, $sp, 4
jr $ra