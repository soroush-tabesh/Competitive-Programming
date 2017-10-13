// In the name of God
#include <bits/stdc++.h>

using namespace std;

#define front first
#define back second
#define pb push_back
#define pf push_front
#define inf 100*1000*1000

int dp[1000*100];
bool mark[1000*100];

int solve(int n,int m){
	
	if(n<=0)
		return inf;
	if(n==m)
		return 0;
	if(dp[n] != 0)
		return dp[n];
		
	mark[n] = 1;
	int ans = 0, tempa = inf, tempb = inf;
	if(n < m){
		tempb = solve(2 * n, m);
	}
	if(mark[n-1] == 0 && n != 1){
		tempa = solve(n - 1, m);
	}
	ans = min(tempa, tempb) + 1;
	dp[n] = ans;
	return ans;
}

int main()
{
	int n,m;
	cin >> n >> m;
	mark[n] = 1;
	cout << solve(n,m) << endl;
}
