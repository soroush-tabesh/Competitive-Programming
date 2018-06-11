//In The Name of Allah
//Tue 16/3/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fori(i,a,b) for(ll i = a; i < b;i++)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

ll mylife,enlife,myattack,enattack;
ll coin,lifemul,attmul;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

bool getverdict(ll a1,ll l1,ll a2,ll l2){
	ll t1 = (l1+a2-1)/a2;
	ll t2 = (l2+a1-1)/a1;
	return t1 >= t2;
}

inline void Solution(){
	cin >> myattack >> mylife >> enattack >> enlife;
	cin >> coin >> attmul >> lifemul;
	bool is = false;
	forar(onat,coin+1){
		is |= getverdict(myattack+onat*attmul,mylife+(coin-onat)*lifemul,enattack,enlife);
	}
	cout << int(is) << endl;
}
