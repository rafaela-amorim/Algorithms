#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

int z[MAX];

void zfunc(string s) {
	int l = 0, r = 0;

	for(int i = 1; i < s.size(); i++){
		z[i] = max(0, min(z[i-l], r-i+1));
	
    	while(i+z[i] < s.size() && s[z[i]] == s[i+z[i]]){
			l = i; r = i+z[i]; z[i]++;
		}
	}
	
    z[0] = s.size();
}

int main(){
	cin >> s;
	zfunc();
    
	return 0;
}