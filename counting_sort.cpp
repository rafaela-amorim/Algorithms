#include <bits/stdc++.h>

using namespace std;

void countingSort(int lista[], int tam) {
	int minimo = lista[0];
	int maximo = lista[0];

	for (int i = 1; i < tam; i++) {
		if (lista[i] < minimo)	minimo = lista[i];
		if (lista[i] > maximo)	maximo = lista[i];
	}

	int count[maximo - minimo + 1];
	int saida[tam];

	for (int i = 0; i <= maximo - minimo; i++) 
		count[i] = 0;	

	for (int i = 0; i < tam; i++) 
		count[lista[i] - minimo]++;

	for (int i = 1; i <= (maximo - minimo); i++) 
		count[i] += count[i - 1];

	for (int i = tam - 1; i >= 0; i--) 
		saida[(--count[(lista[i] - minimo)])] = lista[i];

	for (int i = 0; i < tam; i++)
		lista[i] = saida[i];
}

int main() {
	int lista[6] = {4,2,3,1,4,2};

	countingSort(lista, 6);

	for (auto i: lista) {
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}
