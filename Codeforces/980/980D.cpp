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

ll n;
ll inp[5100];
map<ll,ll> facts[5100];
ll sfacts[5100];
ll ans[5100];

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

ll fac2s(map<ll,ll>&prfc){
	ll res = 1;
	for(auto it : prfc){
		if(it.S % 2)
			res *= it.F;
	}
	return res+476;
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> inp[i];
		factorize(abs(inp[i]),facts[i]);
		sfacts[i] = fac2s(facts[i]);
	}
	unordered_set<ll> posfact;
	unordered_set<ll> negfact;
	posfact.reserve(95863);
	negfact.reserve(95863);
	forar(s,n){
		posfact.clear();
		negfact.clear();
		fori(e,s,n){
			if(inp[e]>0){
				posfact.insert(sfacts[e]);
			}else{
				negfact.insert(sfacts[e]);
			}
			ans[posfact.size() + negfact.size()]++;
		}
	}
	forar(i,n){
		cout << ans[i+1] << " ";
	}
	cout << endl;
}






