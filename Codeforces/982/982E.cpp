//In The Name of Allah
//Thu 27/2/97
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

ll gcdExtended(ll a, ll b, ll *x, ll *y){
	if (a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return gcd;
}

inline void Solution(){
	ll n,m,x,y,vx,vy;
	cin >> n >> m >> x >> y >> vx >> vy;
	if(vx == 0){
		if(x == 0 || x == n){
			cout << x << " " << (vy == 1 ? m : 0) << endl;
		}else{
			cout << -1 << endl;
		}
		return;
	}
	if(vy == 0){
		if(y == 0 || y == m){
			cout << (vx == 1 ? n : 0) << " " << y << endl;
		}else{
			cout << -1 << endl;
		}
		return;
	}
	
	if(vx == -1)
		x = n-x;
	if(vy == -1)
		y = m-y;
	
	ll k = y-x;
	ll gc = __gcd(m,n);
	if(k % gc){
		cout << -1 << endl;
		return;
	}
	ll cx,cy;
	gcdExtended(m,n,&cy,&cx); // m*cy + n*cx = gc
	cy *= k/gc;
	cx *= -k/gc; // m*cy - n*cx = gc  ---> m*cy = n*cx + k

	if(cx <= 0 || cy < 0){
		ll d = min(cx/(m/gc),cy/(n/gc));
		--d;
		cx -= d*(m/gc);
		cy -= d*(n/gc);
	}
	
	if(cx > m/gc && cy > n/gc){
		ll d = min(cx/(m/gc),cy/(n/gc));
		cx -= d*(m/gc);
		cy -= d*(n/gc);
	}
	
	cout << ((cx%2==0)^(vx==-1) ? 0 : n) << " " << ((cy%2==0)^(vy==-1) ? 0 : m) << endl;
}
