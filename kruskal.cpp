#include <bits/stdc++.h>

using namespace std;

#define tam 105

class aresta{
public:
	int v1;
	int v2;
	int peso;
	aresta(int v1, int v2, int peso){
		this->v1 = v1;
		this->v2 = v2;
		this->peso = peso;
	}
};

int pais[tam];
vector<aresta> entra;
vector<aresta> sai;

bool compara(aresta& a1, aresta& a2){
	return a1.peso < a2.peso;
}

bool comparaBuscaBinaria(aresta& a1, aresta& a2) {
	return a1.v1 == a2.v1 && a1.v2 == a2.v2;
}

int find(int no) {
	if (pais[no] == -1)	return no;
	return pais[no] = find(pais[no]);
}

bool une(int n1, int n2) {
	n1 = find(n1);
	n2 = find(n2);
	if(n1 == n2) 	return false;
	pais[n1] = n2;
	return true;
}

void limpa() {
	entra.clear();
	sai.clear();
	memset(pais, -1, tam * sizeof(int));
}

void kruskal(){
	sort(entra.begin(),entra.end(),compara);
	for(auto ares: entra){
		if(une(ares.v1, ares.v2)){
			sai.push_back(ares);
		}
	}
}

int main() {
	int n, m;
	int v1, v2, peso;

	int cont = 0, aux;
	vector<aresta> guarda;

	while (true) {
		limpa();

		cin >> n >> m;
		if (n == 0 && m == 0)	break;

		for (int i = 0; i < m; i++) {
			cin >> v1 >> v2 >> peso;
			entra.push_back(aresta(v1, v2, peso));
		}

		kruskal();

		cout << "Teste " << ++cont << endl;

		for(auto ligacoes: sai){
			if (ligacoes.v1 > ligacoes.v2) {
				aux = ligacoes.v1;
				ligacoes.v1 = ligacoes.v2;
				ligacoes.v2 = aux;
			}
			
			cout << ligacoes.v1 << " " << ligacoes.v2 << endl;
			// falta verificar se já teve uma ligação igual
		}

		cout << endl;
	}

	return 0;
}