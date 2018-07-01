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

ll n,x,y;

inline void Solution(){
	cin >> n >> x >> y;
	ll cn[2] = {0};
	char lst;
	cin >> lst;
	int state = lst-'0';
	++cn[state];
	forar(i,n-1){
		cin >> lst;
		if(lst-'0' != state){
			state = 1-state;
			++cn[state];
		}
	}
	cout << min(min(cn[0]*y,cn[1]*y+y) , min(cn[0]*y + (cn[0]-1)*(x-y) , cn[1]*y+(cn[1]-1)*(x-y)+y));
}
