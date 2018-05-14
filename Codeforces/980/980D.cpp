//In The Name of Allah
//Tue 18/2/97
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

ll n;
ll inp[5100];
ll sfacts[5100];
ll ans[5100];
bool exs[5100];
map<ll,int> ord; int cn= 0;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> inp[i];
		
		if(!inp[i])
			continue;
		
		ll t = abs(inp[i]);
		sfacts[i] = (inp[i]>=0?1:-1);
		
		for(ll j = 2;j*j <= t;j++){
			int c = 0;
			while(t%j == 0){
				t/=j;
				c++;
			}
			if(c%2)
				sfacts[i] *= j;
		}
		if(t>1)
			sfacts[i] *= t;
		
		if(!ord[sfacts[i]])
			ord[sfacts[i]] = ++cn;
		sfacts[i] = ord[sfacts[i]];
	}
	forar(s,n){
		forar(i,5100){
			exs[i]=0;
		}
		
		int res = 0;
		fori(e,s,n){
			if(!exs[sfacts[e]] && sfacts[e]){
				res++;
				exs[sfacts[e]] = 1;
			}
			ans[max(res,1)]++;
		}
	}

	forar(i,n){
		cout << ans[i+1] << " ";
	}
	cout << endl;
}
