//In The Name of Allah
//Mon 17/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

ll n;
ll a[M],tmp[M],ans[M],dep[M];
pii par[M];
vector<ll> child[M];
vector<ll> vertseg;
vector<ll> depseg;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

ll dfs(ll v){
	dep[v] = dep[par[v].F] + par[v].S;
	depseg.pb(dep[v]);
	vertseg.pb(v);
	tmp[vertseg[lower_bound(depseg.begin(),depseg.end(),dep[v]-a[v])-depseg.begin()]]--;
	ll des = 0;
	for(ll ch : child[v]){
		des += dfs(ch);
	}
	depseg.pop_back();
	vertseg.pop_back();
	ans[v] = des;
	des+=tmp[v]+1;
	return des;
}

void Solution(){
	cin >> n;
	vertseg.reserve(n+1);
	depseg.reserve(n+1);
	forar(i,n){
		cin >> a[i];
	}
	forar(i,n-1){
		ll p,w;
		cin >> p >> w;
		child[--p].pb(i+1);
		par[i+1]={p,w};
	}
	dfs(0);
	forar(i,n){
		cout << ans[i] << " ";
	}
	cout << endl;
}
