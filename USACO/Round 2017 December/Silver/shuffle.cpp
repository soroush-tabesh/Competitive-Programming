//In The Name of Allah
//Sat 25/9/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("shuffle.in","r",stdin),freopen("shuffle.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define clamp(a,b,i) max(min(i,b),a)
#define infint 1000*1000*1000

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n,pmt[M],ans,tme[M];
bool mark[M],par[M];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void dfs(int v,int t){
	if(mark[v])
		return;
	mark[v] = 1;
	par[v] = 1;
	tme[v] = t;
	if(par[pmt[v]]){
		ans += t+1-tme[pmt[v]];
	}else{
		dfs(pmt[v],t+1);
	}
	par[v] = 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		int a;
		cin >> a;
		pmt[i] = a-1;
	}
	forar(i,n){
		dfs(i,0);
	}
	cout << ans << endl;
}
