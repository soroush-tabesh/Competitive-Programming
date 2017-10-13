//In The Name of Allah
//Tue 28/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 5000+5;

void Solution();

int n,m;
vector<int> adjin[M],adjout[M];
int arrival;
int pre2vert[M],vert2pre[M];
int parent[M];
int tpar[M];
int qmin[M];
int idom[M],sdom[M];
vector<int> prsdom[M];
set<int> ans;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void dfs(int v){
	arrival++;
	pre2vert[arrival] = tpar[v] = qmin[v] = sdom[v] = idom[v] = v;
	vert2pre[v] = arrival;
	for(int neib : adjout[v]){
		if(vert2pre[neib])
			continue;
		parent[neib] = v;
		dfs(neib);
	}
}

int query(int v,bool deep = false){
	if(v == tpar[v])
		return (deep?-1:v);
	assert(v >= 1 && v <= n);
	int res = query(tpar[v],true);
	if(res < 0)
		return v;
	if(vert2pre[sdom[qmin[tpar[v]]]] < vert2pre[sdom[qmin[v]]])
		qmin[v] = qmin[tpar[v]];
	tpar[v] = res;
	return (deep?res:qmin[v]);
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b;
		cin >> a >> b; // 1-indexed
		adjout[a].pb(b);
		adjin[b].pb(a);
	}
	dfs(1);
	for(int i = arrival;i > 0;i--){
		int cur = pre2vert[i];
		for(int neib : adjin[cur]){
			int q = query(neib);
			if(vert2pre[sdom[q]] < vert2pre[sdom[cur]]){
				sdom[cur] = sdom[q];
			}
		}
		if(i!=1){
			prsdom[sdom[cur]].pb(cur);
		}
		for(int ch : prsdom[cur]){
			int res = query(ch);
			if(sdom[res] == sdom[ch]){
				idom[ch] = sdom[ch];
			}else{
				idom[ch] = res;
			}
		}
		if(i!=1){
			tpar[cur] = parent[cur];
		}
	}
	for(int i = 2;i <= arrival;i++){
		int cur = pre2vert[i];
		if(idom[cur] != sdom[cur]){
			idom[cur] = idom[idom[cur]];
		}
		ans.insert(idom[cur]);
	}
	cout << ans.size() << endl;
	for(int x : ans){
		cout << x << " ";
	}
}

