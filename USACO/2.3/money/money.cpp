/*
ID: soroosh4
LANG: C++11
TASK: money
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("money.in","r",stdin),freopen("money.out","w",stdout)
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

const ll mod = 1e9+7;
const int M = 100*1000+5;

void Solution();

ll v,n;
ll coins[26];
ll dp[10*1000+5][26];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

ll solve(ll mon , ll lim){
	if(mon < 0 || lim <= 0)
		return 0;
	if(dp[mon][lim] != -1)
		return dp[mon][lim];
	if(mon == 0)
		return 1;
	ll r = 0;
	forar(i,lim){
		r += solve(mon-coins[i],i+1);
	}
	dp[mon][lim] = r;
	return r;
}

void Solution(){
	cin >> v >> n;
	forar(i,v){
		cin >> coins[i];
	}
	sort(coins,coins+v);
	memset(dp,-1,sizeof dp);
	cout << solve(n,v) << endl;
}
