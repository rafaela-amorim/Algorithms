#include <bits/stdc++.h>


using namespace std;

bool escolhido[10000];
vector<int> elementos;
int tam;

void printa(){
	for(int i = 0; i < elementos.size(); i++){
		cout << elementos[i] << " \n"[i == elementos.size()-1];
	}
}

void search(){
	if(elementos.size() == tam){
		printa();
	}else{
		for(int i = 0; i < tam; i++){
			if(escolhido[i]) continue;
			escolhido[i] = true;
			elementos.push_back(i);
			search();
			escolhido[i] = false;
			elementos.pop_back();
		}
	}
}

int main(){
	memset(escolhido, false, 10000);
	cin >> tam;	
	search();
	return 0;
}
