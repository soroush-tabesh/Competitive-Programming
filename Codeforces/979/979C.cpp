//In The Name of Allah
//Mon 24/2/97
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

const ll mod = 1e9+7,M = 3e5+100;

void Solution();

ll n,x,y;
vector<ll> adj[M];
ll dp[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

bool dfs(ll v,ll par){
    ll k = 0;
    dp[v]=1;
	bool is = false;
    for(ll neib : adj[v]){
		if(neib == par)
			continue;
        if(dfs(neib,v)){
            k = dp[neib];
			is = true;
        }
        dp[v] += dp[neib];
    }
    if(v==x){
        cout << n*(n-1) - (dp[x]-k)*(dp[y]) << endl;
        return true;
    }
    if(v == y)
        return true;
	return is;
}

inline void Solution(){
	cin >> n >> x >> y;
	--x;--y;
	forar(i,n-1){
		ll a,b;
		cin >> a >> b;
		--a;--b;
		adj[b].pb(a);
		adj[a].pb(b);
	}
    dfs(x,x);
}
