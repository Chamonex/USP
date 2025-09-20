# Estudos - Pesquisa Operacional

## Lot Sizing

[Artigo Unicamp](https://www.ime.unicamp.br/~mac/db/2011-2S-083552.pdf)

É um processo hierárquico, que envolve decisões a longo, médio e curto prazo, gerando uma necessidade por melhora e integração dos níveis de produção

Nesse contexto, o objetivo principal
´e determinar o tamanho dos lotes de produ¸c˜ao e o instante de tempo de
produ¸c˜ao de modo a suprir uma certa demanda em um horizonte de planejamento finito
## Exemplo Básico de Programação Inteira Mista com PySCIPOpt

### Descrição do Problema

O código no arquivo `Teste_Solver.ipynb` implementa um exemplo simples de **Programação Inteira Mista (MIP)** usando a biblioteca PySCIPOpt, que é uma interface Python para o solver SCIP (Solving Constraint Integer Programs).

### Formulação Matemática

O problema resolvido pode ser formulado como:

**Minimizar:** z = y

**Sujeito a:**
- 2x + y ≥ 3
- x ∈ {0,1} (variável binária)
- y ∈ ℤ⁺ (variável inteira não-negativa)

### Componentes do Código

#### 1. **Criação do Modelo**
```python
model = Model("Example")
```
Cria uma instância do modelo de otimização com nome opcional "Example".

#### 2. **Definição das Variáveis**
- **x**: Variável binária que pode assumir apenas os valores 0 ou 1
- **y**: Variável inteira não-negativa que pode assumir qualquer valor inteiro ≥ 0

#### 3. **Função Objetivo**
```python
model.setObjective(y)
```
Define que queremos **minimizar** a variável y. Por padrão, o SCIP assume minimização.

#### 4. **Restrições**
```python
model.addCons(-2*x - y <= -3)
```
Adiciona a restrição -2x - y ≤ -3, que é equivalente a 2x + y ≥ 3.

#### 5. **Otimização e Solução**
```python
model.optimize()
sol = model.getBestSol()
```
Resolve o problema e recupera a melhor solução encontrada.

### Análise da Solução

Para resolver este problema, precisamos encontrar os menores valores de x e y que satisfaçam a restrição 2x + y ≥ 3.

**Casos possíveis:**

1. **Se x = 0:** 
   - Restrição fica: 0 + y ≥ 3 → y ≥ 3
   - Menor valor: y = 3
   - Função objetivo: z = 3

2. **Se x = 1:** 
   - Restrição fica: 2 + y ≥ 3 → y ≥ 1
   - Menor valor: y = 1
   - Função objetivo: z = 1

**Solução ótima:** x = 1, y = 1, com valor ótimo z = 1

### Importância Educacional

Este exemplo é fundamental para entender:

1. **Sintaxe do PySCIPOpt**: Como criar modelos, variáveis, função objetivo e restrições
2. **Tipos de variáveis**: Diferença entre variáveis contínuas, inteiras e binárias
3. **Formulação de problemas**: Como traduzir um problema matemático para código
4. **Interpretação de resultados**: Como extrair e verificar a solução ótima

### Aplicações Práticas

Embora seja um exemplo simples, este tipo de formulação é a base para problemas mais complexos como:
- **Problemas de dimensionamento de lotes (Lot Sizing)**
- **Problemas de roteamento**
- **Problemas de scheduling**
- **Otimização de portfólios com restrições inteiras**

### Próximos Passos

Este exemplo serve como base para implementar modelos mais complexos de Lot Sizing, que são o foco principal desta atividade da disciplina.