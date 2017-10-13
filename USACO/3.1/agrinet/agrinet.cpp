/*
ID: soroosh4
LANG: C++11
TASK: agrinet
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("agrinet.in","r",stdin),freopen("agrinet.out","w",stdout)
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

ll n,ans,cnt;
const ll inf = 1e9;
ll adj[105][105];
ll dist[105];
bool mark[105];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		forar(j,n){
			cin >> adj[i][j];
		}
	}
	// Prim's MST
	// init
	memset(dist,inf,sizeof dist);
	dist[0] = 0;
	forar(j,n){
		if(adj[0][j]){
			dist[j] = adj[0][j];
		}
	}
	cnt++;
	mark[0] = 1;
	// algortithm
	while(cnt < n){
		// find next node
		ll newnode = -1;
		forar(i,n){
			if(!mark[i]){
				if(newnode == -1 || dist[newnode] > dist[i])
					newnode = i;
			}
		}
		// process this node
		mark[newnode] = 1;
		ans += dist[newnode];
		cnt++;
		forar(j,n){
			dist[j] = min(dist[j],adj[newnode][j]);
		}
	}
	cout << ans << endl;
}
