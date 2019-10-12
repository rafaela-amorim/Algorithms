#include <bits/stdc++.h>

using namespace std;

int main(){
	int matriz[1000][1000];
	int soma[1000][1000];
	int largura, altura;
	scanf("%d %d",&altura,&largura);
	memset(soma,0,sizeof(int)*altura*largura);
	for(int i = 1; i <= altura; i++){
		for(int j = 1; j <= largura; j++){
			scanf("%d",&matriz[i][j]);
		}
	}
	//contruindo matriz de soma
	for(int i = 1; i <= altura; i++){
		for(int j = 1; j <= largura; j++){
			soma[i][j] = matriz[i][j] + soma[i-1][j] + soma[i][j-1] - soma[i-1][j-1];
		}
	}
	//printando matriz de soma
	for(int i = 0; i <= altura; i++){
		for(int j = 0;j <= largura; j++){
			cout << soma[i][j] << " \n"[j == largura];
		}
	}
	//consultas na matriz
	while(true){
		int n1,n2,m1,m2;
		cin >> n1 >> n2;
		cin >> m1 >> m2;
		n1++;
		n2++;
		int infDir = soma[n1][n2];
		int supDir = soma[n1 - (n1 - m1)][n2];
		int infEsq = soma[n1][n2 - (n2 - m2)];
		int supEsq = soma[m1][m2];
		printf("%d %d %d %d\n",infDir,supEsq,supDir,infEsq);
		printf("%d\n",infDir + supEsq - supDir - infEsq);
	}
}







