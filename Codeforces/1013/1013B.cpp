//In The Name of Allah
//Mon 8/5/97
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

int n,arr[M],x;
int mark[M];
bool mark2[M];

inline void Solution(){
	cin >> n >> x;
	forar(i,n){
		cin >> arr[i];
		if(mark[arr[i]]){
			cout << 0 << endl;
			return;
		}else{
			mark[arr[i]] = i+1;
		}
	}
	forar(i,n){
		if(mark[arr[i]&x] && mark[arr[i]&x] != i+1){
			cout << 1 << endl;
			return;
		}
	}
	forar(i,n){
		if(mark2[arr[i]&x]){
			cout << 2 << endl;
			return;
		}else{
			mark2[arr[i]&x] = 1;
		}
	}
	cout << -1 << endl;
}
