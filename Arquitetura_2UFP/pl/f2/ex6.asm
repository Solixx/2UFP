.data
MSG1: .asciiz "Resultado -> \n"

.align 2
N: .space 4

.text
.globl main
main: 

# $t0 -> Comparacoes
# $t1 -> Soma
# $t2 -> N
# $t3 -> i

add $t3, $0, $0

li $v0, 5
syscall
add $t2, $0, $v0

loop:
slt $t0, $t3, $t2
beq $t0, 0 Exit
li $v0, 5
syscall
slti $t0, $v0, 0
beq $t0, 1 incrementar
add $t1, $t1, $v0
incrementar:
addi $t3, $t3, 1
j loop

Exit:
li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
move $a0, $t1
syscall

li $v0, 10
syscall