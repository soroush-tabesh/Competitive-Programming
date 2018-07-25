//In The Name of Allah
//Fri 29/4/97
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

const ll mod = 13907,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	while(true)Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

int n,ans;
int lst[100];

void solve(int x){
	if(x == n){
		fori(i,1,n+1){
			lst[i] = x;
			solve(x-1);
			lst[i] = 0;
		}
	}else if(x){
		int mx = 0;
		fori(i,1,n+1){
			int dist = n+1;
			forar(j,n+2){
				if(lst[j])
					dist = min(dist,abs(j-i));
			}
			mx = max(mx,dist);
		}
		fori(i,1,n+1){
			int dist = n+1;
			forar(j,n+2){
				if(lst[j])
					dist = min(dist,abs(j-i));
			}
			if(dist == mx){
				lst[i] = x;
				solve(x-1);
				lst[i] = 0;
			}
		}
	}else{
		++ans;
	}
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v *= v;
	if(exp%2)
		v *= base;
	return v%mod;
}

inline void Solution(){
	cin >> n;
	lst[0] = lst[n+1] = 1;
	solve(n);
	cout << ans << endl;
	cout << ppow(ans,1397) << endl;
}
