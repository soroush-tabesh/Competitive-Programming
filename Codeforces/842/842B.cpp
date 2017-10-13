//In The Name of Allah
//Tue 7/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e6+5;

void Solution();

struct Sus{
	ld x,y,r;
};
typedef struct Sus Sus;

ld r,d;
ll n,ans;
Sus sus[M];
const ll eps = 1e-3;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> r >> d >> n;
	forar(i,n){
		cin >> sus[i].x >> sus[i].y >> sus[i].r;
		ld mind,maxd,cend;
		cend = sqrt(sus[i].x*sus[i].x + sus[i].y*sus[i].y);
		mind = cend - sus[i].r;
		maxd = cend + sus[i].r;
		if((maxd<=r || abs(maxd-r)<=eps)&& (mind >= r-d || abs(mind-r+d)<=eps)){
			ans++;
		}
	}
	cout << ans << endl;
}