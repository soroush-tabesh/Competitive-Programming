//In The Name of Allah
//Wed 19/2/97
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

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int cntcat,cntdog;
pii cat[5000],dog[5000];
int tarcat[5000];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline ld dist(pii a,pii b){
	return (a.F - b.F)*(a.F - b.F)+(a.S - b.S)*(a.S - b.S);
} 

inline void Solution(){
	cin >> cntcat >> cntdog;
	forar(i,cntcat){
		cin >> cat[i].F >> cat[i].S;
	}
	forar(i,cntdog){
		cin >> dog[i].F >> dog[i].S;
	}
	forar(i,cntdog){
		int ind = 0;
		forar(j,cntcat){
			if(dist(dog[i],cat[j]) < dist(dog[i],cat[ind]){
				ind = j;
			}
		}
		tarcat[ind]++;
	}
	int ans = 0;
	forar(i,cntcat){
		if(tarcat[i] == 1)
			ans++;
	}
	cout << ans << endl;
}
