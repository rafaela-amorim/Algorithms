#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
#define sqrtsize (int) sqrt(MAX)

int nums[MAX];
int SQRT[sqrtsize];
int bucket_size;

// ------------------------

void build(int tam) {
	int index = -1;

	bucket_size = sqrt(tam);

	for (int i = 0; i < tam; i++) {
		if (i % bucket_size == 0)
			index++;
		
		SQRT[index] += nums[i];
	}
	
}

void update(int ind, int val) {
	int index = ind / bucket_size;
	SQRT[index] += (val - nums[ind]);
	nums[ind] = val;
}

int query(int left, int right) {
	int sum = 0;

	while (left < right && left % bucket_size != 0) 
		sum += nums[left++];
	
	while (left + bucket_size <= right) {
		sum += SQRT[left / bucket_size];
		left += bucket_size;
	}

	while (left <= right) 
		sum += nums[left]++;
	
	return sum;
}

// ------------------------

int main() {

	return 0;
}
