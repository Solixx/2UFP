.data 
MSG1: .asciiz "O valor final é "

.text
.globl main
main:
# t1 - i
# t2 - s
# t3 - i*i
# t4 - j*j
add $t1, $0, $0
add $t2, $0, $0
while:	slti $t0, $t1, 10
	beq $t0, 0 exit
	jal sumsquare
	add $t2, $t2, $v0
	addi $t1, $t1, 1
	j while
exit:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
add $a0, $t2, $0
syscall
li $v0, 10
syscall

sumsquare:
add $a0, $t1, $0
add $a1, $a0, 1
mul $t3, $a0, $a0
mul $t4, $a1, $a1
add $v0, $t3, $t4
jr $ra