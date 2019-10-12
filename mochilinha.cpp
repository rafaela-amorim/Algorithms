#include <bits/stdc++.h>

#define mInf -10000000

using namespace std;

vector<pair<int,int>> ob;
int dp[10000][10000];
int quantidade;

int solve(int peso, int index){
	if(peso < 0) return mInf;
	else if(index == quantidade) return 0;
	if(dp[peso][index]) return dp[peso][index];
	int ret = max(solve(peso - ob[index].first, index +1) + ob[index].second,
						solve(peso, index +1));
	dp[peso][index] = ret;
	return ret;
}

int main(){
	cin >> quantidade;
	for(int i = 0; i < quantidade; i++){
		int peso, valor;
		cin >> peso >> valor;
		ob.push_back({peso,valor});
	}
	int ma;
	cin >> ma;
	cout << "a maior soma possivel eh: " << solve(ma,0) << endl;
}
