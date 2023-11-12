#include "Hashing.h"
#include <iostream>
#include <cstring>
using namespace std;

//https://www.ime.usp.br/pf/estruturas-de-dados/aulas/st-hash.html#::text=Fun%C3%A7%C3%A3o%20de%20espalhamento%20ou%20fun%C3%A7%C3%A3o,chaves%20pela%20tabela%20de%20hash.
Hashing::Hashing(int _tam) {
    tam = _tam;
    quant_colisoes = 0;
    vet = new Lista * [tam];
    for (int i = 0; i < tam; i++)
        vet[i] = 0;
}

int Hashing::getTam() {
    return tam;
}
int Hashing::f(char* str) {
    unsigned int valor = 0;

    for (int i = 0; i < strlen(str); i++) {
        valor = (7 * valor + str[i]) % tam;
    }

    return valor;
}

void Hashing::insere(Player* p) {
    int hachi = f(p->getName());
    if (vet[hachi] != 0) {
        (vet[hachi])->insere_Fim(p);
        quant_colisoes++;
    }
    else {
        vet[hachi] = new Lista();
        (vet[hachi])->insere_Fim(p);
        quant_colisoes++;
    }
}

void Hashing::imprime() {
    for (int i = 0; i < tam; i++) {
        if (vet[i]) {
            vet[i]->imprime();
            cout << endl;
        }

    }
}

int Hashing::getQuantColisoes() {
    return quant_colisoes;
}