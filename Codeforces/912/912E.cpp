//In The Name of Allah
//Fri 15/10/96
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

const ll mod = 1e9+7,M = 1e5+100;

void Solution();

int main()
{
	Init;
	Solution();
	return 0;
}

ll a=2,b=3,c=5,d=7,ans;
ll defa=1,defb=1,defc=1,defd=1;

void Solution(){
	while(defa < ll(1e18)){
		defb = defa;
		while(defb < ll(1e18)){
			defc = defb;
			while(defc < ll(1e18)){
				defd = defc;
				while(defd < ll(1e18)){
					ans++;
					defd*=7;
				}
				defc*=5;
			}
			defb*=3;
		}
		defa*=2;
	}
	cout << ans << endl;
}
