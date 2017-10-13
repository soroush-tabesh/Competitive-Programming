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
vector<int> adj[300];
bool mark[300];
bool color[300];
int black;
vector<int> ans;
bool is;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void dfs(int v,bool col){
	mark[v] = 1;
	color[v] = col;
	if(col){
		black++;
		ans.pb(v);
	}
	for(int neib : adj[v]){
		if(mark[neib]){
			if(col == color[neib])
				is = true;
		}else{
			dfs(neib,!col);
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
	forar(i,n){
		if(!mark[i])
			dfs(i,0);
	}
	if(is){
		cout << "no" << endl;
	}else{
		cout << "yes" << endl;
		cout << black << endl;
		for(int x : ans){
			cout << x+1 << " ";
		}
	}
}

