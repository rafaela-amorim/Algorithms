#include <cstdio>
#include <queue>
using namespace std;

int main(){
	priority_queue<int, vector<int>, greater<int> > pq;
	//priority_queue<int, vector<int>, greater<int> > pq; -> menor para o maior
	//priority_queue<int, vector<int>, less<int> > pq; -> maior pra o menor
	pq.push(10);//coloca na fila
	pq.push(1);
	pq.push(55);

	printf("topo : %d\n",pq.top());

	if(pq.empty()) printf("vazia\n");
	else printf("nao vazia\n");

	printf("elementos: ");
	while(!pq.empty()){
		printf("%d ",pq.top());
		pq.pop();//retira da da frente da fila
	}putchar('\n');

	printf("tamanho: %li\n",pq.size());

	return 0;
}
