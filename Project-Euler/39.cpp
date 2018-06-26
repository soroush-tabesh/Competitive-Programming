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

ll ans[M];

inline ll isqrt(ll x){
	ll l=0,r=x;
	while(r-l>0){
		ll mid = (r+l+1)/2;
		if(mid*mid <= x)
			l = mid;
		else
			r = mid-1;
	}
	return l;
}

inline void Solution(){
	fori(i,1,501){
		fori(j,i,501){
			ll k = isqrt(i*i+j*j);
			if(i*i+j*j != k*k)
				continue;
			++ans[i+j+k];
		}
	}
	int mx = 0;
	fori(i,3,1001){
		if(ans[i] > ans[mx])
			mx=i;
	}
	cout << mx << endl;
}
