#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

int sparse[MAX][(int)log2(MAX) + 1];
int nums[MAX];

// ---------------------------

void build(int tam) {
	for (int i = 0; i < tam; i++) 
		sparse[i][0] = nums[i];
	
	int lim = log2(tam);

	for (int j = 1; j <= lim; j++) {
		for (int i = 0; i + (1 << j-1) < tam; i++) {
			sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << j-1)][j-1]);
		}
	}
}

int query() {	// oq vem aqui??

}

// ---------------------------

int main() {
	return 0;
}
