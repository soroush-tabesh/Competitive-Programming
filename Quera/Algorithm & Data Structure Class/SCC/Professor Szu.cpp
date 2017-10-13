//In The Name of Allah
//Sat 18/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("szu.in","r",stdin),freopen("szu.out","w",stdout)
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

const ll mod = 1e9+7,M = 1e6+5;

void Solution();

int n,m;
pii edges[M];
int edgecache[M],dp[M];
bool comp[M],markdfs[M];
int compcnt;
stack<int> revdfs_stack;
vector<int> ans;
const int inf = 36501;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

bool cmp(pii a,pii b){
	return a.F < b.F;
}

void make_cache(){
	int last = 0;
	forar(i,m){
		if(edges[i].F == last)
			continue;
		last = edges[i].F;
		edgecache[last] = i;
	}
}

void inverse_adjacency(){
	forar(i,m){
		swap(edges[i].F,edges[i].S);
	}
	sort(edges,edges+m,cmp);
}

void dfs(int v){
	markdfs[v] = 1;
	for(int i = edgecache[v];edges[i].F == v;i++){
		int neib = edges[i].S;
		if(!markdfs[neib])
			dfs(neib);
	}
	revdfs_stack.push(v);
}

void revdfs(int v,bool isb){
	comp[v] = 1;
	for(int i = edgecache[v];edges[i].F == v;i++){
		int neib = edges[i].S;
		if(neib == v){
			isb = true;
			continue;
		}
		if(markdfs[neib] && !comp[neib]){
			isb = true;
			revdfs(neib,isb);
		}
	}
	if(isb){
		dp[v] = inf;
	}
}

void tarjan(){
	// forward dfs marking
	dp[n] = 1;
	dfs(n);
	inverse_adjacency();
	make_cache();
	// reverse dfs
	while(!revdfs_stack.empty()){
		int cur = revdfs_stack.top();
		revdfs_stack.pop();
		if(comp[cur]){
			continue;
		}
		compcnt++;
		revdfs(cur,false);
	}
}

int findans(int v){
	if(dp[v])
		return dp[v];
	for(int i = edgecache[v];edges[i].F == v;i++){
		int neib = edges[i].S;
		if(markdfs[neib]){
			dp[v] += findans(neib);
			if(dp[v] > inf)
				dp[v] = inf;
		}
	}
	return dp[v];
}

void Solution(){
	// everything is 1-indexed
	cin >> n >> m;
	n++;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		edges[i] = {a,b};
	}
	inverse_adjacency();
	make_cache();
	tarjan();
	
	int mx = 0;
	fori(i,1,n){
		if(markdfs[i]){
			mx = max(mx,findans(i));
		}
	}
	fori(i,1,n){
		if(dp[i] == mx){
			ans.pb(i);
		}
	}
	if(mx <= 36500)
		cout << mx << endl;
	else
		cout << "zawsze" << endl;
	cout << ans.size() << endl;
	for(int x : ans){
		cout << x << " ";
	}
	cout << endl;
}

 