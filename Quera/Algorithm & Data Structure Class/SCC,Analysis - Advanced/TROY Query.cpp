// In The Name of Allah
// Tue 23/6/96
#include <bits/stdc++.h>

#define fori(i,a,b) for(int i = a;i < b;i++)
#define F first
#define S second
#define pb emplace_back
#define Init ios_base::sync_with_stdio(false),cin.tie(0)

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int M = 4e5+100;

int q,n,tme;
ll inp[M][4];
map<ll,int> conv[2];
vector<pii> adj[M];
int comp[M],compcnt;

void dfs(int v){
	if(comp[v])
		return;
	comp[v] = compcnt;
	for(pii neib : adj[v])
		if(neib.S <= tme)
			dfs(neib.F);
}

bool check2sat(){
	fill(comp,comp+n*2+5,0);
	compcnt=0;
	fori(i,1,2*n+1){
		if(!comp[i]){
			compcnt++;
			dfs(i);
		}
	}
	bool res = true;
	fori(i,1,n+1){
		if(comp[i] == comp[i+n])
			res = false;
	}
	return res;
}

int32_t main(){
	Init;
	cin >> q;
	fori(i,0,q){
		fori(j,0,2){
			cin >> inp[i][j];
			if(!conv[j][inp[i][j]])
				conv[j][inp[i][j]] = ++n; // vertices are 1-based
			inp[i][j] = conv[j][inp[i][j]];
		}
		fori(j,2,4){
			cin >> inp[i][j];
		}
	}
	fori(i,0,q){ // make graph
		if(inp[i][2] == inp[i][3]){
			adj[inp[i][0]].pb(inp[i][1],i+1);
			adj[inp[i][1]].pb(inp[i][0],i+1);
			adj[inp[i][0]+n].pb(inp[i][1]+n,i+1);
			adj[inp[i][1]+n].pb(inp[i][0]+n,i+1);
		}else{
			adj[inp[i][0]].pb(inp[i][1]+n,i+1);
			adj[inp[i][1]+n].pb(inp[i][0],i+1);
			adj[inp[i][1]].pb(inp[i][0]+n,i+1);
			adj[inp[i][0]+n].pb(inp[i][1],i+1);
		}
	}
	int low=0,hi=q+1;// binary search on first cycle appearance time
	while(low < hi){
		int mid = (low+hi)/2;
		tme = mid;
		if(check2sat()){
			low = mid+1;
		}else{
			hi = mid;
		}
	}
	fori(i,1,low){
		cout << "Yes" << endl;
	}
	fori(i,low,q+1){
		cout << "No" << endl;
	}
	return 0;
}