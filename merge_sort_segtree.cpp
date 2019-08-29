#include <bits/stdc++.h>

using namespace std;

#define MAX 100005
#define vi vector<int>

vi sgtree[MAX * 4];
int nums[MAX];

// --------------------------------

vi merge(vi l1, vi l2) {
	int i = 0, j = 0;
	vi ans;

	while (i < l1.size() && j < l2.size()) {
		if (l1[i] < l2[j]) 
			ans.push_back(l1[i]);	
		else 
			ans.push_back(l2[j]);

		i++;
		j++;
	}

	while (i < l1.size()) 
		ans.push_back(l1[i]);
	
	while (j < l2.size())
		ans.push_back(l2[j]);

	return ans;
}

// --------------------------------

void build(int id, int left, int right) {
	if (left == right) {
		sgtree[id] = nums[left];
	} else {
		int middle = (left + right) / 2;

		build(id*2, left, middle);
		build(id*2+1, middle+1, right);

		sgtree[id] = merge(sgtree[id*2], sgtree[id*2+1]);	
	}
}

void update(int id, int left, int right, int val) {
		
}

// --------------------------------

int main() {
	return 0;
}
