import numpy as np
from haversine import haversine
from scipy.optimize import linprog
import matplotlib.pyplot as plt

# Obter custo
def get_cost(coord1, coord2):
    tk: float = 0
    if (coord1[2] == 'saae'):
        if (coord2[2] == 'saae'):
            tk = 0.53
        elif (coord2[2] == 'universidade'):
            tk = 0.83
    if (coord1[2] == 'universidade'):
        if (coord2[2] == 'saae'):
            tk = 0.83
        elif (coord2[2] == 'universidade'):
            tk = 0.71

    point1 = coord1[0:2]
    point2 = coord2[0:2]
    return haversine(point1, point2) * tk


# Coordenadas
coords = [(-22.056067, -47.906624, "saae"), (-22.029408, -47.874192, "saae"),
          (-22.022213, -47.897600, "saae"), (-22.009414, -47.892042, "saae"),
          (-22.005740, -47.873665, "saae"), (-22.007573, -47.889043, "saae"),
          (-22.006214, -47.899628, "saae"), (-21.989030, -47.917174, "saae"),
          (-22.008774, -47.929795, "universidade"),
          (-22.008018, -47.896600, "universidade"),
          (-21.983547, -47.880959, "universidade")]

# Array de custos
c = np.zeros(110, dtype=float)
x = 0
for i in range(len(coords)):
    for j in range(len(coords)):
        if i == j:
            continue
        c[x] = get_cost(coords[i], coords[j])
        x += 1
print(c)

# MATRIZ DE INEQUAÇÃO
# Eu não soube transformar o somatório em uma matriz de equação
A = np.zeros((11, 110), dtype=int)
for i in range(11):
    for j in range(10):
        A[i, 10 * i + j] = 1
    for j in range(110):
        indice_1 = j // 10
        indice_2 = j % 10 if (j % 10 < indice_1) else (j % 10) + 1
        if indice_2 == i:
            A[i, j] = -1
np.set_printoptions(threshold=np.inf)
print(A)

# Fluxo de água
b = [
    30, 40, 50, 30, 50, 30, 30, 90, -120, -100,-130
]

#           LINPROG
# c = array de custo.           FEITO
# A = matriz de inequação       NÃO SOUBE  !!!!!!!!!!!!
# b = fluxo de água             OK
# bounds = default              OK

res = linprog(c, A_eq=A, b_eq=b)

print(len(res.x))

x = []
y = []

for i in range(len(coords)):
    x[i] = coords[i][0]
    y[i] = coords[i][1]

