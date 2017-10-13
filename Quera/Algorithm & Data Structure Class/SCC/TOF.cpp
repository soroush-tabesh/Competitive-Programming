//In The Name of Allah
//Sat 18/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 5e3+5;

void Solution();

int n,m;
vector<int> adjin[M],adjout[M],cadjin[M],cadjout[M];
int comp[M],compcnt,compsize[M];
int markdfs[M],markdfscnt;
vector<int> dfs_stack;
int ans;
int dist[M][M];
int sc[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void dfs(int v){
	markdfs[v] = markdfscnt;
	for(int neib : adjout[v]){
		if(!markdfs[neib]){
			dfs(neib);
		}
	}
	dfs_stack.pb(v);
}

void revdfs(int v,int orig){
	comp[v] = compcnt;
	compsize[comp[v]]++;
	for(int neib : adjin[v]){
		if(markdfs[neib] == orig && !comp[neib]){
			revdfs(neib,orig);
		}
	}
}

void tarjan(){
	fori(i,1,n+1){
		if(!markdfs[i]){
			markdfscnt++;
			dfs(i);
		}
	}
	while(!dfs_stack.empty()){
		int cur = dfs_stack.back();
		dfs_stack.pop_back();
		if(!comp[cur]){
			compcnt++;
			revdfs(cur,markdfs[cur]);
		}
	}
	fori(i,1,n+1){
		for(int neib : adjin[i]){
			if(comp[neib] == comp[i])
				continue;
			cadjin[comp[i]].pb(comp[neib]);
			cadjout[comp[neib]].pb(comp[i]);
		}
	}
}

void getSC(){
	vector<int> topro;int head = 0;
	topro.reserve(n+1);
	fori(i,1,n+1){
		topro.resize(0);
		head = 0;
		topro.pb(i);
		while(head < topro.size()){
			int cur = topro[head];
			head++;
			for(int neib : adjout[cur]){
				if(dist[i][neib] || neib == i)
					continue;
				dist[i][neib] = dist[i][cur]+1;
				topro.pb(neib);
			}
		}
	}
	forar(i,M){
		sc[i] = M;
	}
	fori(i,1,n+1){
		fori(j,i+1,n+1){
			if(comp[i] == comp[j])
				sc[comp[i]] = min(sc[comp[i]],dist[i][j] + dist[j][i]);
		}
	}
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adjin[b].pb(a);
		adjout[a].pb(b);
	}
	tarjan();
	getSC();
	fori(i,1,n+1){
		if(!compsize[i])
			break;
		if(cadjout[i].size() != 0 || compsize[i] == 1){
			ans += compsize[i];
		}else{
			ans += sc[i]*999+1;
			ans += compsize[i]-sc[i];
		}
	}
	cout << ans << endl;
}

 