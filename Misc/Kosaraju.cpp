//In The Name of Allah
//Tue 1/4/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(ll i = a; i < b;i++)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n,m;
vector<int> adjin[M];
vector<int> adjout[M];
vector<int> proc;
bool mark1[M];
int compid[M],compcnt;
int compsize[M];

int32_t main()
{
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

void makeList(int v){
	if(mark1[v])
		return;
	mark1[v] = 1;
	for(auto neib : adjout[v])
		makeList(neib);
	proc.pb(v);
}

void getComp(int v){
	if(compid[v])
		return;
	compid[v] = compcnt;
	++compsize[compcnt];
	for(auto neib : adjin[v])
		getComp(neib);
}

inline void Solution(){
	// A complete kosaraju's scc example
	cin >> n >> m;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adjout[a].pb(b);
		adjin[b].pb(a);
	}
	forar(i,n){
		makeList(i);
		ans[i] = mod;
	}
	reverse(all(proc));
	for(auto x : proc){
		if(!compid[x]){
			++compcnt;
			getComp(x);
		}
	}
}
