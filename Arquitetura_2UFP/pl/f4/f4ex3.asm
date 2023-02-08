.data
.text

.globl main
main:
add $t0, $0, $0
addi $t1, $0, 1
for: 	beq $t1, 1000, exit
	add $t0, $t0, $t1
	mul $t1, $t1, 2
	j for
exit:
li $v0, 10
syscall