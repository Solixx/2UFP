.data
ENTER:	.asciiz "\n"
ZERO:	.float 0.0

.text
.globl main
main:
# $f1 -> fahr
# $f2 -> celsius
# $f3 -> lower
# $f4 -> upper
# $f5 -> step

lwc1 $f3, ZERO
addi $t0, $t0, 300
addi $t1, $t1, 20
mtc1 $t0, $f4
cvt.s.w $f4, $f4
mtc1 $t1, $f5
cvt.s.w $f5, $f5 
lwc1 $f1, ZERO
add.s $f1, $f1, $f3
while: 	c.lt.s $f1, $f4
	bc1f Exit
	addi $t0, $0, 5
	addi $t1, $0, 9
	mtc1 $t0, $f7
	cvt.s.w $f7, $f7
	mtc1 $t1, $f6
	cvt.s.w $f6, $f6
	div.s $f7, $f7, $f6
	addi $t0, $0, 32
	mtc1 $t0, $f6
	cvt.s.w $f6, $f6
	sub.s $f6, $f1, $f6
	mul.s $f2, $f7, $f6
	li $v0, 2
	mov.s $f12, $f1
	syscall
	li $v0, 4
	la $a0, ENTER
	syscall
	li $v0, 2
	mov.s $f12, $f2
	syscall
	li $v0, 4
	la $a0, ENTER
	syscall
	add.s $f1, $f1, $f5
	j while
Exit:
li $v0, 10
syscall