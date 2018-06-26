//In The Name of Allah
//Tue 5/4/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(ll i = a; i < b;i++)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll sv[M];

ll getnorm(ll x){
	vector<int> dgs;
	while(x){
		dgs.pb(x%10);
		x/=10;
	}
	sort(dgs.begin(),dgs.end());
	for(auto t : dgs){
		x = x*10 + t;
	}
	return x;
}

inline void Solution(){
	fori(i,2,M){
		if(sv[i])
			continue;
		for(int j = i * 2;j < M;j += i){
			sv[j] = 1;
		}
	}
	fori(i,1000,10000){
		fori(j,1,10000){
			int a = i,b = i+j,c = i+2*j;
			if(b >= 10000 || c >= 10000 || sv[a] || sv[b] || sv[c])
				continue;
			a = getnorm(a);
			b = getnorm(b);
			c = getnorm(c);
			if(a == b && b == c){
				cout << i << " " << i+j << " " << i+2*j << endl;
			}
		}
	}
}
