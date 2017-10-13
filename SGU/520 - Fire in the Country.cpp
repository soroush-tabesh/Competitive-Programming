//In The Name of Allah
//Mon 23/5/96
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

int n,m;
vector<int> adj[1000+5];
bool mark[1000+5];
int layer[1000+5];
vector<int> topro;int head,tail;
bool state[1000+5]; // 0:lose - 1:win

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void bfs(int v){
	mark[v] = 1;
	topro.pb(v);
	tail = 1;
	while(head < tail){
		int cur = topro[head];
		head++;
		for(int neib : adj[cur]){
			if(mark[neib])
				continue;
			layer[neib] = layer[cur] + 1;
			mark[neib] = 1;
			topro.pb(neib);
			tail++;
		}
	}
}

void bfsrev(){
	for(int i = topro.size()-1;i>=0;i--){
		for(int neib : adj[topro[i]]){
			if(layer[neib] > layer[topro[i]]){
				state[topro[i]] |= !state[neib];
			}
		}
	}
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	
	bfs(0);
	bfsrev();
	
	if(state[0]){
		cout << "Vladimir" << endl;
	}else{
		cout << "Nikolay" << endl;
	}
}

