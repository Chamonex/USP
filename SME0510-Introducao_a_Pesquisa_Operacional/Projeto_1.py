import numpy
import numpy as np
from haversine import haversine
from scipy.optimize import linprog
import matplotlib.pyplot as plt


# Função utilizada para obter os custos de cada
# par de coordenada.
def get_cost(coord1, coord2):
    tk: float = 0
    if (coord1[2] == 'saae'):
        if (coord2[2] == 'saae'):
            tk = 0.63
        elif (coord2[2] == 'universidade'):
            tk = 0.59
    if (coord1[2] == 'universidade'):
        if (coord2[2] == 'saae'):
            tk = 0.63
        elif (coord2[2] == 'universidade'):
            tk = 0.94


    point1 = coord1[0:2]
    point2 = coord2[0:2]

    print(haversine(point1, point2) * tk)

    return haversine(point1, point2) * tk

coords = [
    (-22.056067, -47.906624, "saae"),
    (-22.029408, -47.874192, "saae"),
    (-22.022213, -47.897600, "saae"),
    (-22.009414, -47.892042, "saae"),
    (-22.005740, -47.873665, "saae"),
    (-22.007573, -47.889043, "saae"),
    (-22.006214, -47.899628, "saae"),
    (-21.989030, -47.917174, "saae"),
    (-22.989030, -47.917174, "universidade"),
    (-22.008018, -47.896600, "universidade"),
    (-21.983547, -47.880959, "universidade")
]

# Array de custos (pronta)
c = np.zeros(11 * 11, dtype=float)
x = 0
for i in range (len(coords)):
    for j in range (len(coords)):
        print("i", i, "j", j)
        c[x] = get_cost(coords[i], coords[j])
        x += 1




# A_eq = COEFICIENETS DAS RESTRIÇÕES DE IGUALDADE
#       ---->COMPLETAR<----
#               - ela precisa ter 2 dimensões e ser 11 por 11
#               - conter apenas os coeficientes
a_eq = numpy.zeros((len(coords), len(coords)), dtype=float)


# Suprimento em litros
# Coeficientes das restrições de igualdade
b_eq = [
    30000,
    40000,
    50000,
    30000,
    50000,
    30000,
    30000,
    90000,
    -120000,
    -100000,
    -130000
]

# Resolvendo o problema:
res = linprog(c, A_eq=a_eq, b_eq=b_eq, method=('simplex'))

#Plot da função objetivo mínima
plt.figure(figsize=(8, 6))
plt.plot(res.x[0], res.x[1], 'ro', label=("Solução Ótima"))
plt.title('Solução Ótima da Função Objetivo')
plt.grid(True)
plt.show()

