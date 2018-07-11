//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int,pair<int,int>>
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define reqd(i,s,e,d) for(int i=s;i<e;i+=d)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 100000 + 100,mod = 1000 * 1000 * 1000 + 7;
using namespace std;

vector<pii> inp;
vector<int> adj[MX];
bool mark[MX];
int match[MX];

bool dfs(int v){
	mark[v]=1;
	for(int i=0;i<adj[v].size();i++)
	{
		int u=adj[v][i];
		if(match[u]==-1 || (!mark[match[u]] && dfs(match[u])))
		{
			match[u]=v;
			return 1;
		}
	}
	return 0;
}

bool check(pii a,pii b){///returns true if a is in b
	if(a.F>=b.F){
		return 0;
	}
	int x=(a.S.F-b.S.F)*(a.S.F-b.S.F)+(a.S.S-b.S.S)*(a.S.S-b.S.S);
	if(x<-b.F*a.F*2LL+a.F*a.F+b.F*b.F){
		return 1;
	}
	return 0;
}

int32_t main(){
	Init
	int n,m;
	cin>>n>>m;
	int ans=0;
	req(i,0,m){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
	}
	fill(match,match+n,-1);
	req(i,0,n){
		fill(mark,mark+n,0);
		dfs(i);
	}
	req(i,0,n){
		if(match[i]==-1){
			ans++;
		}
	}
	cout<<ans<<endl;
}