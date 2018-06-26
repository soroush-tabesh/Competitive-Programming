//In The Name of Allah
//Tue 3/4/97
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

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

struct dsu{
	int par[M],n,sz[M];
	dsu(int tn){
		n = tn;
		forar(i,n){
			par[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		return (x == par[x] ? x : par[x] = find(par[x]));
	}
	bool join(int a,int b){
		a = find(a);
		b = find(b);
		if(a == b)
			return false;
		if(sz[a] < sz[b])
			swap(a,b);
		sz[a] += sz[b];
		par[b] = a;
		return true;
	}
};

inline void Solution(){
	dsu cmp(10);
	Log(cmp.find(2));
	cmp.join(1,2);
	cmp.join(0,3);
	cmp.join(0,2);
	Log(cmp.find(1));
	Log(cmp.find(3));
}
