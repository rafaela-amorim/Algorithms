//kruskal
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class aresta{
public:
	int v1,v2,peso;
	aresta(int v1, int v2, int peso){
		this->v1 = v1;
		this->v2 = v2;
		this->peso = peso;
	}

	bool operator<(const aresta &p){
		return peso < p.peso;
	}
};



class grafo{
public:
	int v;
	vector<aresta> ares;
	grafo(int v){
		this->v = v;
	}

	void adicionarAresta(int v1, int v2, int peso){
		aresta ar(v1,v2,peso);
		ares.push_back(ar);
	}

	int find(int vet[],int p){
		if(vet[p] == -1) return p;
		return vet[p] = find(vet,vet[p]);
	}

	bool unir(int vet[], int v1, int v2){
		v1 = find(vet,v1);
		v2 = find(vet,v2);
		if(v1 == v2) return false;
		vet[v1] = v2;
		return true;
	}

	void kruskal(){
		vector<aresta> sai;
		int size = ares.size();
		sort(ares.begin(),ares.end());
		int vet[v];
		memset(vet,-1,sizeof(int)*v);
		for(int i = 0; i < size; i++){
			if(unir(vet,ares[i].v1,ares[i].v2)) sai.push_back(ares[i]);
		}
		for(int i = 0; i < sai.size(); i++){
			printf("(%c,%c) -> %d\n", sai[i].v1+ 'A', sai[i].v2+ 'A', sai[i].peso);
		}
	}
};

int main(){
	grafo g(7); // grafo
	
	// adiciona as arestas
	g.adicionarAresta(0, 1, 7);
	g.adicionarAresta(0, 3, 5);
	g.adicionarAresta(1, 2, 8);
	g.adicionarAresta(1, 3, 9);
	g.adicionarAresta(1, 4, 7);
	g.adicionarAresta(2, 4, 5);
	g.adicionarAresta(3, 4, 15);
	g.adicionarAresta(3, 5, 6);
	g.adicionarAresta(4, 5, 8);
	g.adicionarAresta(4, 6, 9);
	g.adicionarAresta(5, 6, 11);

	g.kruskal();

	return 0;
}
