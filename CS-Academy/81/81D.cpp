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

ll n,dp[M],pref[M];
bool vote[M],islarge[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n;
	int frs = mod;
	forar(i,n){
		char a,b;
		cin >> a >> b;
		vote[i] = a == 'A';
		islarge[i] = b == 'L';
		if(islarge[i])
			frs = min(frs,i);
	}
	pref[0] = vote[i]*2-1;
	fori(i,1,n){
		pref[i] = pref[i-1]+vote[i]*2-1;
	}
	int ans = 0;
	bool is = false;
	int last = 0;
	forar(i,n){
		if(islarge[i+1] || i+1 >= n){
			ans += int()
			last = pref[i];
		}
	}
}
