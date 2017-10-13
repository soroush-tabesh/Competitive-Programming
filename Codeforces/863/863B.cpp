//In The Name of Allah
//Thu 30/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e2+5;

void Solution();

ll n;
ll data[120];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	n*=2;
	forar(i,n){
		cin >> data[i];
	}
	sort(data,data+n);
	ll ans = 120*1000;
	forar(a,n-1){
		fori(b,a+1,n){
			ll res = 0;
			for(int i = 0;i < n;i++){
				if(i==b || i==a)
					continue;
				int nxt = i+1;
				while(nxt==a||nxt==b)
					nxt++;
				res += data[nxt]-data[i];
				i=nxt;
			}
			ans = min(res,ans);
		}
	}
	cout << ans << endl;
}
