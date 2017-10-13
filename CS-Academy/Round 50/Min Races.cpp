//In The Name of Allah
//Wed 5/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

int n,k;
pii data[M]; // rank - class
multiset<pii,less<pii> > seen; // class - dp
int cnt[M];
int dp[M];
int ind;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> data[i].S >> data[i].F;
	}
	sort(data,data+n,less<pii>());
	seen.insert({0,-1});
	forar(i,n){
		auto r1 = prev(seen.lower_bound({data[i].S),0});
		if(r1->S == -1){
			dp[i] = ++ind;
		}else{
			
		}
		cnt[i] = max(cnt[i],dp[i]);
	}
}
