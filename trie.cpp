#include <bits/stdc++.h>

using namespace std;

struct node{
	node *child[30];
	char c;
	int vezes;
	bool fim;
};

node *getnode(){
	node *a = new node;
	a->fim = false;
	a->vezes = 0;
	for(int i = 0; i < 30; i++){
		a->child[i] = NULL;
	}
	return a;
}


void insert(node *root, string pal){
	node *aux = root;
	for(int i = 0; i < pal.size(); i++){
		int index = pal[i] - 'a';
		if(!aux->child[index])
			aux->child[index] = getnode();
		aux = aux->child[index];
		aux->vezes++;
		aux->c = pal[i];
	}
	aux->fim = true;

}

int search(node *root,string pal){
	node *aux = root;
	for(int i = 0; i < pal.size(); i++){
		int index = pal[i] - 'a';
		if(!aux->child[index])
			return 0;
		aux = aux->child[index];
	}
	if(!aux) return 0;
	return aux->vezes;
}


int main(){
	node *root = getnode();
	string pal[] = {"matheus","matheee","uououou","mat"};
	for(int i = 0; i < 4;i++){
		insert(root,pal[i]);
	}
	cout << search(root,"matheusaaa") << endl;
	return 0;
}
