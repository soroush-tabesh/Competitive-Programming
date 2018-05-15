//In The Name of Allah
//Tue 25/2/97
#pragma GCC optimize "-Ofast"
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

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	int q;
	cin >> q;
	while(q--){
		ll base,nom ,den;
		cin >> nom >> den >> base;
		ll g = __gcd(nom,den);
		den/=g;
		g = __gcd(base,den);
		while(g != 1){
			while(den%g==0)
				den/=g;
			g = __gcd(base,den);
		}
		if(den == 1){
			cout << "Finite" << endl;
		}else{
			cout << "Infinite" << endl;
		}
	}
}
