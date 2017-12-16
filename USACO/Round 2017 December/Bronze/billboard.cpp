//In The Name of Allah
//Sat 25/9/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("billboard.in","r",stdin),freopen("billboard.out","w",stdout)
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

struct Rect{
	int l,r,u,d;
};
Rect rects[4];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	forar(i,3){
		cin >> rects[i].l >> rects[i].d >> rects[i].r >> rects[i].u;
	}
	int ans = 0;
	forar(i,2){
		ans += (rects[i].r-rects[i].l)*(rects[i].u - rects[i].d);
		int l,r,u,d;
		l = max(rects[i].l,rects[2].l);
		d = max(rects[i].d,rects[2].d);
		r = min(rects[i].r,rects[2].r);
		u = min(rects[i].u,rects[2].u);
		ans -= clamp(0,infint,r-l)*clamp(0,infint,u-d);
	}
	cout << ans << endl;
}
