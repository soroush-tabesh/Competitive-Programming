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

int n,t1,t1val,t2,t2val;
vector<int> adj[M];
int mark[M];
bool trn[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void dfsA(int v,int d){
	mark[v] = 1;
	if(d > t1val){
		t1 = v;
		t1val = d;
	}
	for(int neib: adj[v]){
		if(mark[neib] != 1){
			dfsA(neib,d+1);
		}
	}
}

void dfsB(int v,int d){
	mark[v] = 2;
	if(d > t2val){
		t2 = v;
		t2val = d;
	}
	for(int neib: adj[v]){
		if(mark[neib] != 2){
			dfsB(neib,d+1);
		}
	}
}

bool dfsC(int v, int tar){
	mark[v] = 3;
	if(v == tar)
		return trn[v] = true;
	for(int neib: adj[v]){
		if(mark[neib]!=3){
			trn[v] |= dfsC(neib,tar);
		}
	}
	return trn[v];
}

void simpsolve(int v){
	mark[v] = 4;
	cout << v + 1 << " ";
	for(int neib : adj[v]){
		if(mark[neib] == 4)
			continue;
		simpsolve(neib);
		cout << v + 1 << " ";
	}
}

void solve(int v){
	mark[v] = 4;
	cout << v + 1 << " ";
	if(v == t2)
		return;
	int r = v;
	for(int neib : adj[v]){
		if(mark[neib] == 4)
			continue;
		if(trn[neib]){
			r = neib;
		}else{
			simpsolve(neib);
			cout << v + 1 << " ";
		}
		
	}
	solve(r);
}

void Solution(){
	cin >> n;
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		--a;--b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfsA(0,0);
	dfsB(t1,0);
	dfsC(t1,t2);
	cout << (2*(n-1) - t2val) << endl;
	solve(t1);
}
