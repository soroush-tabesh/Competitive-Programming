//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("shopping.in","r",stdin),freopen("shopping.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;
const int M = 100*1000+5;

void Solution();

ll data[100*1000+5];
ll ans = 1e18;
ll temp;
ll n,x,y;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void rec(ll depth,ll curgcd){
	if(depth == n){
		if(curgcd != 1)
			ans = min(ans,temp);
		return;
	}
	ll t;
	// keep it
	temp += 0;
	t = __gcd(curgcd,data[depth]);
	if(t != 1 && temp < ans)
		rec(depth+1,t);
	temp -= 0;
	
	// remove it
	temp += x;
	t = curgcd;
	if(t != 1 && temp < ans)
		rec(depth+1,t);
	temp -= x;
	
	// increase it
	temp += y;
	t = __gcd(curgcd,data[depth]+1);
	if(t != 1 && temp < ans)
		rec(depth+1,t);
	temp -= y;
}

void Solution(){
	cin >> n >> x >> y;
	forar(i,n){
		cin >> data[i];
	}
	rec(0,0);
	cout << ans << endl;
}
