#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

vector<int> nums;

// ------------------------------

/*
    This binary_search alogrithm returns the number in an
    ordered array which is greater or equals to the 
    value in the parameter.
*/

int binary_search(int tam, int value) {
    int begin = 0, end = tam - 1;
    int middle, number;

    while (begin <= end) {
        middle = (begin + end) / 2;

        if (nums[middle] > value) {
            end = middle - 1;
        } else if (nums[middle] < value) {
            begin = middle + 1;
        } else {
            number = value;
        }

    }

    if (begin > end) {
        number = nums[middle]; 
    }

    return number;
}

// ------------------------------

int main() {
    return 0;
}