//In The Name of Allah
//Thr 16/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("grass.in","r",stdin),freopen("grass.out","w",stdout)
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

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

int n,m;
set<int> adjin[M],adjout[M];
set<int> cadjin[M],cadjout[M];
int comp[M],compcnt,compsize[M];
int markdfs[M], markdfscnt;
vector<int> dfs_stack;
int dpout[M],dpin[M];
vector<int> toproA;int headA;
vector<int> toproB;int headB;
int markcntA[M],markcnttarA[M];
bool marktempA[M];
int markcntB[M],markcnttarB[M];
bool marktempB[M];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void dfs(int v){
	markdfs[v] = markdfscnt;
	for(int neib : adjout[v]){
		if(!markdfs[neib])
			dfs(neib);
	}
	dfs_stack.pb(v);
}

void revdfs(int v,int origfmark){
	comp[v] = compcnt;
	compsize[compcnt]++;
	for(int neib : adjin[v]){
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
	for(int i = dfs_stack.size()-1;i>=0;i--){
		if(comp[dfs_stack[i]])
			continue;
		compcnt++;
		revdfs(dfs_stack[i],markdfs[dfs_stack[i]]);
	}
	// find components adjacency
	fori(i,1,n+1){
		for(int neib : adjout[i]){
			if(comp[i] != comp[neib])
				cadjout[comp[i]].insert(comp[neib]);
		}
		for(int neib : adjin[i]){
			if(comp[i] != comp[neib])
				cadjin[comp[i]].insert(comp[neib]);
		}
	}
}

void calcdpout_dfs(int v){
	marktempA[v] = 1;
	for(int neib : cadjout[v]){
		markcnttarA[neib]++;
		if(!marktempA[neib])
			calcdpout_dfs(neib);
	}
}

void calcdpout(){
	calcdpout_dfs(comp[1]);
	toproA.reserve(n+1);
	toproA.pb(comp[1]);
	while(headA < toproA.size()){
		int cur = toproA[headA];
		headA++;
		for(int neib : cadjin[cur]){
			if(marktempA[neib])
				dpout[cur] = max(dpout[cur],dpout[neib]+compsize[cur]);
		}
		for(int neib : cadjout[cur]){
			markcntA[neib]++;
			if(markcntA[neib] == markcnttarA[neib]){
				toproA.pb(neib);
			}
		}
	}
}

void calcdpin_dfs(int v){
	marktempB[v] = 1;
	for(int neib : cadjin[v]){
		markcnttarB[neib]++;
		if(!marktempB[neib])
			calcdpin_dfs(neib);
	}
}

void calcdpin(){
	calcdpin_dfs(comp[1]);
	toproB.reserve(n+1);
	toproB.pb(comp[1]);
	headB = 0;
	while(headB < toproB.size()){
		int cur = toproB[headB];
		headB++;
		for(int neib : cadjout[cur]){
			if(marktempB[neib])
				dpin[cur] = max(dpin[cur],dpin[neib]+compsize[cur]);
		}
		for(int neib : cadjin[cur]){
			markcntB[neib]++;
			if(markcntB[neib] == markcnttarB[neib]){
				toproB.pb(neib);
			}
		}
	}
}

void Solution(){
	// everything is 1-indexed
	cin >> n >> m;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adjout[a].insert(b);
		adjin[b].insert(a);
	}
	tarjan();
	calcdpout();
	calcdpin();
	int ans = 0;
	for(int c : toproA){
		for(int neib : cadjin[c]){
			if(!marktempB[neib])
				continue;
			ans = max(ans,dpout[c]+dpin[neib]);
		}
	}
	cout << ans+compsize[comp[1]] << endl;
}

 