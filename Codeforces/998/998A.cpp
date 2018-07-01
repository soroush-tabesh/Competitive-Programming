//In The Name of Allah
//Tue 10/4/97
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

inline void Solution(){
	int n;
	cin >> n;
	int dt[10] = {0};
	int sum = 0;
	forar(i,n){
		cin >> dt[i];
		sum += dt[i];
	}
	fori(i,1,(1<<n)-1){
		int res = 0;
		int k = 0;
		forar(j,n){
			if(i & (1<<j)){
				res += dt[j];
				++k;
			}
		}
		if(res*2 != sum){
			cout << k << endl;
			forar(j,n){
				if(i & (1<<j)){
					cout << j+1 << " ";
				}
			}
			return;
		}
	}
	cout << -1 << endl;
}
