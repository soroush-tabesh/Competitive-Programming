//In The Name of Allah
//Thu 3/3/97
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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

bool npr[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

ll check(ll a,ll b){
	ll t = 0;
	while(!npr[abs(t*t + a*t + b)])
		++t;
	return t;
}

inline void Solution(){
	for(ll i = 2;i < M;i++){
		if(npr[i])
			continue;
		for(ll j = 2*i;j < M;j += i)
			npr[j] = true;
	}
	ll mx = 0,val = 0;
	fori(a,-999,1000){
		fori(b,-1000,1001){
			ll t = check(a,b);
			if(t > mx){
				mx = t;
				val = a*b;
			}
		}
	}
	cout << val << endl;
}
