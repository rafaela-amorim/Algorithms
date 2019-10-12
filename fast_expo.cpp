#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define m 1000000007

ll fast_expo(int base, int pot) {
    if (pot == 0)
        return 1;

    ll ret = fast_expo(base, pot / 2);

    if (pot % 2 == 0) 
        return ((ret % m) * (ret % m)) % m;
    else
        return ((base % m) * (ret % m) * (ret % m)) % m;
}

int main() {
    return 0;
}