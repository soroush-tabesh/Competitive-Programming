//In The Name of Allah
//Thu 31/2/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

ull n,h;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

bool check(ull base){
	ull bc = base;
	ll ext = min(base,h)-1;
	base += ext;
	bool is = (base % 2 == 0);
	base = (base + 1)/2;
	ll vol = base*base;
	vol -= (ext*(ext+1))/2;
	if(is)
		vol += base;
	return vol >= n;
}

inline void Solution(){
	cin >> n >> h;
	ull l = 1,r = ull(2e9);
	while(r-l){
		ull mid = (r+l)/2;
		if(check(mid)){
			r = mid;
		}else{
			l = mid+1;
		}
	}
	cout << l << endl;
}
