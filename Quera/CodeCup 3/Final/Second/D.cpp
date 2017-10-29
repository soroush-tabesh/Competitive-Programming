//In The Name of Allah
//Thu 7/8/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

ll n,k;
ll par[M];
vector<ll> ch[M];
ll dp[M];
ll p[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll res = ppow(base,exp/2);
	res *= res;
	res %= mod;
	if(exp%2)
		res *= base;
	return res%mod;
}

ll dfs(ll v){
	ll res = dp[ch[v].size()+1];
	for(ll neib : ch[v]){
		res *= dfs(neib);
		res %= mod;
	}
	return res%mod;
}

void Solution(){
	cin >> n >> k;
	ll cr = 0,tr = 0;
	forar(i,n){
		char c;
		cin >> c;
		if(c=='('){
			par[++tr] = cr;
			ch[cr].pb(tr);
			cr=tr;
		}else{
			cr=par[cr];
		}
	}
	p[1] = dp[1] = 1;
	p[2] = dp[2] = k-1;
	fori(i,3,n+10){
		p[i] = p[i-1] * (k-1);
		p[i] %= mod;
		dp[i] = p[i] - dp[i-1] + mod;
		dp[i] %= mod;
	}
	ll ans = (k*ppow(k-1,ch[0].size()-1))%mod;
	for(ll neib : ch[0]){
		ans *= dfs(neib);
		ans %= mod;
	}
	cout << ans << endl;
}
