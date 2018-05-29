//In The Name of Allah
//Tue 8/3/97
#pragma GCC optimize "-Ofast"
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

int n,m,k,s;
vector<int> adj[M];
int good[M];
int dist[110][M]; // nearest i-th good type to town j
bool mark[110][M];
vector<int> ans[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n >> m >> k >> s;
	forar(i,n){
		cin >> good[i];
		--good[i];
	}
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	forar(i,k){
		forar(j,n){
			dist[i][j] = mod;
		}
	}
	forar(gt,k){
		vector<int> qu;int head = 0;// qu for checking child
		forar(i,n){
			if(good[i] == gt){
				qu.pb(i);
				mark[gt][i] = 1;
				dist[gt][i] = 0;
			}
		}
		while(head < qu.size()){
			int cur = qu[head++];
			for(int neib : adj[cur]){
				if(mark[gt][neib])
					continue;
				mark[gt][neib] = 1;
				dist[gt][neib] = dist[gt][cur]+1;
				qu.pb(neib);
			}
		}
	}
	forar(i,k){
		forar(j,n){
			ans[j].pb(dist[i][j]);
		}
	}
	forar(i,n){
		int sum = 0;
		sort(ans[i].begin(),ans[i].end());
		forar(t,s){
			sum += ans[i][t];
		}
		cout << sum << " ";
	}
}
