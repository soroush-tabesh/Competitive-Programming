//In The Name of Allah
//Tue 14/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int16_t i = 0; i < n;i++)
#define fori(i,a,b) for(int16_t i = a; i < b;i++)
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

const ll mod = 1e9+7,M = 2050;

void Solution();

int16_t n;

vector<int16_t> adjout[M];
vector<int16_t> adjin[M];

int16_t markdfs[M], markdfscnt;
vector<int16_t> dfs_stack;

int16_t comp[M],compcnt;
bool badcomp[M];

vector<int16_t> ans;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void dfs(int16_t v){
	markdfs[v] = markdfscnt;
	for(int16_t neib : adjout[v]){
		if(!markdfs[neib])
			dfs(neib);
	}
	dfs_stack.pb(v);
}

void revdfs(int16_t v,int16_t origfmark){
	comp[v] = compcnt;
	for(int16_t neib : adjin[v]){
		if(markdfs[neib] == origfmark && !comp[neib])
			revdfs(neib,origfmark);
	}
}

void tarjan(){
	// forward dfs marking
	fori(i,1,n+1){
		if(!markdfs[i]){
			markdfscnt++;
			dfs(i);
		}
	}
	// reverse dfs
	for(short i = dfs_stack.size()-1;i>=0;i--){
		if(comp[dfs_stack[i]])
			continue;
		compcnt++;
		revdfs(dfs_stack[i],markdfs[dfs_stack[i]]);
	}
	// find components adjacency
	fori(i,1,n+1){
		for(int16_t neib : adjin[i]){
			if(comp[neib]!=comp[i]){
				badcomp[comp[i]] = 1;
			}
		}
	}
	// find ans
	fori(i,1,n+1){
		if(!badcomp[comp[i]]){
			ans.pb(i);
		}
	}
}

void init(){
	dfs_stack.reserve(n+1);
	ans.reserve(n+1);
	forar(i,n+1){
		adjin[i].reserve(n/2+1);
		adjout[i].reserve(n/2+1);
	}
}

void Solution(){
	cin >> n;
	init();
	forar(i,n){
		int16_t a;
		cin >> a;
		while(a != 0){
			adjout[i+1].pb(a);
			adjin[a].pb(i+1);
			cin >> a;
		}
	}
	tarjan();
	bool is = true;
	forar(i,ans.size()-1){
		if(comp[ans[i]] != comp[ans[i+1]])
			is = false;
	}
	if(is){
		sort(ans.begin(),ans.end());
		forar(i,ans.size()){
			cout << ans[i] << " ";
		}
	}
	cout << 0;
}

 