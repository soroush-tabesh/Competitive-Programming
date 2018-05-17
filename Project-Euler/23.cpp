//In The Name of Allah
//Thu 27/2/97
#include <bits/stdc++.h>
#pragma GCC optimize "-Ofast"

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

bool mark[60000];
ll divsum[60000];
vector<ll> abunds;

inline void Solution(){
	ll lim = 28124;
	
	fori(i,1,lim){
		for(ll j = i*2;j<=lim;j+=i){
			divsum[j]+=i;
		}
	}
	fori(i,1,lim){
		if(divsum[i] > i)
			abunds.pb(i);
	}
	forar(i,abunds.size()){
		forar(j,i+1){
			mark[abunds[i]+abunds[j]] = 1;
		}
	}
	ll ans = 0;
	fori(i,1,lim){
		if(!mark[i])
			ans += i;
	}
	cout << ans << endl;
}
