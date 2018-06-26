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

const ll mod = 1e9+7,M = 2e6+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

bool sv[M];

inline void Solution(){
	sv[1] = sv[0] = 1;
	fori(i,2,M){
		if(sv[i])
			continue;
		for (int j = 2*i; j < M; j+=i){
			sv[j] = 1;
		}
	}
	int ans = 0;
	fori(i,2,1000000){
		int ip = i;
		int mul = 1;
		int c = 0;
		while(ip){
			mul *= 10;
			ip/=10;
			c++;
		}
		bool is = true;
		forar(t,c){
			is &= !sv[i];
			int tm = i%10;
			i /= 10;
			i += tm*mul/10;
		}
		if(is)
			ans ++;
	}
	cout << ans << endl;

}
