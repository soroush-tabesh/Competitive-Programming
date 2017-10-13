//In The Name of Allah
//Sat 28/5/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
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

void Solution();

int n,m,cnt,ans;
vector<pii> adj[1005];
bool mark[1005];
int dist[1005];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b,c;
		cin >> a >> b >> c;
		adj[--a].pb({--b,c});
		adj[b].pb({a,c});
	}
	forar(i,n){
		dist[i] = -1;
	}
	mark[0] = 1;
	cnt++;
	for(pii neib : adj[0]){
		dist[neib.F] = neib.S;
	}
	while(cnt < n){
		int vertmin,valmin=-1;
		forar(i,n){
			if(mark[i] || dist[i] == -1)
				continue;
			if(valmin == -1){
				vertmin = i;
				valmin = dist[i];
			}else if(dist[i] < valmin){
				valmin = dist[i];
				vertmin = i;
			}
		}
		cnt++;
		mark[vertmin] = 1;
		ans += valmin;
		for(pii neib : adj[vertmin]){
			if(dist[neib.F] == -1){
				dist[neib.F] = neib.S;
			}else{
				dist[neib.F] = min(dist[neib.F],neib.S);
			}
		}
	}
	cout << ans;
}

