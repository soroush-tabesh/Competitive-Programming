//In The Name of Allah
//Sun 23/2/97
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

inline ll getlen(ll i){
	if(i == 1000)
		return 11;
	const int numlen[20] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
	const int ntmlen[10] = {0,0,6,6,5,5,5,7,6,6};
	int ans = 0;
	if(i>=100){
		ans += numlen[i/100] + 7;
		if(i%100)
			ans += 3;
	}
	if(i%100){
		if(i%100 >= 20){
			ans += ntmlen[(i/10)%10];
			if(i%10)
				ans += numlen[i%10];
		}else{
			ans += numlen[i%100];
		}
	}
	return ans;
}

inline void Solution(){
	ll ans = 0;
	fori(i,1,1000+1){
		ans += getlen(i);
	}
	cout << ans << endl;
}
