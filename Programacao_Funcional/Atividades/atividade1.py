# Faça um programa em Python, utilizando os conceitos de programação do paradigma
# funcional, que leia dois inteiros x e y, sendo que x é menor que y, e imprima
# o comprimento do maior intervalo entre dois números primos consecutivos maiores ou 
# iguais a x e menores ou iguais a y.


def e_primo(x, y):

    # VER SE O NUMERO X É PRIMO
    # y vai entrar como (x-1), e vai ir diminuindo até 2
    # se chegar em 1, retorna TRUE, x é primo
    # se em algum momento x%y == 0, x não é pimo

    if(y == 1):
        return True
    
    elif (x % y == 0):
        return False

    else:
        return e_primo(x, y-1)



def encontrar_primos(x, y, anterior, resultado):
    # Procurar um primo no conjunto [x , y]
    # vou aumentando x
    # se x > y, nao encontrou nenhum primo

    if (x > y):
        return resultado

    elif (e_primo(x, x-1)):

        if (anterior != 0):
            resultado_imediato = x - anterior
            if (resultado_imediato > resultado):
                return encontrar_primos(x+1, y, x, resultado_imediato)
            else:
                return encontrar_primos(x+1, y, x, resultado)
        
        else:
            return encontrar_primos(x+1, y, x, resultado)
            
    
    else:
        return encontrar_primos(x+1, y, anterior, resultado)



x = int(input())
y = int(input())


print(encontrar_primos(x, y, 0, 0))
