.data
MSG1:	.asciiz "Insira um numero: "
RES:	.asciiz "Resultado: "
ZERO:	.float 0.0
UM:	.float 1.0

.text
.globl main
main:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 6
syscall
mov.s $f2, $f0
lwc1 $f4, ZERO
lwc1 $f6, UM
sub.s $f2, $f2, $f6
while:	c.eq.s $f2, $f4
	bc1t Exit
	mul.s $f0, $f0, $f2
	sub.s $f2, $f2, $f6
	j while
Exit:
li $v0, 4
la $a0, RES
syscall
li $v0, 2
mov.s $f12, $f0
syscall
li $v0, 10
syscall