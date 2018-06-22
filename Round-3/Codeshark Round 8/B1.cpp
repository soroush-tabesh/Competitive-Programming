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

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int32_t main()
{
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll ppow(ll base,ll exp){
	if(!exp)
		return 1;
	ll v = ppow(base,exp/2);
	v = (v*v)%mod;
	if(exp%2)
		v*=base;
	return v%mod;
}

ll _x;
bool getbit(ll pos){
	return (_x & (1<<pos) ? 1 : 0);
}

bool getedge(ll a,ll b){
	return getbit(5*a+b);
}

ll mark[20],mcn ,scn,ans;

void dfs(ll v){
	if(mark[v] == mcn)
		return;
	scn++;
	mark[v] = mcn;
	forar(i,5){
		if(getedge(v,i))
			dfs(i);
	}
}

void rdfs(ll v){
	if(mark[v] == mcn)
		return;
	scn++;
	mark[v] = mcn;
	forar(i,5){
		if(getedge(i,v))
			rdfs(i);
	}
}

inline void Solution(){
	ll k = ppow(2,25);
	forar(t,k){
		_x=t;
		bool is = true;
		forar(i,5){
			if(getedge(i,i))
				is = false;
		}
		if(!is)
			continue;
		ll cn = 0;
		forar(i,25){
			cn += int(getbit(i));
		}
		if(cn > 11)
			continue;

		mcn++;
		scn = 0;
		dfs(0);
		ll t1 = scn;

		mcn++;
		scn = 0;
		rdfs(0);
		ll t2 = scn;

		if(t1 == 5 && t2 == 5)
			ans++;
	}
	cout << ans%10789 << endl;
}
