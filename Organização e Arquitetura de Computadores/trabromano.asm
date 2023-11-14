.data
	mens1: .asciiz "BEM VINDO!\nEscolha a base para ler o numero:\nB - Binario\nD - Decimal\nH - Hexadecimal\nR - Base Romana\n"
	mens2: .asciiz "\nDigite o numero a ser convertido\n"
	mens3: .asciiz "\nEscolha a base para qual quer converter: \nB - Binario\nD - Decimal\nH - Hexadecimal\nR - Base Romana\n"
	error1: .asciiz "\nO numero nao possui nenhum digito\n"
	dec: .space 12
	bin: .space 34
	hex: .space 40 	#teste: tem que ter 40 bytes para armazenar 10 elementos inteiros.
	rom: .space 10
	error2: .asciiz "\nDigito invalido\n"
	error3: .asciiz "\nO numero ja esta nessa base\n"
	espaco: .asciiz "\n"
	letras_rom: .word 73,86,88,76,67,68,77
	dec2rom_divisores: .word 1,4,5,9,10,40,50,90,100,400,500,900,1000
	I: .asciiz "I"
	IV: .asciiz "IV"
	V: .asciiz "V"
	IX: .asciiz "IX"
	X: .asciiz "X"
	XL: .asciiz "XL"
	L: .asciiz "L"
	XC: .asciiz "XC"
	C: .asciiz "C"
	CD: .asciiz "CD"
	D: .asciiz "D"
	CM: .asciiz "CM"
	M: .asciiz "M"
	dec2rom_algs: .word I, IV, V, IX, X, XL, L, XC, C, CD, D, CM, M
.text
main:
	ler_base1:
		#PRINTAR PRIMEIRA MENSAGEM
		li $v0, 4		#4 -> printar string
		la $a0, mens1		#endere�o da string para printar
		syscall			#printando
	
		#LER E SALVAR A PRIMEIRA OP��O EM S1
		li $v0, 12		#12 -> ler char. Vai para $v0
		syscall			#ler a op��o que o usu�rio escolheu
		move $s1, $v0
	
		#DESVIO
		beq $v0, 68, ler_decimal	#vai para ler_decimal se s0 == 'D'
		beq $v0, 66, ler_binario	#vai para ler_binario se s0 == 'B'...
		beq $v0, 72, ler_hexadecimal
		beq $v0, 82, ler_romano
	
		beq $v0, 100, inv_digito	#caso seja inserida uma letra minuscula
		beq $v0, 98, inv_digito		
		beq $v0, 104, inv_digito
		beq $v0, 114, inv_digito	
			
	ler_base2:
		#PRINTAR MENSAGEM 3
		li $v0, 4		#4 -> printar string
		la $a0, mens3		#endere�o da string para printar
		syscall
	
		
		#LER SEGUNDA OP��O:
		li $v0, 12		#12 ->ler char. Vai para $v0
		syscall
		move $s2, $v0
		
		#DESVIO
		beq $s1, 68, dec2
		beq $s1, 66, bin2
		beq $s1, 72, hex2
		beq $s1, 82, rom2
		dec2:
			j string_to_int	#s1 tem o resultado da transforma��o para inteiro
			transformei:
			beq $s2, 66, dec2bin
			beq $s2, 72, dec2hex
			beq $s2, 82, dec2rom
						
			beq $s2, 100, inv_digito	#caso seja inserida uma letra minuscula
			beq $s2, 98, inv_digito		
			beq $s2, 104, inv_digito
			beq $s2, 114, inv_digito	
			
		bin2:
			beq $s2, 68, bin2dec
			beq $s2, 72, bin2hex
			beq $s2, 82, bin2rom
						
			beq $s2, 100, inv_digito	#caso seja inserida uma letra minuscula
			beq $s2, 98, inv_digito		
			beq $s2, 104, inv_digito
			beq $s2, 114, inv_digito	
			
		hex2:
			beq $s2, 66, hex2bin
			beq $s2, 68, hex2dec
			beq $s2, 82, hex2rom
						
			beq $s2, 100, inv_digito	#caso seja inserida uma letra minuscula
			beq $s2, 98, inv_digito		
			beq $s2, 104, inv_digito
			beq $s2, 114, inv_digito	
			
		rom2:
			beq $s2, 66, rom2bin
			beq $s2, 72, rom2hex
			beq $s2, 68, rom2dec
						
			beq $s2, 100, inv_digito	#caso seja inserida uma letra minuscula
			beq $s2, 98, inv_digito		
			beq $s2, 104, inv_digito
			beq $s2, 114, inv_digito	
			
base_repetida:
	#printa a mensagem de erro
	li $v0, 4
	la $a0, error3
	syscall
	#ENCERRAR PROGRAMA
	li $v0, 10
	syscall				
printar_resultado:
	#printa um \n para o resultado aparecer mais organizado
	li $v0, 4		
	la $a0, espaco		
	syscall	
	#printa o resultado
	li $v0, 1
	move $a0, $s1
	syscall
	#ENCERRAR PROGRAMA
	li $v0, 10
	syscall	
		
inv_digito:			#caso o digito inserido seja invalido, mostrar mensagem de erro
	li $v0, 4		#4 -> printar string
	la $a0, error2		
	syscall			#printando		

	#ENCERRAR PROGRAMA
	li $v0, 10
	syscall
				
ler_decimal:
	
	#PRINTAR SEGUNDA MENSAGEM
	li $v0, 4		#4 -> printar string
	la $a0, mens2		
	syscall			#printando
	
	#SALVAR O DECIMAL NA MEM�RIA
	li $v0, 8		#8 -> ler vetor de caracteres
	la $a0, dec		#endere�o da mem�ria que vou salvar
	li $a1, 12		#numero m�ximo de caracteres a ler
	syscall
	
	j ler_base2

ler_binario:

	#PRINTAR SEGUNDA MENSAGEM
	li $v0, 4		#4 -> printar string
	la $a0, mens2		
	syscall			#printando
	
	
	#SALVAR O BINARIO NA MEM�RIA
	li $v0, 8		#8 -> ler vetor de caracteres
	la $a0, bin		#endere�o da mem�ria onde vou salvar
	li $a1, 34		#n�mero m�ximo de caracteres a ler
	syscall

	j ler_base2
	
	
ler_hexadecimal:

	#PRINTAR SEGUNDA MENSAGEM
	li $v0, 4		#4 -> printar string
	la $a0, mens2		
	syscall			#printando
	
	#SALVAR O HEXADECIMAL NA MEM�RIA
	li $v0, 8		#8 -> ler vetor de caracteres
	la $a0, hex		#endere�o da mem�ria onde vou salvar
	li $a1, 10		#n�mero m�ximo de caracteres a ler
	syscall
	
	j ler_base2

ler_romano:

	#PRINTAR SEGUNDA MENSAGEM
	li $v0, 4		#4 -> printar string
	la $a0, mens2		
	syscall			#printando
	
	#SALVAR O ROMANO NA MEM�RIA
	li $v0, 8		#8 -> ler vetor de caracteres
	la $a0, rom		#endere�o da mem�ria onde vou salvar
	li $a1, 10		#n�mero m�ximo de caracteres a ler
	syscall
	
	j ler_base2
	
################ DEC TO BIN ###############
	
string_to_int:		
	li $s1, 0	#n�mero decimal (inteiro)
	li $t2, 0	#multiplicador
	li $t5, 11
	
	loop_vetor_dec:
	bltz $t5, sair_loop_dec
	#leitura do vetor inserido pelo usuario
	lb $t0, dec($t5)	#$t0 = digito temporario que armazena o conteudo de dec[i]
	jal int2bin_primeiro
	subi $t5, $t5, 1	#i--
	j loop_vetor_dec
	sair_loop_dec:	
	j transformei
		
	int2bin_primeiro:
		# s1 = resultado
		#t0 = cada numero TEMP
		#t1 = cada numero multiplicado TEMP
		#t2 = multiplicador TEMP
		
		sub $t0, $t0, 48
		bltz $t0, inv1

		beqz $t2, d2b_primeiro
		mul $t1, $t0, $t2
		add $s1, $s1, $t1
		mul $t2, $t2, 10
		
		inv1:
			jr $ra
		
		d2b_primeiro:
			add $s1, $s1, $t0
			li $t2, 10
			jr $ra

d2b_divisao:

	#s1, numero a dividir
	#t0, 1 ou 0, resto da divisao
	#t1, multiplicador
	#t2, numero multiplicado
	
	beq $s1, 0, d2b_acabou
	
	divu $s1, $s1, 2	
	mfhi $t0		#t0 recebe o resto da divis�o 1 ou zero
				#multiplicar por 10^seu peso (contador em $s5)
	mul $t2, $t0, $t1
	add $s2, $s2, $t2
	mul $t1, $t1, 10
	
	j d2b_divisao
		
	d2b_acabou:
		jr $ra 

dec2bin:	
	# --- $s1 CARREGA O N�MERO EM INT --- #
	
	li $t5, 11
	li $t1, 1
	li $s2, 0
	jal d2b_divisao

	#printa um \n para o resultado aparecer mais organizado
	li $v0, 4		
	la $a0, espaco		
	syscall	
	#PRINTAR RESULTADO
	li $v0, 1
	move $a0, $s2
	syscall
	#ENCERRA A FUNCAO
	li $v0, 10
	syscall
	
################ DEC 2 HEX ###############
	
d2h_divisao:
	#vou salvar o resultado no vetor de char HEX
	#t0, resultado de cada divis�o
	#t1, index da mem�ria
	#s1, elemento em inteiro
	
	beq $s1, 0, d2h_acabou
	
	divu $s1, $s1, 16	
	mfhi $t0		#t0 recebe o resto da divis�o		

	blt $t0, 10, d2h_numero		#salvar de traz para frente no vetor hex
	
	addi $t0, $t0, 7
	
	d2h_numero:
		addi $t0, $t0, 48
	
	sw $t0, hex($t1)
	subi $t1, $t1, 4
	
	j d2h_divisao
	
	d2h_acabou:
		addi $t1, $t1, 4
		jr $ra 

dec2hex:
	
	li $t1, 36	# index para vetor (MAX 10)
		#TESTANDO, APENAS 3 ELEMENTOS NO VETOR! 
	
	jal d2h_divisao

	#printa um \n para o resultado aparecer mais organizado
	li $v0, 4		
	la $a0, espaco		
	syscall	

	#em t1 est� o index do ultimo vetor, usar ele pra printar somando 4 at� 36!
	# o resultado est� na mem�ria! 
	# TESTE: PRINTANDO UM POR UM: 
	
	li $v0, 11
	
	d2h_printando:
	
		bgt $t1, 36, d2h_encerrar
		lw $a0, hex($t1)
		addi $t1, $t1, 4
		syscall
		j d2h_printando

	d2h_encerrar:
		#ENCERRA PROGRAMA
		li $v0, 10
		syscall
	
################ DEC 2 ROM ###############									
	retornar_divisoes:
	j loop_divisoes_dec2rom
	
	printar_primeiro_alg_repetido:
	move $t4, $t1
	loop_print_pr:
	beqz $t4, transformei_dec2rom
	li $v0, 4		
	lw $a0, 0($s3)
	syscall
	subi $t4, $t4, 1	#printar o algarismo equivalente ao divisor
	j loop_print_pr	
	
	printar_primeiro_alg:
	bgt $t1, 1, printar_primeiro_alg_repetido	#ex: 3/1 = 3; 3 em romanos = III
	li $v0, 4		
	lw $a0, 0($s3)	#printar o algarismo equivalente ao divisor
	syscall		
	j transformei_dec2rom
	
	algarismos_repetidos:
	move $t4, $t1	#resultado da divisao � carregado em $t4, que servir� como indice para printar a quantidade correta
	loop_print_r:
	beqz $t4, retornar_divisoes	#sair do loop e voltar a transformar o n�mero
	li $v0, 4		
	lw $a0, 0($s3)			#printar o algarismo equivalente ao divisor
	syscall		
	subi $t4, $t4, 1
	j loop_print_r
	
	printar_algarismos:
	bgt $t1, 1, algarismos_repetidos	#ex: 3/1 = 3; 3 em romanos = III
	li $v0, 4		
	lw $a0, 0($s3)		#printar o algarismo equivalente ao divisor
	syscall		 
	j loop_divisoes_dec2rom
		
	divisoes_dec2rom:
	beqz $t0, printar_primeiro_alg		#caso o numero seja composto por uma s� letra(X, III, CC etc.)/combina��o(IV, IX etc.)
	bnez $t0, printar_algarismos		#printar o primeiro numero dividido
	loop_divisoes_dec2rom:
	bltz $t2, transformei_dec2rom	#fim loop caso o indice seja menor que zero 
	sll $t3, $t2, 2		#4 * i
	sll $s3, $t2, 2		#4 * i
	addu $t3, $t3, $t6 	#endere�o correspondente ao indice (divisores)
	addu $s3, $s3, $t7	#endere�o correspondente ao indice (algarismos)
	lw $t5, 0($t3)		#carregar conteudo do endere�o em $t5
	div $t0, $t5		#dividir o resto pelo divisor atual
	mflo $t1	
	mfhi $t0	
	subi $t2, $t2, 1	#reduzir indice
	bnez $t1, printar_algarismos	#printar numero dividido com sucesso
	j loop_divisoes_dec2rom

 	divisoes_rom:
	#checar primeiro divisor
	loop_encontrar_divisor:
	#carregar valor
	sll $t3, $t2, 2		#4 * i
	sll $s3, $t2, 2		#4 * i
	addu $t3, $t3, $t6 	#endere�o correspondente ao indice (divisores)
	addu $s3, $s3, $t7	#endere�o correspondente ao indice (algarismos)
	lw $t5, 0($t3)		#carregar conteudo do endere�o em $t5
	div $s1, $t5		#dividir o numero inserido pelo usuario pelo divisor atual
	mflo $t1	
	mfhi $t0		
	subi $t2, $t2, 1	#reduzir indice
	bne $t0, $s1, divisoes_dec2rom 	#se o resto nao igual ao numero inserido, ele p�de ser dividido e entrou na proxima fun��o
	j loop_encontrar_divisor	

dec2rom:
	bgt $s1, 3999, inv_digito # mostra mensagem de erro caso o decimal inserido esteja fora dos limites de representa��o do sistema romano
	blez $s1, inv_digito
	
	li $t2, 12	#ultima posicao do indice	
	la $t6, dec2rom_divisores	#carrega o endere�o do vetor dos divisores em $t6
	la $t7, dec2rom_algs		#carrega o endere�o do vetor dos algarismos em $t7
	#printa um \n para o resultado aparecer mais organizado
	li $v0, 4		
	la $a0, espaco		
	syscall	
	j divisoes_rom	
	transformei_dec2rom:
	#ENCERRAR PROGRAMA
	li $v0, 10
	syscall	
################ BIN 2 DEC ###############
b2d_calculo:
	#$t0 = digito temp
	#$t1 = digito multiplicado temp
	#$s1 = resultado
	#$t2 = index
	
	li $s1, 0
	li $t2, 0
	li $t5, 11
	loop_vetor_bin:
	bltz $t5, sair_loop_bin
	#leitura do vetor inserido pelo usuario
	lb $t0, bin($t5)	#$t0 = digito temporario que armazena o conteudo de bin[i]
	jal encontrar_primeiro
	subi $t5, $t5, 1	#i--
	j loop_vetor_bin
	sair_loop_bin:
	j fim_b2d_calculo
	
	#ENCONTRAR O PRIMEIRO
	encontrar_primeiro:

		#t2 = zero at� encontrar um numero
		
		sub $t0, $t0, 48	#digito temporario subtraido
		bltz $t0, inv	#pula se for invalido

		beqz $t2, primeiro
		
		mul $t1, $t0, $t2
		add $s1, $s1, $t1
		mul $t2, $t2, 2
		jr $ra
		
		primeiro:
			add $s1, $s1, $t0
			li $t2, 2
			jr $ra
			
		inv:
			jr $ra		#vai para o proximo sem realizar opera��es
	
bin2dec:
	# o numero possui limite de 34 bits.	
	# $s7 = contador de digitos
	# $s1 = resultado
	# $t0 = cada numero
	# $t1 = multiplicador
	# $t2 = index  		come�a com 32
	# $t5 =  aux loop
	# POR ENQUANTO, POR MAIS QUE O LIMITE SEJA 34 DIGITOS BIN�RIOS, O C�DIGO S� SUPORTA 
	# 8 DIGITOS
	li $t5, 11
	
	j b2d_calculo
	fim_b2d_calculo:
	j printar_resultado

################ BIN 2 HEX ###############
bin2hex:
################ BIN 2 ROM ###############
bin2rom:

################ HEX 2 DEC ###############
string_to_int_H:
	#s1 - resultado
	#t0 - cada numero (temp)
	
	loop_vetor_hex:
	bltz $t5, sair_loop_hex
	#leitura do vetor inserido pelo usuario
	lb $t0, hex($t5)	#$t0 = digito temporario que armazena o conteudo de hex[i]
	jal encontrar_primeiro_h
	subi $t5, $t5, 1	#i--
	j loop_vetor_hex
	sair_loop_hex:
	j transformei_h
	
	encontrar_primeiro_h:
	#t2 = zero at� encontrar um numero
			
		sub $t0, $t0, 48	#digito temporario subtraido
		ble $t0, 9, numero 

		#se for letra:
		sub $t0, $t0, 7	
		#fim se for letra 
		
		numero:
		bltz $t0, inv_h	#pula se for invalido
		
		beqz $t2, primeiro_h
		
		mul $t1, $t0, $t2
		add $s1, $s1, $t1
		mul $t2, $t2, 16
		jr $ra
		
		primeiro_h:
			add $s1, $s1, $t0
			li $t2, 16
			jr $ra
			
		inv_h:
			jr $ra		#vai para o proximo sem realizar opera��es

hex2dec:
	# o numero possui limite de 10 bits.
	# $s7 = contador de digitos
	# $s1 = resultado
	# $t0 = cada numero
	# $t1 = multiplicador
	# $t2 = index
	# $t5 =  aux loop

	li $t2, 0
	li $s1, 0
	li $t5, 9

	j string_to_int_H
transformei_h:
	j printar_resultado
	
################ HEX 2 BIN ###############
hex2bin:
################ HEX 2 ROM ###############
hex2rom:
################ ROM 2 DEC ###############
contar_validez:
addi $s4, $s4, 1
beq $s4, 1, sair_loop_validez

transformar_rom:
	loop_ler_vetor_rom:
	bge $t5, $t6, sair_loop_rom
	#leitura do vetor inserido pelo usuario
	lb $t0, rom($t5)	#$t0 = digito temporario que armazena o conteudo de rom[i]
	jal encontrar_rom
	addi $t5, $t5, 1	#i++
	j loop_ler_vetor_rom
	sair_loop_rom:
	j transformei_rom	
	
	encontrar_rom:	#comparar o valor do digito inserido pelo usuario com os valores dos algarismos romanos 
	li $s4, 0
	move $t7, $t0		#&t7 = auxiliar para checar se a letra � mai�scula ou min�scula
	subi $t7, $t7, 32	#na tabela ascii, as letras minusculas tem 32 de diferen�a das letras mai�sculas
	
	lb $t3, rom($t4)	#carregar o conteudo do indice anterior
	addi $t4, $t4, 1	#atualizar o ponteiro de anterior
	lb $t1, rom($t2)	#carregar o conteudo do proximo indice
	addi $t2, $t2, 1	#atualizar o ponteiro de proximo
	
	checar_minusculo:
	bltz $t8, checar_validez
	sll $t9, $t8, 2		#4 * i
	addu $t9, $t9, $s2
	lw $s3, 0($t9)
	beq $t7, $s3, inv_digito	#caso a letra seja min�scula
	subi $t8, $t8, 1
	j checar_minusculo

	checar_validez:
	li $t8, 6
	li $s4, 0
	loop_validez:
	bltz $t8, inv_digito
	sll $t9, $t8, 2		#4 * i
	addu $t9, $t9, $s2
	lw $s3, 0($t9)
	subi $t8, $t8, 1
	beq $t0, $s3, contar_validez
	beq $t0, 10, transformei_rom
	j loop_validez
	
	sair_loop_validez:
	beq $t0, 73, add_1	#letra I
	beq $t0, 86, add_5	#letra V
	beq $t0, 88, add_10	#letra X
	beq $t0, 76, add_50	#letra L
	beq $t0, 67, add_100	#letra C
	beq $t0, 68, add_500	#letra D
	beq $t0, 77, add_1000	#letra M
			
	jr $ra	#ir para o proximo digito

	#adicoes no registrador de resultado/transformacao em si
	add_1:
	beq $t1, 86, ler_proximo 	#caso o conteudo do proximo indice seja V, pular para a leitura desse indice
	beq $t1, 88, ler_proximo	#caso o conteudo do proximo indice seja X, pular para a leitura desse indice
	addi $s1, $s1, 1		#adiciona 1 ao resultado
	jr $ra
			
	add_5:
	addi $s1, $s1, 5	#adiciona 5 ao resultado
	beq $t3, 73, sub_1	#caso o conteudo do indice anterior seja I, subtrai 1 do resultado
	jr $ra

	add_10:
	beq $t1, 76, ler_proximo	#caso o conteudo do proximo indice seja L, pular para a leitura desse indice
	beq $t1, 67, ler_proximo	#caso o conteudo do proximo indice seja C, pular para a leitura desse indice
	addi $s1, $s1, 10		#adiciona 1 ao resultado
	beq $t3, 73, sub_1		#caso o conteudo do indice anterior seja I, subtrai 1 do resultado
	jr $ra

	add_50:
	addi $s1, $s1, 50		#adiciona 50 ao resultado
	beq $t3, 88, sub_10		#caso o conteudo do indice anterior seja X, subtrai 10 do resultado
	jr $ra

	add_100:
	beq $t1, 68, ler_proximo	#caso o conteudo do proximo indice seja D, pular para a leitura desse indice
	beq $t1, 77, ler_proximo	#caso o conteudo do proximo indice seja M, pular para a leitura desse indice
	addi $s1, $s1, 100		#adiciona 100 ao resultado
	beq $t3, 88, sub_10		#caso o conteudo do indice anterior seja X, subtrai 10 do resultado
	jr $ra

	add_500:
	addi $s1, $s1, 500	#adiciona 500 ao resultado
	beq $t3, 67, sub_100	#caso o conteudo do indice anterior seja C, subtrai 100 do resultado
	jr $ra
	
	add_1000:				
	addi $s1, $s1, 1000	#adiciona 1000 ao resultado
	beq $t3, 67, sub_100	#caso o conteudo do indice anterior seja C, subtrai 100 do resultado
	jr $ra

	#funcoes auxiliares de subtra��o	
	sub_1:
	subi $s1, $s1, 1
	jr $ra
	
	sub_10:
	subi $s1, $s1, 10
	jr $ra
		
	sub_100:
	subi $s1, $s1, 100
	jr $ra

	ler_proximo:
	jr $ra	

rom2dec:					#inicia a transformacao
	#possui um limite de 10 bits
	#$s1 = resultado
	#$t1 = conteudo do indice seguinte
	#$t2 = armazena o numero do proximo indice
	#$t3 = conteudo do indice anterior
	#$t4 = armazena o numero do indice anterior
	#$t5 = iterador loop
	#t6 = tamanho vetor

	#definir valores iniciais para os operadores	
	li $s1, 0
	li $t2, 1
	lb $t1, rom($t2)
	li $t4, -1
	li $t5, 0
	li $t6, 10
	la $s2, letras_rom
	li $t8, 6 # ultimo indice do vetor letras_rom

	j transformar_rom

	transformei_rom:
	j printar_resultado

################ ROM 2 BIN ###############
rom2bin:
################ ROM 2 HEX ###############
rom2hex:
	#ENCERRAR PROGRAMA
	li $v0, 10
	syscall
