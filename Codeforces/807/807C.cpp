//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

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
	ll x, y, p, q;
	int t;
	cin >> t;
	forar(aux,t){
		cin >> x >> y >> p >> q;
		if(p == 1 && q == 1 && x/y != 1){
			cout << -1 << endl;
			continue;
		}
		if(x != 0 && p == 0){
			cout << -1 << endl;
			continue;
		}
		if(x == 0 && p == 0){
			cout << 0 << endl;
			continue;
		}
		
		ll xp = (x + p - x%p)/p;
		ll yp = (y + q - y%q)/q;
		if(x%p == 0)
			xp = x / p;
		if(y%q == 0)
			yp = y / q;
		ll mul = max(xp,yp);
		if(p*mul - x <= q*mul - y){
			cout << q*mul - y << endl;
		}else{
			int temp = 0;
			if(((p*mul - x) - (q*mul - y)) % (q-p) != 0)
				temp = 1;
			mul += ((p*mul - x) - (q*mul - y)) / (q - p);
			mul += temp;
			cout << q*mul - y << endl;
		}
	}
}




