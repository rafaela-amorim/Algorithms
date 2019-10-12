#include <bits/stdc++.h>

using namespace std;

#define lado 2
#define m 1000000007    // 10^9 + 7
#define vet vector<vector<int> >

vet id = {{1, 0}, 
          {0, 1}};


// -------------------------------------

void show(vet matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

// -------------------------------------

vet init(int lines, int col) {
    vet matrix;

    for (int i = 0; i < lines; i++) {
        matrix.push_back({});

        for (int j = 0; j < col; j++) {
            matrix[i].push_back(0);
        }
    }

    return matrix;
}

// -------------------------------------

// multiplica 2 matrizes 2x2 (resulta em outra 2x2)
vet mult_matrix(vet m1, vet m2, int col) {

    // inicia r com as linhas de m1 e as colunas de m2
    vet r = init(m1.size(), m2[0].size());

    // k deve ir de 0 até (num de colunas de m1 == num de lados de m2)
    for (int k = 0; k < col; k++) {

        // i vai de 0 até num de linhas de m1
        for (int i = 0; i < m1.size(); i++) {
            
            // j vai de 0 até num de colunas de m2
            for (int j = 0; j < m2[0].size(); j++) {
                r[i][j] += ((m1[i][k] % m) * (m2[k][j] % m)) % m;
            }
        }
    } 

    return r;
}

// -------------------------------------

vet fast_exp_matrix(vet matrix, int p) {
    if (p == 0)
        return id;
    
    vet ret = fast_exp_matrix(matrix, p / 2);
    int col = ret.size();

    if (p % 2 == 0) {
        return mult_matrix(ret, ret, col);
    } else {
        vet aux = mult_matrix(ret, ret, col);
        return mult_matrix(matrix, aux, col);
    }
}


// -------------------------------------

int main() {
    int n = 4;
    int col = 2;    // colunas de m1 -- linhas de m2

    cout << "Termo da seq de Fibonacci: ";
    cin >> n;

    vet seq = {{1, 0}};
    vet matrix = {{1, 1},
                  {1, 0}};
    vet aux;

    aux = fast_exp_matrix(matrix, n - 2);
    vet answer = mult_matrix(seq, aux, col);

    // show(answer);
    cout << answer[0][0] << "\n";   
   
    return 0;
}