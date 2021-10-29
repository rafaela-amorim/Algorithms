#include <cstdio>

using namespace std;


int vet[] = {1,2,3,-1,-1};

int find(int p){
	if(vet[p] == -1) return p;
	return vet[p] = find(vet[p]);
}

void uni(int p, int q){
	p = find(p);
	q = find(q);
	vet[p] = q;
}

int main(){
	uni(0,4);
	for(int i = 0; i < 5; i++) printf("%d ",vet[i]);
	putchar('\n');
	return 0;
}
