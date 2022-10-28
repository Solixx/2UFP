.data
MSG1: .asciiz "O valor final é "

.text
.globl main
main:

# $s0 - i
# $s1 - s
# s2 - $t1 + $v0

add $s0, $0, $0
add $s1, $0, $0

loop: slti $t0, $s0, 5
beq $t0, 0 exit
	jal funct
	add $s1, $s1, $v0
	addi $s0, $s0, 1
j loop
	
exit:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
move $a0, $s1
syscall
li $v0, 10
syscall

funct:
# $t2 - i ou j
# $t3 - i*square(i)
# $t4 - j*square(j)
addi $t0, $0, 5
add $sp, $sp, -8
sw $ra, 0($sp)
sw $s0, 4($sp) 
lw $a0, 4($sp)
sub $a1, $t0, $a0

add $t2, $0, $a0
jal square
lw $a0, 4($sp)
mul $t3, $a0, $v0

add $t2, $0, $a1
jal square
mul $t4, $a1, $v0
sub $v0, $t4, $t3
lw $ra, 0($sp)
add $sp, $sp, 8
jr $ra

square:
add $a0, $0, $t2
mul $v0, $a0, $a0
jr $ra
