//In The Name of Allah
//Tue 7/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

int n;
int data[M];
vector<int> adj[M];
int beauty[M];
bool mark[M];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void dfs(int v,int curgcd,int del){
	mark[v] = 1;
	if(del != -1){
		int sita = __gcd(curgcd,data[v]);
		int sitb = __gcd(curgcd,data[del]);
		if(sita >= sitb){
			curgcd = sita;
		}else{
			curgcd = sitb;
			del = v;
		}
	}else{
		if(curgcd == 0){
			curgcd = data[v];
		}else{
			del = v;
		}
	}
	beauty[v] = curgcd;
	for(int neib : adj[v]){
		if(!mark[neib]){
			dfs(neib,curgcd,del);
		}
	}
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
	}
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	dfs(0,0,-1);
	forar(i,n){
		cout << beauty[i] << " ";
	}
	cout << endl;
}

