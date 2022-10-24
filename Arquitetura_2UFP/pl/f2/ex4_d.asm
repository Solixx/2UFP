.data
MSG1: .asciiz "O valor final e \n"

.text
.globl main
main:

# $t1 - i
# $t2 - j
# $t3 - sum
# $t5 - (i-j)

add $t3, $0, $0

add $t1, $0, $0
for1: slti $t0, $t1, 20
beq $t0, 0, exit_for1

add $t2, $0, $0
for2:slti $t0, $t2, 5
beq $t0, 0, exit_for2

sub $t5, $t1, $t2
add $t3, $t3, $t5

addi $t2, $t2, 1
j for2

exit_for2: addi $t1, $t1, 2
j for1

exit_for1:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
move $a0, $t3
syscall
li $v0, 10
syscall