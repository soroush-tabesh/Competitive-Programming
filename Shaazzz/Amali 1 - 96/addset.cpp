//In The Name of Allah
//Sun 3/10/96
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
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n;

int main()
{
	Init;
	Solution();
	return 0;
}

inline int getans(ull x){
	if(x <= 2)
		return 0;
	int mlg = 63-__builtin_clzll(x/3);
	ull t = 1<<mlg;
	if(t*3 == x){
		return mlg+1;
	}else{
		return mlg+2;
	}
}

void Solution(){
	cin >> n;
	forar(i,n){
		ull a;
		cin >> a;
		cout << getans(a) << endl;
	}
}
