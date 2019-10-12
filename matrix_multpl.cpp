#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
#define m 1000000007

void mult_matrix(int lm1, int lm2, int col, int m1[][], int m2[][], int r[][]) {

    for (int k = 0; k < col; k++) {
        
        for (int i = 0; i < lm1; i++) {
            for (int j = 0; j < lm2; j++) {
                r[i][j] += ( ((m1[i][k] % m) * (m2[k][j] % m)) % m )
            }
        }
    }

}

int main() {
    return 0;
}