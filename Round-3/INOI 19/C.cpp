//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll delta = 10337;

void Solution();

ll dp[100][100];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

ll combine(int n, int r){
	if(r == n || r == 0 || n == 1)
		return 1;
	if(dp[n][r])
		return dp[n][r];
	int v = combine(n-1,r) + combine(n-1,r-1);
	v %= delta;
	dp[n][r] = v;
	return v;
}

void Solution(){
	cout << combine(66,33) << endl;
}