//In The Name of Allah
//Sun 9/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

ll n,l,r,ans;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> l >> r;
	ll k = 0;
	while(n > 0){
		k *= 2;
		k += n%2;
		n /= 2;
	}
	n = k;
	while(l<=r){
		ll t = l;
		ll res = 0;
		while(t%2==0){
			t/=2;
			res++;
		}
		ans += ((n >> res)%2);
		l++;
	}
	cout << ans << endl;
}
