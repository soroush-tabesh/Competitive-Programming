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

inline void Solution(){
	int lst[10] = {0,0,0,2,3,5,7,11,13,17};
	int num[10] = {1,0,2,3,4,5,6,7,8,9};
	ll ans = 0;
	do{
		int a = num[0]*100+num[1]*10+num[2];
		bool is = true;
		fori(i,3,10){
			a -= num[i-3]*100;
			a*=10;
			a += num[i];
			is &= (a%lst[i] == 0);
		}
		if(is){
			ll res = 0;
			forar(i,10){
				res = res*10+num[i];
			}
			ans += res;
		}
	}while(next_permutation(num,num+10));
	cout << ans << endl;
}
