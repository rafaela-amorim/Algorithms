#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

int prefix[MAX];

// ------------------------------

void kmp(string word) {
    int i = 0;
    int tam = word.size();

    for (int j = 1; j < tam; j++) {
        while (i > 0 && word[i] != word[j])
            i = prefix[i - 1];

        if (word[i] == word[j]) {
            prefix[j] = i + 1;
            i++;
        } else
            prefix[j] = 0;
    }    
}

void show(int tam) {
    for (int i = 0; i < tam; i++) {
        cout << prefix[i];
    }
    cout << "\n";
}

// ------------------------------

int main() {
    string str1, str2, word;
    cin >> str1 >> str2;

    word = str1 + '#' + str2;

    int tam = word.size();

    kmp(word);
    show(tam);

    return 0;
}