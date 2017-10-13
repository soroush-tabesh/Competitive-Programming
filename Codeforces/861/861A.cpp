//In The Name of Allah
//Sun 26/6/96
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

ll n,k;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> k;
	ll d2=0,d5=0;
	ll t = n;
	ll res = 1;
	while(t%2 == 0){
		t/=2;
		d2++;
	}
	while(t%5 == 0){
		t/=5;
		d5++;
	}
	while(d2 < k){
		d2++;
		res*=2;
	}
	while(d5 < k){
		d5++;
		res*=5;
	}
	n*=res;
	cout << n << endl;
}
