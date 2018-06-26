//In The Name of Allah
//Tue 5/4/97
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

inline bool ispan(ll x){
	int cn[10] = {0};
	while(x){
		cn[x%10] ++;
		x/=10;
	}
	bool is = cn[0]==0;
	fori(i,1,10){
		is &= cn[i] == 1;
	}
	return is;
}

inline ll getsz(ll x){
	ll res = 1;
	while(x){
		res*=10;
		x/=10;
	}
	return res;
}

inline void Solution(){
	ll mx = 0;
	fori(i,1,1e5){
		ll res = i;
		fori(tt,2,10){
			res = res*getsz(tt*i) + tt*i;
			if(res > 1e9)
				break;
			if(ispan(res))
				mx = max(mx,res);
		}
	}
	cout << mx << endl;
}
