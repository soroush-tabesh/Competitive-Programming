/*
ID: soroosh4
LANG: C++11
TASK: inflate
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("inflate.in","r",stdin),freopen("inflate.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;
const int M = 100*1000+5;

void Solution();

int dp[10005];
int t,n,ans;
pii q[10005]; // time - score

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> t >> n;
	forar(i,n){
		cin >> q[i].S >> q[i].F;
	}
	sort(q,q+n);
	forar(i,t+1){
		int m = 0;
		forar(j,n){
			if(q[j].F > i)
				break;
			m = max(m,dp[i-q[j].F]+q[j].S);
		}
		dp[i] = m;
		ans = max(ans,m);
	}
	cout << ans << endl;
}
