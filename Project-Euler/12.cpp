//In The Name of Allah
//Tue 18/2/97
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

void factorize(ll n,map<ll,ll> &prfc){
	for(ll i = 2;i*i <= n;i++){
		while(n%i == 0){
			n/=i;
			prfc[i]++;
		}
	}
	if(n>1)
		prfc[n]++;
}

inline void Solution(){
	fori(i,3,1000000){
		map<ll,ll> prfc;
		factorize(i,prfc);
		factorize(i+1,prfc);
		ll res = 1;
		for(auto it : prfc){
			res *= it.S+(it.F == 2 ? 0 : 1);
		}
		if(res > 500){
			cout << i*(i+1)/2 << endl;
			break;
		}
	}
}
