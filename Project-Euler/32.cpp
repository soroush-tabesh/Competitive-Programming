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

inline void ard(int* arr,ll x){
	while(x>0){
		arr[x%10]++;
		x /= 10;
	}
}

inline void Solution(){
	set<int> prds;
	int cn[10];
	forar(i,10000){
		fori(j,i,10000){
			memset(cn,0,sizeof cn);
			ard(cn,i),ard(cn,j),ard(cn,i*j);
			bool is = cn[0] == 0;
			int cnt = 0;
			fori(t,1,10){
				cnt += cn[t];
				if(cn[t] != 1)
					is = false;
			}
			if(is)
				prds.insert(i*j);
			if(cnt > 9)
				break;
		}
	}
	ll ans = 0;
	for(auto x : prds){
		ans += x;
	}
	cout << ans << endl;
}
