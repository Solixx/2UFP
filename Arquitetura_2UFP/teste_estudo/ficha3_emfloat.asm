.data
ZERO:	.float 0.0
NOVE:	.float 9.0
UM:	.float 1.0
MSG1:	.asciiz "Resultado: "

.text
.globl main
main:
lwc1 $f2, ZERO
lwc1 $f4, ZERO
lwc1 $f6, NOVE
lwc1 $f8, UM
lwc1 $f10, ZERO
lwc1 $f12, ZERO
lwc1 $f14, ZERO
while:	c.le.s $f2, $f6
	bc1f Exit
	lwc1 $f12, ZERO
	lwc1 $f14, ZERO 
	add.s $f12, $f12, $f2
	add.s $f2, $f2, $f8
	add.s $f14, $f14, $f2
	jal sumsquare
	add.s $f4, $f4, $f0
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

sumsquare:
addi $sp, $sp, -8
swc1 $f12, 0($sp)
swc1 $f14, 4($sp)
mul.s $f12, $f12, $f12
mul.s $f14, $f14, $f14
add.s $f0, $f12, $f14
lwc1 $f12, 0($sp)
lwc1 $f14, 4($sp)
addi $sp, $sp, 8
jr $ra
