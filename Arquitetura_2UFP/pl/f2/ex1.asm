## O seu primeiro programa em assembly do MIPS
## Note o estilo: 3 colunas:
## (1) �Labels�, opcional
## (2) Instru��es e seus operandos
## (3) coment�rios, opcional

.data 				# Zona est�tica de dados 
str: .asciiz "Ol� Mundo!\n" 	# Uma �label�, str, e uma string
				# terminda pelo car�cter �\0�
				# usando a directiva .asciiz
.text 				# Zona de c�digo
.globl main 			# declara `main' como um s�mbolo
				# global
main:
li $v0, 4 			# C�digo para a chamada ao sistema 
				# print_str
la $a0, str 			# Endere�o da string a imprimir
syscall 			# Executa a chamada
Exit: 
li $v0, 10 			# C�digo para a chamada ao sistema
				# "Exit"
syscall 			# Executa a chamada