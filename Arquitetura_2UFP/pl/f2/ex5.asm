.data 
MSG1: .asciiz "Soma Impar -> "
MSG2: .asciiz "\nSoma Par -> "
MSG3: .asciiz "\nResultado -> "

.align 2
Vetor: .space 80
#N: .space 4

.text
.globl main
main: 
# $t1 -> Indice do vetor
# $t2 -> Valor do vetor
# $t3 -> Vetor
# $t4 -> Length
# $t5 -> Soma Impar
# $t6 -> Soma Par

# $s1 -> Length do array

add $t1, $0, $0
add $t2, $0, $0
add $t5, $0, $0
add $t6, $0, $0

li $v0, 5
syscall
add $t4, $0, $v0

slti $t0, $t4, 20
beq $t0, 0 Exit
add $s1, $t4, $0

li $v0, 5
syscall

la $t2, Vetor
sw $v0, 0($t2)
add $s0, $t2, $0
subi $t4, $t4, 1

loop_guardar:
beq $t4, 0 loop_guardar_exit

addi $t2, $t2, 4
li $v0, 5
syscall
sw $v0, 0($t2)

subi $t4, $t4, 1
j loop_guardar

loop_guardar_exit:
la $t2, Vetor
add $t4, $s1, $0

loop_impar:
beq $t4, 0 loop_impar_exit
lw $v0, 4($t2)
add $t5, $t5, $v0
addi $t2, $t2, 8

subi $t4, $t4, 2
j loop_impar

loop_impar_exit:
la $t2, Vetor
add $t4, $s1, $0

loop_par:
beq $t4, 0 loop_par_exit
lw $v0, 0($t2)
add $t6, $t6, $v0
addi $t2, $t2, 8

subi $t4, $t4, 2
j loop_par

loop_par_exit:

sub $t7, $t5, $t6

li $v0, 4
la $a0, MSG1
syscall
li $v0, 1
move $a0, $t5
syscall

li $v0, 4
la $a0, MSG2
syscall
li $v0, 1
move $a0, $t6
syscall

li $v0, 4
la $a0, MSG3
syscall
li $v0, 1
move $a0, $t7
syscall

Exit:
li $v0, 10
syscall
