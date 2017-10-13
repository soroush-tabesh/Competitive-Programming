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

int n,k;
bool mark[205][205];
int path[205];
int adj[205][205];
set<int> ans;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void dfs(int v, int depth){
	mark[v][depth] = 1;
	if(depth == k){
		ans.insert(v);
		return;
	}
	forar(neib,n){
		if(!mark[neib][depth+1] && adj[v][neib] == path[depth]){
			dfs(neib,depth+1);
		}
	}
}

void Solution(){
	cin >> n;
	forar(i,n){
		forar(j,n){
			cin >> adj[i][j];
		}
	}
	cin >> k;
	forar(i,k){
		cin >> path[i];
	}
	dfs(0,0);
	cout << ans.size() << endl;
	for(int x : ans){
		cout << (x + 1) << " ";
	}
	cout << endl;
}

