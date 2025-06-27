#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Pilha {
    double dados[100];
    int topo;
};

void inicializaPilha(Pilha& p) {
    p.topo = -1;
}

void push(Pilha& p, double valor) {
    p.dados[++p.topo] = valor;
}

double pop(Pilha& p) {
    return p.dados[p.topo--];
}

bool estaVazia(Pilha& p) {
    return p.topo == -1;
}

int main() {
    Pilha pilha;
    inicializaPilha(pilha);
    
    string linha, token;
    
    cout << "Digite a expressão RPN: ";
    getline(cin, linha);
    
    stringstream ss(linha);
    
    while (ss >> token) {
        if (token == "+") {
            double b = pop(pilha);
            double a = pop(pilha);
            push(pilha, a + b);
        }
        else if (token == "-") {
            double b = pop(pilha);
            double a = pop(pilha);
            push(pilha, a - b);
        }
        else if (token == "*") {
            double b = pop(pilha);
            double a = pop(pilha);
            push(pilha, a * b);
        }
        else if (token == "/") {
            double b = pop(pilha);
            double a = pop(pilha);
            push(pilha, a / b);
        }
        else {
            double numero = stod(token);
            push(pilha, numero);
        }
    }
    
    cout << "Resultado: " << pop(pilha) << endl;
    
    return 0;
}