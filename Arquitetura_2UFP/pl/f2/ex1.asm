## O seu primeiro programa em assembly do MIPS
## Note o estilo: 3 colunas:
## (1) “Labels”, opcional
## (2) Instruções e seus operandos
## (3) comentários, opcional

.data 				# Zona estática de dados 
str: .asciiz "Olá Mundo!\n" 	# Uma “label”, str, e uma string
				# terminda pelo carácter ‘\0’
				# usando a directiva .asciiz
.text 				# Zona de código
.globl main 			# declara `main' como um símbolo
				# global
main:
li $v0, 4 			# Código para a chamada ao sistema 
				# print_str
la $a0, str 			# Endereço da string a imprimir
syscall 			# Executa a chamada
Exit: 
li $v0, 10 			# Código para a chamada ao sistema
				# "Exit"
syscall 			# Executa a chamada