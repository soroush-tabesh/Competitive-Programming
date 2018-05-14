//In The Name of Allah
//Wed 11/11/96
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
ll arr[M];

int main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> arr[i];
	}
	sort(arr,arr+n,greater<ll>());
	ll ans = 0;
	ll cnt = 0;
	ll last = 0;
	forar(i,n){
		if(arr[i] >= 0){
			ans += arr[i];
			cnt++;
			last = i;
		}
	}
	if(cnt%2){
		if(last < n-1){
			ans = max(ans-arr[last],ans+arr[last+1]);
		}else{
			ans -= arr[last];
		}
	}
	cout << ans << endl;
}
