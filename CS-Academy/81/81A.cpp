//In The Name of Allah
//Tue 16/3/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fori(i,a,b) for(ll i = a; i < b;i++)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int q,x;
pii inv[10000];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

bool cmp(pii a,pii b){
	return ((a.S-a.F) > (b.S-b.F)) || (((a.S-a.F) == (b.S-b.F)) && (a.F<b.F));
}

inline void Solution(){
	cin >> q >> x;
	forar(i,q){
		cin >> inv[i].F >> inv[i].S;
	}
	sort(inv,inv+q,cmp);
	forar(t,12){
		int delta = 0;
		forar(i,q){
			if(inv[i].F <= x){
				delta = inv[i].S - inv[i].F;
				break;
			}
		}
		x += max(delta,0);
	}
	cout << x <<endl;
}
