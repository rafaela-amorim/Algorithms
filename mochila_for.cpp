#include <cstdio>
#include <vector>

using namespace std;

class obj{
public:
	int peso;
	int bene;
	obj(int peso, int bene){
		this->peso = peso;
		this->bene = bene;
	}
};

int mochila(vector<obj>& ob, int peso){
	int tam = ob.size();
	int matriz[tam + 1][peso + 1];
	for(int i = 0; i <= tam; i++){
		for(int j = 0; j <= peso; j++){
			matriz[i][j] = 0;
		}
	}
	for(int i = 1; i <= peso; i++){
		for(int j = 1; j <= tam; j++){
			int sum = matriz[j - 1][i];
			if(ob[j - 1].peso <= i){
				int aux = i - ob[j - 1].peso;
				if((ob[j - 1].bene + matriz[j - 1][aux]) > sum)
					sum = ob[j-1].bene + matriz[j - 1][aux];
			}
			matriz[j][i] = sum;
		}
	}
	for(int i = 0; i <= tam; i++){
		for(int j = 0; j <= peso; j++){
			if(!j%peso) putchar('\n');
			printf("%d ",matriz[i][j]);
		}
	}putchar('\n');
	return matriz[tam][peso];
}


int main(){
	vector<obj> ob = {{4,5},{2,4},{1,3},{3,4}};
	printf("%d\n",mochila(ob,11));
	return 0;
}
