/*
ID: soroosh4
LANG: C++11
TASK: nocows
*/
//In The Name of God

// Yadegari : Jer Khordam Sar in!!!!!!!

#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("nocows.in","r",stdin),freopen("nocows.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mod = 9901;
const int M = 100*1000+5;

void Solution();

int dp[200+5][100+5]; // n , k

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int solve(int n ,int k){ // solves on a single tree
	if(n < 0 || k < 0){
		return 0;
	}
	if(dp[n][k] != -1){
		return dp[n][k];
	}
	if(n%2 == 0){
		dp[n][k] = 0;
		return 0;
	}
	
	int r = 0;
	fori(i,2*k-3,n){
		int t = 0;
		forar(j,k-1){
			t += solve(i,k-1)*solve(n-i-1,j);
			t %= mod;
		}
		t *= 2;
		t += solve(i,k-1)*solve(n-i-1,k-1);
		r += t;
		r %= mod;
	}
	
	dp[n][k] = r;
	return r;
}

void init(int n,int k){
	dp[1][1] = 1;
	fori(i,2,n+1){
		fori(j,2,k+1){
			dp[i][j] = -1;
		}
	}
}

void Solution(){
	int n,k;
	cin >> n >> k;
	init(n,k);
	if(n%2 == 0){
		cout << 0 << endl;
		return;
	}
	cout << solve(n,k) << endl;
}
