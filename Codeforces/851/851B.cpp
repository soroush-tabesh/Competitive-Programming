//In The Name of Allah
//Mon 13/6/96
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
	ll ax,ay,bx,by,cx,cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	ll ab = (ax-bx)*(ax-bx) * 1LL + (ay-by)*(ay-by) * 1LL;
	ll bc = (cx-bx)*(cx-bx) * 1LL + (cy-by)*(cy-by) * 1LL;
	if(ab == bc && ax*(by-cy)+bx*(cy-ay)+cx*(ay-by) != 0){
		cout << "Yes";
	}else{
		cout << "No";
	}
}