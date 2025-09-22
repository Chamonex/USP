"""
Problema:
- 2 tipos de vigas, 3 períodos
- Demandas conhecidas: Item 1 = [100, 40, 60], Item 2 = [30, 20, 80]  
- Tempos de produção: Item 1 = 15 min/unidade, Item 2 = 20 min/unidade
- Capacidade: 40 horas/período = 2400 minutos/período
- Custos de estoque: Item 1 = [2, 3] Item 2 = [2.5, 3.5]
- Possibilidade de horas extras com custo X por hora
"""

import math
from pyscipopt import Model

# custo por hora extra
X = int(input())

model = Model("LotSizing_Vigas")

model.setParam("display/verblevel", 0)

num_itens = 2
num_periodos = 3

# ------------------- INFORMAÇÕES CONHECIDAS -------------------
demandas = [
    [100, 90, 120],
    [40, 50, 80]
]

tempo_producao = [15, 20]

custo_producao = [
    [20, 20, 30],
    [20, 20, 30]
]

custo_estoque = [
    [2, 3, 0],
    [2.5, 3.5, 0]
]

capacidade = 40 * 60

# ------------------- VARIÁVEIS DE DECISÃO -------------------

# Tamanho de lotes por período
x = []
for i in range(num_itens):
    linha = []
    for t in range(num_periodos):
        var = model.addVar(f"x_{i+1}_{t+1}", vtype="CONTINUOUS", lb=0)
        linha.append(var)
    x.append(linha)

# Uso de estoque por período
s = []
for i in range(num_itens):
    linha = []
    for t in range(num_periodos):
        var = model.addVar(f"s_{i+1}_{t+1}", vtype="CONTINUOUS", lb=0)
        linha.append(var)
    s.append(linha)

# minutos de hora extra por período
e = []
for t in range(num_periodos):
    var = model.addVar(f"e_{t+1}", vtype="CONTINUOUS", lb=0)
    e.append(var)

# ------------------- FUNÇÃO OBJETIVO -------------------

obj = 0
# custos de producao
for i in range(num_itens):
    for t in range(num_periodos):
        obj += custo_producao[i][t] * x[i][t]

# custos de estoque
for i in range(num_itens):
    for t in range(num_periodos -1):
        obj += custo_estoque[i][t] * s[i][t]

# custos de hora extra (min)
for i in range(num_periodos):
    obj += (X / 60) * e[i]

model.setObjective(obj, "minimize")

# ------------------- RESTRIÇÕES -------------------

# conservação de fluxo (balanço de estoque para cada item e período)
for i in range(num_itens):
    for t in range(num_periodos):
        if t == 0:
            # primeiro período: estoque inicial = 0
            model.addCons(x[i][t] == demandas[i][t] + s[i][t])
        else:
            # períodos seguintes: estoque anterior + produção = demanda + estoque atual
            model.addCons(s[i][t-1] + x[i][t] == demandas[i][t] + s[i][t])

# horas extras
# as horas extras de cada período = horas trabalhadas - 40
for t in range(num_periodos):
    tempo_gasto = x[0][t] * tempo_producao[0] + x[1][t] * tempo_producao[1]
    model.addCons(e[t] >= tempo_gasto - capacidade)

# não negatividade
for i in range(num_itens):
    for t in range(num_periodos):
        # estoque não pode ser negativo
        model.addCons(s[i][t] >= 0)
        # produção não pode ser negativa
        model.addCons(x[i][t] >= 0)

# horas extras não podem ser negativas
for t in range(num_periodos):
    model.addCons(e[t] >= 0)

# ------------------- RESOLIÇÃO -------------------

model.optimize()
print(int(model.getObjVal()))

# if model.getStatus() == "optimal":
#     sol = model.getBestSol()
#     custo_total = model.getObjVal()
#     print("\n=== SOLUÇÃO ÓTIMA ===")
#     print(f"Custo total: {custo_total:.2f}")
    
#     print("\n--- PRODUÇÃO (x) ---")
#     for i in range(num_itens):
#         for t in range(num_periodos):
#             valor = model.getVal(x[i][t])
#             print(f"x[{i+1}][{t+1}] = {valor:.2f}")
    
#     print("\n--- ESTOQUE (s) ---")
#     for i in range(num_itens):
#         for t in range(num_periodos):
#             valor = model.getVal(s[i][t])
#             print(f"s[{i+1}][{t+1}] = {valor:.2f}")
    
#     print("\n--- HORAS EXTRAS (e) ---")
#     for t in range(num_periodos):
#         valor = model.getVal(e[t])
#         print(f"e[{t+1}] = {valor:.2f} minutos")
        
#     print("\n--- VERIFICAÇÃO DE CAPACIDADE ---")
#     for t in range(num_periodos):
#         tempo_usado = model.getVal(x[0][t]) * tempo_producao[0] + model.getVal(x[1][t]) * tempo_producao[1]
#         print(f"Período {t+1}: {tempo_usado:.2f} minutos (capacidade: {capacidade} min)")
# else:
#     print("Nenhuma solução ótima encontrada.")