//In The Name of Allah
//Wed 16/8/96
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

const ll mod = 1e9+7,M = 1e4+50;

void Solution();

ll n;
pll bl[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

ll getsum(ll x){
	ll res = 0;
	forar(i,n){
		res += abs(bl[i].F-bl[x].F)*bl[i].S;
	}
	return res;
}

ll solve(ll lo, ll hi){
	if(hi - lo <= 10){
		ll res = mod;
		fori(i,lo,hi+1){
			res = min(res,getsum(i));
		}
		return res;
	}
	ll mid1 = (lo*2+hi)/3;
	ll mid2 = (lo+hi*2)/3;
	if(getsum(mid1) <= getsum(mid2)){
		return solve(lo,mid2);
	}else{
		return solve(mid1,hi);
	}
}

void Solution(){
	int t;
	cin >> t;
	while(t--){
		// O(n)
		/*
		cin >> n;
		ll sumc=0,sumcr=0;
		forar(i,n){
			cin >> bl[i].F;
		}
		forar(i,n){
			cin >> bl[i].S;
			sumc += bl[i].S;
		}
		sort(bl,bl+n,less<pll>());
		sumcr = sumc-bl[0].S;
		ll ansri = 0,ansrval = sumcr;
		fori(i,1,n){
			sumcr -= bl[i].S;
			if(max(sumcr,sumc-sumcr-bl[i].S) < ansrval){
				ansrval = max(sumcr,sumc-sumcr-bl[i].S);
				ansri = i;
			}
		}
		ll ans = 0;
		forar(i,n){
			ans += abs(bl[i].F-bl[ansri].F)*bl[i].S;
		}
		cout << ans << endl;
		*/
		
		// O(nlgn)
		cin >> n;
		forar(i,n){
			cin >> bl[i].F;
		}
		forar(i,n){
			cin >> bl[i].S;
		}
		sort(bl,bl+n,less<pll>());
		cout << solve(0,n-1) << endl;
	}
}
