//In The Name of Allah
//Mon 8/5/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(int i = a; i < b;++i)
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

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

int n,m,q,pz=-1;
map<int,vector<int> > rws,clms;

inline void Solution(){
	cin >> n >> m >> q;
	int tmp = 1;
	forar(i,q){
		int r,c;
		cin >> r >> c;
		rws[r].pb(c);
		clms[c].pb(r);
		tmp = c;
		if(clms[c].size()>1)
			pz = c;
	}
	if(pz == -1)
		pz = tmp;
	clms[pz].pb(0);
	int res = 0;
	fori(currow,1,n+1){
		auto& tl = rws[currow];
		bool is = false;
		for(auto x : tl){
			if(clms[x].size()>1)
				is = true;
		}
		if(!is){
			++res;
			clms[pz].pb(currow);
			rws[currow].pb(pz);
		}
	}
	fori(j,1,m+1){
		if(clms[j].size() == 0)
			++res;
	}
	cout << res << endl;
}
