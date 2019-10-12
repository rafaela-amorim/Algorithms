 
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;

class Individuo{
public:
	double a,b,c,d;
	string classe;

	Individuo(double a, double b, double c, double d, string classe){
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->classe = classe;
	}

};

double obDist(Individuo &a, Individuo &b){
	double soma = pow(a.a - b.a, 2) +
				  pow(a.b - b.b, 2) +
				  pow(a.c - b.c, 2) +
				  pow(a.d - b.d, 2);
	return sqrt(soma);
}

string obtClasse(vector<Individuo> &v, Individuo &ava, int k){
	if(!(k%2)){
		k--;
		if(k < 0) k = 1;
	}
	int tam_vet = v.size();

	set<pair<double, string>> dista;

	for(int i = 0; i < tam_vet; i++){
		double dis = obDist(v[i], ava);
		dista.insert(make_pair(dis,v[i].classe));
		if(dista.size() > (k+2)) dista.erase(--dista.end());
	}
	set<pair<double, string>>::iterator it;
	int aux = 0;
	vector<int> cont(3);

	for(it = dista.begin(); it != dista.end(); it++, aux++){
		if(it->second == "Iris-setosa") cont[0]++;
		else if(it->second == "Iris-versicolor") cont[1]++;
		else cont[2]++;	
		if(aux > k) break;
 	}

	int indi = 0;
	vector<string> v1 ={"Iris-setosa","Iris-versicolor","Iris-virginica"};

	for(int i = 1; i < 3; i++)
		if(cont[indi] < cont[i]) indi = i;

	return v1[indi];

}



int main(){
	vector<Individuo> indivis;
	int tam_testes = 50;
	int k = 9;

	for(int i = 0; i < tam_testes; i++){
		double a,b,c,d;
		string e;
		cin >> a >> b >> c >> d >> e;
		Individuo in(a,b,c,d,e);
		indivis.push_back(in);
	}

	int testes = 150 - tam_testes;
	int acertos = 0;
	for(int j = 0; j < testes; j++){
		double a,b,c,d;
		string e;
		cin >> a >> b >> c >> d >> e;
		Individuo in(a,b,c,d,e);
		string obtido = obtClasse(indivis,in,k);
		printf("obtido:%s\nesperado:%s\n\n",obtido.c_str(),e.c_str());
		if(obtido == e) acertos++;
	}

	printf("%d acertos de %d\n",acertos,testes);
	return 0;
}
