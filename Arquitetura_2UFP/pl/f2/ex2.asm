.data
MSG1: .asciiz "Indique o primeiro número => "
MSG2: .asciiz "Indique o segundo número => "
SUM: .asciiz "Soma = "
SUB: .asciiz "Diferença = "

 .align 2 		# Garante que os valores vão ser guardados em um endereço multiplo de 2 bytes
INPUT1: .space 4 	# Numero de bytes reservados na memória na label INPUT1
INPUT2: .space 4 	# Numero de bytes reservados na memória na label INPUT2

 .text
 .globl main
main: li $v0,4 		# linha 13 - print string / linha 14 - e guarda o valor da label MSG1 no endereço de memória $a0
 la $a0, MSG1
 syscall
 li $v0,5 		# lê um int
 syscall 
 la $t5, INPUT1
 sw $v0, 0($t5) 	# Guarda $v0 na exata posição da memória de $t5
 li $v0,4 		# linah 20 - print string / linha 21 - e guarda o valor da label MSG2 no endereço de memória $a0
 la $a0, MSG2
 syscall
 li $v0,5 		# lê um int
 syscall
 la $t6, INPUT2
 sw $v0, 0($t6) 	# guarda $v0 na posição exata da memória de $t6
 lw $t0, 0($t5) 	# guarda o valor guardado na exata posição de memória de $t5 em $t0
 lw $t1, 0($t6)
 li $v0,4 		# linha 29 - print string / linha 30 - e guarda o valor da label SUM no endereço de memória $a0
 la $a0, SUM
 syscall
 add $t3, $t0, $t1 	# guarda em $t3 a soma de $t0 + $t1
 li $v0,1 		# print int
 move $a0, $t3 		# copia o valor de $t3 para o endereço de memória $a0
 syscall
 li $v0,4 		# linha 36 - print string / linha 37 - e guarda o valor da label SUB no endereço de memória $a0
 la $a0, SUB
 syscall
 sub $t4, $t0, $t1 	# guarda em $t4 a subtração de $t0 - $t1
 li $v0,1 		# print int
 move $a0, $t4 		# copia o valor de $t4 para o endereço de memória $a0
 syscall
 li $v0,10 		# Exit
 syscall
