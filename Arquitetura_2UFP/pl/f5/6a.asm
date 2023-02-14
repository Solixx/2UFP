.data
MSG1:	.asciiz "Insira um numero: "
MSG2:	.asciiz "Elevado: "
MSG3:	.asciiz "Resultado: "
ZERO:	.float 0.0

.text
.globl main
main:
# $f0 -> numero
# $f2 -> multiplicacao
li $v0, 4
la $a0, MSG1
syscall
li $v0, 6
syscall
li $v0, 4
la $a0, MSG2
syscall
li $v0, 5
syscall
move $t0, $v0
mov.s $f2, $f0
while:	beq $t0, 1, Exit
	mul.s $f0, $f0, $f2
	addi $t0, $t0, -1
	j while
Exit:
li $v0, 4
la $a0, MSG3
syscall
li $v0, 2
mov.s $f12, $f0
syscall
li $v0, 10
syscall