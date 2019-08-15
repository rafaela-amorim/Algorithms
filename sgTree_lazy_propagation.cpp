#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

int sgtree[MAX * 4];
int lazy[MAX * 4];
int nums[MAX];

// ---------------------------------

/*
    Lazy propagation is used when you need to update
    an entire range of an array.
*/

/*
    Segment Tree with lazy propagation which keeps the sum 
    of all number in range of an array.
*/

void build(int id, int left, int right) {
    if (left == right) {
        sgtree[id] = nums[left];
        lazy[id] = 0;
    } else {
        int middle = (left + right) / 2;

        build(id*2, left, middle);
        build(id*2 + 1, middle + 1, right);

        sgtree[id] = sgtree[id*2] + sgtree[id*2 + 1];
    }
}

int query()

// ---------------------------------

int main() {
    return 0;
}