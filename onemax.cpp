#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>


#define tam_genes 50
#define tam_pop 50
#define tam_torn 20
#define geracoes 500
#define prob_mul 0.2
#define prob_cruza 0.5

using namespace std;

vector<vector<int>> popula(tam_pop);

void preenche(){
	for(int i = 0; i < tam_pop; i++){
		vector<int> v(tam_genes);
		for(int j = 0; j < tam_genes; j++){
			v[j] = rand()%2;
		}
		popula[i] = v;
	}
}

void multa(vector<int> &a){
	int gene = rand()%tam_genes;
	if(a[gene] == 0) a[gene] = 1;
	else a[gene] = 0;
}

vector<int> cruzamento(int ind_pai1, int ind_pai2){
	vector<int> filho(tam_genes);
	int ponto = rand()%tam_genes;

	for(int i = 0; i <= ponto; i++)
		filho[i] = popula[ind_pai1][i];
	for(int i = ponto + 1; i < tam_genes; i++)
		filho[i] = popula[ind_pai2][i];
	return filho;
}

int obtemPont(vector<int> &a){
	int soma = 0;
	for(int i = 0; i < tam_genes; i++){
		soma += a[i];
	}
	return soma;
}

int obtemMelhor(){
	int melhor = 0;
	int pontMelhor = obtemPont(popula[0]);
	for(int i = 1; i < tam_pop; i++){
		if(pontMelhor < obtemPont(popula[i])){
			melhor = i;
			pontMelhor = obtemPont(popula[i]);
		}
	}
	return melhor;
}

void mostra(){
	for(int i = 0; i < tam_pop; i++){
		for(int j = 0; j < tam_genes; j++){
			printf("%d ",popula[i][j]);
		}printf("\n");
	}
}

int main(){
	srand(time(0));
	preenche();
	for(int i = 0; i < geracoes; i++){
		for(int j = 0; j < tam_torn; j++){
			double porCruza = (double)rand() / RAND_MAX;
			if(porCruza < prob_cruza){

				int pai1 = rand()%tam_pop;
				int pai2 = rand()%tam_pop;
				while(pai2 == pai1) pai2 = rand()%tam_pop;

				vector<int> filho = cruzamento(pai1,pai2);

				double porMul = (double)rand() / RAND_MAX;
				if(porMul < prob_mul)
					multa(filho);

				if(obtemPont(filho) > obtemPont(popula[pai1]))
					popula[pai1] = filho;

			}
		}
		// mostra();
		// printf("\n");
		int melhor = obtemMelhor();
		int pontos = obtemPont(popula[melhor]);
		printf("da geração %d o melhor foi: %d pontos: %d\n",i,melhor,pontos);
		for(int k = 0; k < tam_genes; k++){
			printf("%d ",popula[melhor][k]);
		}printf("\n\n");
		if(pontos == tam_genes) break;
	}
	return 0;
}
