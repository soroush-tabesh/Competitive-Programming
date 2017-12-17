//In The Name of Allah
//Sun 26/9/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("hayfeast.in","r",stdin),freopen("hayfeast.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define clamp(a,b,i) max(min(i,b),a)
#define infint 1000*1000*1000

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

ll n,m;
pll data[M];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	forar(i,n){
		cin >> data[i].F >> data[i].S;
	}
	int l = 0,r = 0;
	ll sum = 0;
	ll ans = 2LL*infint;
	multiset<ll,greater<int> > mx;
	while(r < n){
		while(r < n && sum < m){
			sum += data[r].F;
			mx.insert(data[r].S);
			r++;
		}
		if(sum < m)
			break;
		while(l<r && sum >= m){
			ans = min(ans,*mx.begin());
			sum -= data[l].F;
			mx.erase(mx.find(data[l].S));
			l++;
		}
	}
	cout << ans << endl;
}
