# Calculadora RPN 

## Visão Geral

Uma calculadora que processa expressões em notação polonesa reversa (RPN) usando C++. <br><br>
Para rodar o projeto em uma máquina linux basta clonar o repositório, entrar nele, e rodar `./pilha`
Exemplo de uso: `3 4 +` resulta em `7`. 

## Estrutura de Dados 

### Pilha (Stack)
Criei uma estrutura `Pilha` como base:

```cpp
struct Pilha {
    double dados[100];
    int topo;
};
```

## Operações da Pilha

### Inicialização
```cpp
void inicializaPilha(Pilha& p) {
    p.topo = -1;
}
```

### Push (Empilhar)
```cpp
void push(Pilha& p, double valor) {
    p.dados[++p.topo] = valor;
}
```
Primeiro incremento `topo`, depois insere o valor.

### Pop (Desempilhar)
```cpp
double pop(Pilha& p) {
    return p.dados[p.topo--];
}
```
Retorna o elemento atual e depois decremento `topo`.

### Verificação de Vazia
```cpp
bool estaVazia(Pilha& p) {
    return p.topo == -1;
}
```

## Algoritmo Principal

### Estratégia de Parsing
Usei `stringstream` para quebrar a entrada em tokens, que já lida com espaços em branco e separa números e operadores.

```cpp
stringstream ss(linha);
while (ss >> token) {
    // processamento de cada token
}
```

### Lógica de Processamento

Para cada token, implementei:

1. **Se for operador (`+`, `-`, `*`, `/`):**
   - Desempilha dois operandos
   - Realiza a operação
   - Empilha o resultado

2. **Se for número:**
   - Converte para `double` usando `stod()`
   - Empilha na pilha

### Ordem dos Operandos

```cpp
double b = pop(pilha);  // segundo operando
double a = pop(pilha);  // primeiro operando
push(pilha, a - b);     // a - b, não b - a
```

Como a pilha inverte a ordem, o último elemento empilhado é o segundo operando da operação.

## Exemplo de Execução

Para a expressão `5 3 - 2 *`:

1. `5` → pilha: `[5]`
2. `3` → pilha: `[5, 3]`
3. `-` → desempilha 3 e 5, calcula 5-3=2 → pilha: `[2]`
4. `2` → pilha: `[2, 2]`
5. `*` → desempilha 2 e 2, calcula 2*2=4 → pilha: `[4]`
6. Resultado: `4`

## Conclusão

Esse algoritmo é simples e lúdico: empilha números, desempilha para operações, e o resultado final permanece no topo da pilha.