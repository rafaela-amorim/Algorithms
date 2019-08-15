#include <bits/stdc++.h>

using namespace std;

#define MAX 100000005   // 10⁸

bool isPrime[MAX];
vector<int> primes;

void crivo() {
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i < ceil(sqrt(MAX)); i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j < MAX; j += i) 
                isPrime[j] = false;
        }
    }

    // se quiser armazenar todos os numeros primos em um vetor, deve percorrer isPrime novamente ate o fim
    for (int i = 0; i < MAX; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }
}

void memset_() {
    for (int i = 0; i < MAX; i++) 
        isPrime[i] = true;
}


int main() {
    memset_();
    crivo();

    cout << "Consulte se um número x é primo ou nao.\n";
    cout << "Entre -1 para sair do programa..\n";

    int entry;
    cin >> entry;

    while (entry != -1) {
        if (isPrime[entry])
            cout << "É primo.\n";
        else
            cout << "Não é primo.\n";
        
        cin >> entry;
    }


    return 0;
}