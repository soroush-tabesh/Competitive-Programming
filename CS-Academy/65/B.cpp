//In The Name of Allah
//Wed 27/10/96
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

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n,ans;
set<int> adj[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[--a].insert(--b);
		adj[b].insert(a);
	}
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		--a;--b;
		ans += (adj[a].find(b) != adj[a].end());
	}
	cout << ans << endl;
}
