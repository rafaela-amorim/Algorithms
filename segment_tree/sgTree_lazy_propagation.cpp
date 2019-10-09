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

/* Since the operation being used in this segment tree is the sum
    The neutral element is 0, because any number plus zero is the number
*/
void propaga(int id, int left, int right) {
    if (lazy[id] != 0) {
        /*  In the sum seg tree, the upper nodes keep the values of the TOTAL SUM 
            in a specific range in the array.
            That's why we sum the current range (right - left) + 1 and multiply it
            by the value we want which is the one kept in the lazy tree
        */
        sgtree[id] += lazy[id] * ((right - left) + 1);  

        if (left != right) {    // if not leaf
            lazy[id*2] = lazy[id];
            lazy[id*2 + 1] = lazy[id];  // the actual propagation
        }
    }
}

int query(int id, int left, int right, int x, int y) {
    if (x <= left && right <= y) {
        return sgtree[id];
    } else if (right < x || left > y) {
        return 0;   // neutral element
    } else {
        int middle = (left + right) / 2;

        return query(id*2,left,middle,x,y) + query(id*2 + 1,middle+1,right,x,y);    // returns the sum
    }
}

/* The update happens in range */
void update(int id, int left, int right, int x, int y, int value) {
    if (x <= left && right <= y) {
        lazy[id] = value;           // update the lazy tree before propagating the "cache"
        propaga(id, left, right);
    } else if (right < x || left > y) {
        propaga(id, left, right);
    } else {
        propaga(id, left, right);

        int middle = (left + right) / 2;

        update(id*2, left, middle, x, y, value);
        update(id*2 + 1, middle + 1, right, x, y, value);
    }
}

// ---------------------------------

int main() {
    return 0;
}