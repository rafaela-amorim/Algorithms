#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

int BITree[MAX];
int nums[MAX];

// ----------------------------------

void update(int ind, int val) {
	int i = ind;
	while (i + (i & -i) <= MAX) {
		BITree[i] += val;
		i += (i & -i);
	}	   
}

int query(int ind) {	// the sum of the subarray [1...ind]
	int soma = 0;
	int i = ind;

	while (i - (i & -i) >= 0) {
		soma += BITree[i];
		i -= (i & -i);
	}

	return soma;
}

// ----------------------------------

int main() {

    return 0;
}
