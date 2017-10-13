/*
ID: soroosh4
LANG: C++11
TASK: concom
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("concom.in","r",stdin),freopen("concom.out","w",stdout)
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

int n;
int adj[101][101];
bool mark[101];
int prc[101];
set<pii>ans;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void dfs(int v,int org){
	if(mark[v])
		return;
	mark[v] = true;
	forar(i,101){
		prc[i] += adj[v][i];
		if(prc[i] > 50){
			if(org != i)
				ans.insert({org,i});
			dfs(i,org);
		}
	}
}

void Solution(){
	cin >> n;
	forar(i,n){
		int a,b;
		cin >> a >> b;
		cin >> adj[a-1][b-1];
	}
	forar(i,101){
		memset(mark,0,sizeof mark);
		memset(prc,0,sizeof prc);
		dfs(i,i);
	}
	for(pii p : ans){
		cout << p.F+1 << ' ' << p.S+1 << endl;
	}
}
