//verificão de ciclos
#include <cstdio>
#include <list>
#include <stack>

using namespace std;

class Grafo{
	int V;
	list<int> *adj;
public:
	Grafo(int v){
		V = v;
		adj = new list<int>[V];
	}

	void adiciona(int v1, int v2){
		adj[v1].push_back(v2);
	}

	bool dfs(int ver){
		stack<int> pilha;
		bool visitados[V] = {false};
		bool es_pilha[V] = {false};
		while(true){
			if(!visitados[ver]){
				pilha.push(ver);
				visitados[ver] = es_pilha[ver] = true;
			}
			bool achou_vizinho = false;
			list<int>::iterator it;
			for(it = adj[ver].begin(); it != adj[ver].end(); it++){
				if(!visitados[*it]){
					achou_vizinho = true;
					break;
				}else if(es_pilha[*it]) return true;
			}
			if(achou_vizinho){
				ver = *it;
			}else{
				es_pilha[pilha.top()] = false;
				pilha.pop();
				if(pilha.empty()) return false;
				ver = pilha.top();
			}

		}
	}

};

int main(){
	Grafo g(4);
	g.adiciona(0,1);
	g.adiciona(0,2);
	g.adiciona(1,3);
	g.adiciona(3,2);

	if(g.dfs(0)) printf("tem\n");
	else printf("tem n\n");

	return 0;
}
