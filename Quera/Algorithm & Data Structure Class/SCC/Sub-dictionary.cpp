//In The Name of Allah
//Tue 14/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
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

const ll mod = 1e9+7,M = 120;

void Solution();

int n;

map<string,int> str2ind;
string ind2str[M];
int indicer = 1;

set<int> adjout[M];
set<int> adjin[M];

set<int> cadjout[M];
set<int> cadjin[M];

int markdfs[M], markdfscnt;
vector<int> dfs_stack;

int comp[M],compcnt;
int compsize[M];

bool presence[M];
bool markpres[M];

vector<string> ans;
string line;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

int getnum(string s){
	int t = str2ind[s];
	if(t == 0){
		t = str2ind[s] = indicer++;
		ind2str[t] = s;
	}
	return t;
}

int getn(){
	cin >> n;
	string line;
	getline(cin,line);
	return n;
}

void init(){
	str2ind.clear();
	indicer = 1;
	ans.clear();
	markdfscnt = 0;
	compcnt = 0;
	dfs_stack.clear();
	forar(i,M){
		ind2str[i].clear();
		adjout[i].clear();
		adjin[i].clear();
		cadjout[i].clear();
		cadjin[i].clear();
		markdfs[i] = 0;
		comp[i] = 0;
		compsize[i] = 0;
		presence[i] = 0;
		markpres[i] = 0;
	}
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

bool presdfs(int v){
	if(markpres[v])
		return presence[v];
	markpres[v] = 1;
	bool is = (compsize[v] > 1) || (cadjin[v].size() == 0);
	for(int neib : cadjout[v]){
		is |= presdfs(neib);
	}
	return (presence[v] = is);
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
	while(!dfs_stack.empty()){
		int cur;
		while(!dfs_stack.empty() && comp[cur = dfs_stack.back()])
			dfs_stack.pop_back();
		if(!dfs_stack.empty()){
			compcnt++;
			revdfs(cur,markdfs[cur]);
		}
	}
	// find components adjacency
	fori(i,1,n+1){
		for(int neib : adjout[i]){
			cadjout[comp[i]].insert(comp[neib]);
		}
		for(int neib : adjin[i]){
			cadjin[comp[i]].insert(comp[neib]);
		}
	}
	// find ans
	fori(i,1,n+1){
		presdfs(i);
	}
	
}

void Solution(){
	while(getn() != 0){
		init();
		forar(i,n){
			getline(cin,line);
			stringstream ss(line);
			string token;
			getline(ss,token,' ');
			int curvert = getnum(token);
			while(getline(ss,token,' ')){
				int neib = getnum(token);
				adjout[neib].insert(curvert);
				adjin[curvert].insert(neib);
			}
		}
		tarjan();
		fori(i,1,n+1){
			if(presence[comp[i]]){
				ans.pb(ind2str[i]);
			}
		}
		sort(ans.begin(),ans.end());
		cout << ans.size() << endl;
		forar(i,ans.size()){
			if(i)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}

 