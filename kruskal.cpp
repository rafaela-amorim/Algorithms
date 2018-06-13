#include <bits/stdc++.h>

using namespace std;

#define tam 100

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
vector<aresta> come;
vector<aresta> sai;

bool compara(aresta& a1, aresta& a2){
	return a1.peso < a2.peso;
}


int find(int no) {
	if (pais[no] == -1)	return no;
	return pais[no] = find(pais[no]);
}

bool une(int n1, int n2) {
	n1 = find(n1);
	n2 = find(n2);
	if(n1 == n2) return false;
	pais[n1] = n2;
	return true;
}

void kruskal(){
	sort(come.begin(),come.end(),compara);
	for(auto ares: come){
		if(une(ares.v1, ares.v2)){
			sai.push_back(ares);
		}
	}
}


int main() {


	return 0;
}