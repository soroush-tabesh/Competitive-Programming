/*
ID: soroosh4
LANG: C++11
TASK: subset
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("subset.in","r",stdin),freopen("subset.out","w",stdout)
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

ll dp[500][500];
ll n,sum;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

ll solve(ll suma,ll sumb,ll k){
	if(suma < 0 || sumb < 0)
		return 0;
	if(suma == 0 || sumb == 0){
		dp[suma][sumb] = 1;
		return 1;
	}
	if(dp[suma][sumb] != 0)
		return dp[suma][sumb];
	dp[suma][sumb] = solve(suma-k,sumb,k-1) + solve(suma,sumb-k,k-1);
	return dp[suma][sumb];
}

void Solution(){
	cin >> n;
	if(n%4 != 0 && n%4 != 3){
		cout << 0 << endl;
		return;
	}
	sum = n*(n+1)/4;
	//Log(sum);
	cout << solve(sum,sum,n)/2 << endl;
}
