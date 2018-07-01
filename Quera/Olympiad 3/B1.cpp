//In The Name of Allah
//Tue 8/4/97
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

int n;
set<int> mta,mtb;

inline void Solution(){
	cin >> n;
	forar(i,n){
		int a,b;
		cin >> a >> b;
		mta.insert(a);
		mtb.insert(b);
	}
	ll ans = 0;
	forar(i,n){
		auto ta = mta.begin();
		auto tb = mtb.begin();
		if(*ta == *tb){

		}else{
			ans += abs(*ta-*tb);
			mta.erase(ta);
			mtb.erase(tb);
		}
	}
	cout << ans << endl;
}
