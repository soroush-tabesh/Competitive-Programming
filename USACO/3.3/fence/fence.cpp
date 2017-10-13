//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: fence
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("fence.in","r",stdin),freopen("fence.out","w",stdout)
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

multiset<int> adj[501];
int f;
vector<int> ans;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void eulerpath(int v){
	while(!adj[v].empty()){
		int neib = *(adj[v].begin()); // smallest number to process
		adj[v].erase(adj[v].begin());
		adj[neib].erase(adj[neib].find(v));
		eulerpath(neib);
	}
	ans.pb(v+1);
}

void Solution(){
	cin >> f;
	forar(i,f){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	bool is = false;
	int start = 2000;
	forar(i,500){
		if(adj[i].size() % 2 == 1){
			is = true;
			start = min(start,i);
		}
	}
	if(!is)
		start = 0;
	eulerpath(start);
	forar(i,ans.size()){
		cout << ans[ans.size()-i-1] << endl;
	}
}
