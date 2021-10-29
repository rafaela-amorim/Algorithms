#include <bits/stdc++.h>

using namespace std;

#define max 10100
#define INF 999999999
#define duo pair<int,int>

int distancias[max];
bool visitados[max];
vector<duo> list_adj[max];// vertice -> distancia

int dijkstra(int origem, int destino){
	priority_queue<duo, vector<duo>, greater<duo> > pq;//distancia -> vertice
	distancias[origem] = 0;
	pq.push(make_pair(0,origem));

	while(!pq.empty()){
		duo frente = pq.top();
		int vertice_pai = frente.second;
		visitados[vertice_pai] = true;
		pq.pop();

		for(auto no: list_adj[vertice_pai]){
			int vertice = no.first;
			int peso = no.second;
			if(!visitados[vertice]){
				if(distancias[vertice] > (distancias[vertice_pai] + peso)){
					distancias[vertice] = (distancias[vertice_pai] + peso);
					pq.push(make_pair(distancias[vertice],vertice));
				}
			}
		}
	}
	return distancias[destino];
}


void limpa(){
	for(int i = 0; i < max; i++){
		visitados[i] = false;
		distancias[i] = INF;
		list_adj[i].clear();
	}
}

int main(){
	limpa();
	list_adj[1].push_back(make_pair(2,90));
	list_adj[1].push_back(make_pair(4,10));
	list_adj[2].push_back(make_pair(3,50));
	list_adj[3].push_back(make_pair(5,30));
	list_adj[4].push_back(make_pair(3,20));

	cout << dijkstra(1,5) << endl;


	return 0;
}
