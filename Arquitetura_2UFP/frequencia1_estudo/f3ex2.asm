.data 
MSG1: .asciiz "O valor final é "

.text
.globl main
main:
# t1 - i
# t2 - s
# t3 - 5
add $t1, $0, $0
add $t2, $0, $0
addi $t3, $0, 5
while:	slti $t0, $t1, 5
	beq $t0, 0 exit
	jal funct
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

funct:
# a0 - i
# a1 - j
# t4 - i*square(i)
# t5 - j*square(j)
add $sp, $sp, -8 # ra, i
sub $a0, $t3, $t1 # i (5-i)
add $a1, $t1, $0 # j (i)
sw $ra, 0($sp)
sw $a0, 4($sp)
jal square
mul $t4, $a0, $v0
sw $a1, 4($sp)
jal square
mul $t5, $a1, $v0
sub $v0, $t4, $t5 #((i*square(i))-(j*square(j)))
lw $ra, 0($sp)
add $sp, $sp, 8
jr $ra

square:
lw $a0, 4($sp)
mul $v0, $a0, $a0 # (i*i)
jr $ra