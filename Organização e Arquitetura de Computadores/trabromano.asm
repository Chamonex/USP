data
	mens1: .asciiz "BEM VINDO!\nEscolha a base para ler o numero:\nB - Binario\nD - Decimal\nH - Hexadecimal\nR - Base Romana\n"
	mens2: .asciiz "\nDigite o numero a ser convertido\n"
	mens3: .asciiz "\nEscolha a base para qual quer converter: \nB - Binario\nD - Decimal\nH - Hexadecimal\nR - Base Romana\n"
	error1: .asciiz "\nO numero nao possui nenhum digito\n"
	dec: .space 12
	bin: .space 34
	hex: .space 40 	#teste: tem que ter 40 bytes para armazenar 10 elementos inteiros.
	rom: .space 13	
	error2: .asciiz "\nDigito ou numero invalido\n"
	error3: .asciiz "\nO numero inserido ja esta nessa base\n"
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
		li $v0, 4		
		la $a0, mens1		
		syscall			
			
		#LER E SALVAR A PRIMEIRA OPÇÃO EM S1
		li $v0, 12
		syscall
		move $s1, $v0
	
		#DESVIOS PARA LEITURA
		beq $v0, 68, ler_decimal	
		beq $v0, 66, ler_binario	
		beq $v0, 72, ler_hexadecimal
		beq $v0, 82, ler_romano
	
		#DESVIOS DE ERRO
		beq $v0, 100, inv_digito
		beq $v0, 98, inv_digito		
		beq $v0, 104, inv_digito
		beq $v0, 114, inv_digito	
		bne $s1, 100, inv_digito	
					
	ler_base2:
		#PRINTAR MENSAGEM 3
		li $v0, 4		
		la $a0, mens3		
		syscall
	
		
		#LER SEGUNDA OPÇÃO:
		li $v0, 12		
		syscall
		move $s2, $v0		#salvar a segunda base em $s2 (funcoes diretas)
		move $s6, $v0		#salvar a segunda base em $s6 (funcoes intermediarias)
		
		#DESVIOS CONVERSÃO
		beq $s1, 68, dec2
		beq $s1, 66, bin2
		beq $s1, 72, hex2
		beq $s1, 82, rom2
		
		dec2:
			j string_to_int		#como lemos o número em um vetor de string,
						#o número deve ser convertido em inteiro
			transformei:
			beq $s2, 66, dec2bin
			beq $s2, 72, dec2hex
			beq $s2, 82, dec2rom
			
			beq $s6, 82, dec2rom
			beq $s6, 66, dec2bin			
			beq $s6, 72, dec2hex									
			j checar_base2
						
		bin2:
			beq $s2, 68, bin2dec
			beq $s2, 72, bin2hex
			beq $s2, 82, bin2rom
						
			j checar_base2
						
		hex2:
			beq $s2, 66, hex2bin
			beq $s2, 68, hex2dec
			beq $s2, 82, hex2rom
						
			j checar_base2	
			
		rom2:
			beq $s2, 66, rom2bin
			beq $s2, 72, rom2hex
			beq $s2, 68, rom2dec
								
															
			j checar_base2

checar_base2:	
	beq $s2, 100, inv_digito	#caso seja inserida uma letra minuscula
	beq $s2, 98, inv_digito		
	beq $s2, 104, inv_digito
	beq $s2, 114, inv_digito	
	
	bne $s2, 100, inv_digito	#caso seja outra letra qualquer
																			
base_repetida:
	#printa a mensagem de erro
	li $v0, 4
	la $a0, error3
	syscall
	#ENCERRAR PROGRAMA
	li $v0, 10
	syscall				
printar_resultado:
	
	li $v0, 4				
	la $a0, espaco		
	syscall				#printar \n
	
	li $v0, 1
	move $a0, $s1	
	syscall				#printa o resultado

	li $v0, 10
	syscall				#encerrar programa
		
		
inv_digito:			
	li $v0, 4		
	la $a0, error2		
	syscall				#printa mensagem de erro caso o digito for inválido		

	li $v0, 10
	syscall				#encerrar programa

	

#-------------------- LEITURA DO NÚMERO A CONVERTER --------------------#			

ler_decimal:
	
	li $v0, 4		
	la $a0, mens2		
	syscall				#printar segunda mensagem
	
	
	li $v0, 8		
	la $a0, dec		
	li $a1, 12
	syscall				#salvar decimal na memória como vetor de char
	
	j ler_base2

ler_binario:

	li $v0, 4		
	la $a0, mens2		
	syscall				#printar segunda mensagem
	
	
	li $v0, 8		
	la $a0, bin		
	li $a1, 34		
	syscall				#salvar binario na memória como vetor de char

	j ler_base2
	
ler_hexadecimal:

	#t1 = testar cada elemento
	
	li $v0, 4		
	la $a0, mens2		
	syscall				#printar segunda mensagem
	
	li $v0, 8		
	la $a0, hex		
	li $a1, 10			#salvar hexadecimal na memória como vetor de char
	syscall	

	j ler_base2

ler_romano:
	
	li $v0, 4		
	la $a0, mens2		
	syscall				#printar segunda mensagem
	
	li $v0, 8		 
	la $a0, rom		
	li $a1, 13		#salvar romano como vetor de char
	syscall
	
	j ler_base2
	

#-------------------- CONVERTER DECIMAL PARA BINÁRIO --------------------#

string_to_int:		
	li $s1, 0	#número decimal (inteiro)
	li $t2, 0	#multiplicador
	li $t5, 11	#indice loop
	
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
		#t1 = cada numero multiplicado vezes TEMP
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
	mfhi $t0		#t0 recebe o resto da divisão 1 ou zero
				#multiplicar por 10^seu peso (contador em $s5)
	mul $t2, $t0, $t1
	add $s2, $s2, $t2
	mul $t1, $t1, 10
	
	j d2b_divisao
		
	d2b_acabou:
		jr $ra 

dec2bin:	
	# --- $s1 CARREGA O NÚMERO EM INT --- #
	
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
	#vou salvar o resultado no vetor de char
	#t0, resto de cada divisão
	#s3, memoria onde salvar
	#s1, elemento em decimal -> resultados das divisões por 16
	#s4, correção de letra
	
	
	divu $s1, $s1, 16	#divide por 16, resultado deve ser printado
	mfhi $t0		#t0 é o resto da divisao, que deve ser dividido de novo				
	

	
	# TRATAMENTO PARA LETRA
	move $s4, $t0
	blt $s4, 10, d2h_numero
	addi $s4, $s4, 7
	d2h_numero:,
		addi $s4, $s4, 48
	#FIM TRATAMENTO PARA LETRA
	
	#nesse ponto, s1 é o que devo salvar na memoria, e $t0 é o que devo dividir de novo
	sw $s4, 0($s3)		#salva o resto da divisão na memória
	
	subi $s3, $s3, 4	#t1 recebe o endereço para salvar próximo resultado
	addi $s2, $s2, 1	#incrementa contador de casas

	beqz $s1, d2h_acabou
	j d2h_divisao
		 
	d2h_acabou:
		jr $ra

dec2hex:
	# $s1 = NUMERO DECIMAL
	# $s3 = index para vetor (36, MAX 10)
	# $s2 = numero de casas do hexadecimal
	
	li $s2, 0		#contador
	la $s3, hex		#endereço pra salvar
		
	addi $s3, $s3, 37	#começa do ultimo elemento do vetor
	
	jal d2h_divisao

	#printa um \n para o resultado aparecer mais organizado
	li $v0, 4		
	la $a0, espaco		
	syscall	

	# em t1 está o index do ultimo elemento do vetor em HEXA
	# em s2 está o número de casas que o HEXADECIMAL tem
	# 	usa-lo como contador para printar
	# o resultado está na memória no sentido correto!

	li $v0, 11
	addi $s3, $s3, 4
	d2h_printando:
	
		blez $s2, d2h_encerrar
		subi $s2, $s2, 1
		lw $a0, 0($s3)
		addi $s3, $s3, 4
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
	move $t4, $t1	#resultado da divisao é carregado em $t4, que servirá como indice para printar a quantidade correta
	loop_print_r:
	beqz $t4, retornar_divisoes	#sair do loop e voltar a transformar o número
	li $v0, 4		
	lw $a0, 0($s3)			#printar o algarismo equivalente ao divisor
	syscall		
	subi $t4, $t4, 1
	j loop_print_r
	
	printar_algarismos:
	bgt $t1, 1, algarismos_repetidos	#ex: 33/10 = 3, resto 3; 30 em romanos = XXX (3 vezes X)
	li $v0, 4		
	lw $a0, 0($s3)		#printar o algarismo equivalente ao divisor
	syscall		 
	j loop_divisoes_dec2rom
		
	divisoes_dec2rom:
	beqz $t0, printar_primeiro_alg		#caso o numero seja composto por uma só letra(X, III, CC etc.)/combinação(IV, IX etc.)
	bnez $t0, printar_algarismos		#printar o primeiro numero dividido
	loop_divisoes_dec2rom:
	bltz $t2, transformei_dec2rom	#fim loop caso o indice seja menor que zero 
	sll $t3, $t2, 2		#4 * i
	sll $s3, $t2, 2		#4 * i
	addu $t3, $t3, $t6 	#endereço correspondente ao indice (divisores)
	addu $s3, $s3, $t7	#endereço correspondente ao indice (algarismos)
	lw $t5, 0($t3)		#carregar conteudo do endereço em $t5
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
	addu $t3, $t3, $t6 	#endereço correspondente ao indice (divisores)
	addu $s3, $s3, $t7	#endereço correspondente ao indice (algarismos)
	lw $t5, 0($t3)		#carregar conteudo do endereço em $t5
	div $s1, $t5		#dividir o numero inserido pelo usuario pelo divisor atual
	mflo $t1	
	mfhi $t0		
	subi $t2, $t2, 1	#reduzir indice
	bne $t0, $s1, divisoes_dec2rom 	#se o resto nao for igual ao numero inserido, ele pôde ser dividido e entrou na proxima função
	j loop_encontrar_divisor	

dec2rom:
	bgt $s1, 3999, inv_digito # mostra mensagem de erro caso o decimal inserido esteja fora dos limites de representação do sistema romano
	blez $s1, inv_digito
	
	li $t2, 12	#ultima posicao do indice	
	la $t6, dec2rom_divisores	#carrega o endereço do vetor dos divisores em $t6
	la $t7, dec2rom_algs		#carrega o endereço do vetor dos algarismos em $t7
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

		#t2 = zero até encontrar um numero
		
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
			jr $ra		#vai para o proximo sem realizar operações
	
bin2dec:
	# o numero possui limite de 34 bits.	
	# $s1 = resultado
	# $t0 = cada numero
	# $t1 = multiplicador
	# $t2 = index  		começa com 32
	# $t5 =  aux loop
	# POR ENQUANTO, POR MAIS QUE O LIMITE SEJA 34 DIGITOS BINÁRIOS, O CÓDIGO SÓ SUPORTA 
	# 8 DIGITOS
	li $t5, 11
	
	j b2d_calculo
	fim_b2d_calculo:
	bne $s6, 68, transformei	#caso a transformacao nao tenha como objetivo final um numero decimal, carrega o resultado da transformacao em decimal para a conversao desejada
	j printar_resultado

################ BIN 2 HEX ###############
bin2hex:
 j bin2dec #conversao intermediaria

################ BIN 2 ROM ###############
bin2rom:
 j bin2dec #conversao intermediaria
################ HEX 2 DEC ###############
string_to_int_H:
	#s1 - resultado
	#t0 - cada numero (temp)
	
	loop_vetor_hex:
	bltz $t5, sair_loop_hex
	#leitura do vetor inserido pelo usuario
	lb $t0, hex($t5)	#$t0 = digito temporario que armazena o conteudo de hex[i]
	
	jal encontrar_primeiro_h
	subi $t5, $t5, 1	
	j loop_vetor_hex
	sair_loop_hex:
	j transformei_h
	
	encontrar_primeiro_h:
	#t2 = zero até encontrar um numero
			
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
			jr $ra		#vai para o proximo sem realizar operações

hex2dec:
	# o numero possui limite de 10 bits.
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
	bne $s6, 68, transformei	#caso a transformacao nao tenha como objetivo final um numero decimal, carrega o resultado da transformacao em decimal para a conversao desejada
	j printar_resultado
	
################ HEX 2 BIN ###############
hex2bin:
j hex2dec #conversao intermediaria
################ HEX 2 ROM ###############
hex2rom:
j hex2dec #conversao intermediaria
################ ROM 2 DEC ###############
reset_contagem:
li $s5, 0
jr $ra

repeticoes_fim:
j inv_digito

repeticoes_max:
bne $t3, $t0, reset_contagem
beq $t1, $t0, ler_proximo
li $s5, 0
jr $ra

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
	
	lb $t3, rom($t4)	#carregar o conteudo do indice anterior
	addi $t4, $t4, 1	#atualizar o ponteiro de anterior
	lb $t1, rom($t2)	#carregar o conteudo do proximo indice
	addi $t2, $t2, 1	#atualizar o ponteiro de proximo

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
	ble $t0, 10, transformei_rom
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
	addi $s5, $s5, 1
	beq $s5, 2, repeticoes_max
	beq $s5, 3, repeticoes_max
	beq $s5, 4, repeticoes_fim
	jr $ra
			
	add_5:
	addi $s1, $s1, 5	#adiciona 5 ao resultado
	beq $t1, $t0, inv_digito
	beq $t3, 73, sub_1	#caso o conteudo do indice anterior seja I, subtrai 1 do resultado
	jr $ra

	add_10:
	beq $t1, 76, ler_proximo	#caso o conteudo do proximo indice seja L, pular para a leitura desse indice
	beq $t1, 67, ler_proximo	#caso o conteudo do proximo indice seja C, pular para a leitura desse indice
	addi $s1, $s1, 10		#adiciona 1 ao resultado
	addi $s5, $s5, 1
	beq $t3, 73, sub_1		#caso o conteudo do indice anterior seja I, subtrai 1 do resultado
	beq $s5, 2, repeticoes_max
	beq $s5, 3, repeticoes_max
	beq $s5, 4, repeticoes_fim
	jr $ra

	add_50:
	addi $s1, $s1, 50		#adiciona 50 ao resultado
	beq $t1, $t0, inv_digito
	beq $t3, 88, sub_10		#caso o conteudo do indice anterior seja X, subtrai 10 do resultado
	jr $ra

	add_100:
	beq $t1, 68, ler_proximo	#caso o conteudo do proximo indice seja D, pular para a leitura desse indice
	beq $t1, 77, ler_proximo	#caso o conteudo do proximo indice seja M, pular para a leitura desse indice
	addi $s1, $s1, 100		#adiciona 100 ao resultado
	addi $s5, $s5, 1
	beq $t3, 88, sub_10		#caso o conteudo do indice anterior seja X, subtrai 10 do resultado
	beq $s5, 2, repeticoes_max
	beq $s5, 3, repeticoes_max
	beq $s5, 4, repeticoes_fim
	jr $ra

	add_500:
	addi $s1, $s1, 500	#adiciona 500 ao resultado
	beq $t1, $t0, inv_digito
	beq $t3, 67, sub_100	#caso o conteudo do indice anterior seja C, subtrai 100 do resultado
	jr $ra
	
	add_1000:				
	addi $s1, $s1, 1000	#adiciona 1000 ao resultado
	addi $s5, $s5, 1
	beq $t3, 67, sub_100	#caso o conteudo do indice anterior seja C, subtrai 100 do resultado
	beq $s5, 2, repeticoes_max
	beq $s5, 3, repeticoes_max
	beq $s5, 4, repeticoes_fim
	jr $ra

	#funcoes auxiliares de subtração	
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
	#$t2 = armazena o valor do proximo indice
	#$t3 = conteudo do indice anterior
	#$t4 = armazena o valor do indice anterior
	#$t5 = iterador loop
	#t6 = tamanho vetor

	#definir valores iniciais para os operadores	
	li $s1, 0
	li $t2, 1
	lb $t1, rom($t2)
	li $t4, -1
	li $t5, 0
	li $t6, 13
	la $s2, letras_rom #carregar endereço do vetor com os valores decimais na tabela ascii dos algarismos romanos
	li $t8, 6 # ultimo indice do vetor letras_rom

	j transformar_rom

	transformei_rom:
	bne $s6, 68, transformei	#caso a transformacao nao tenha como objetivo final um numero decimal, carrega o resultado da transformacao em decimal para a conversao desejada		
	j printar_resultado

################ ROM 2 BIN ###############
rom2bin:
j rom2dec #conversao intermediaria
################ ROM 2 HEX ###############
rom2hex:
j rom2dec #conversao intermediaria
