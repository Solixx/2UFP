.data
MSG1: 	.asciiz "Insira o numero de numeros: "
MSG2:	.asciiz "Insira um numero: "
MEDIA: 	.asciiz "Media: "
MAX:	.asciiz "Max: "
MIN: 	.asciiz "Min: "
ZERO: 	.float 0.0

.text
.globl main
main:
li $t0, 1
li $v0, 4
la $a0, MSG1
syscall
li $v0, 5
syscall
add $s0, $v0, $0
lwc1 $f4, ZERO
lwc1 $f5, ZERO
lwc1 $f3, ZERO
lwc1 $f2, ZERO
li $v0, 4
la $a0, MSG2
syscall
li $v0, 6
syscall
add.s $f4, $f4, $f0
add.s $f5, $f5, $f0
add.s $f2, $f2, $f0
addi $s0, $s0, -1
for:  	beq $s0, 0, ExitFor
	li $v0, 4
	la $a0, MSG2
	syscall
	li $v0, 6
	syscall
	c.lt.s $f4, $f0
	bc1t naoMin
	lwc1  $f4, ZERO
	add.s $f4, $f4, $f0
	naoMin:
	c.lt.s $f0, $f5
	bc1t naoMax
	lwc1  $f5, ZERO
	add.s $f5, $f5, $f0
	naoMax:
	add.s $f2, $f2, $f0
	addi $t0, $t0, 1
	addi $s0, $s0, -1
	j for
ExitFor:
mtc1 $t0, $f1
cvt.s.w $f1, $f1
div.s $f2, $f2, $f1
exit:
li $v0, 4
la $a0, MIN
syscall
li $v0, 2
mov.s $f12, $f4
syscall
li $v0, 4
la $a0, MAX
syscall
li $v0, 2
mov.s $f12, $f5
syscall
li $v0, 4
la $a0, MEDIA
syscall
li $v0, 2
mov.s $f12, $f2
syscall
li $v0, 10
syscall
