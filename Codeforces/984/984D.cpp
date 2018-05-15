//In The Name of Allah
//Tue 25/2/97
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

typedef unsigned int ui;
int n;
ui arr[6000];
ui f[6000][6000];
ui dp[6000][6000];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> arr[i];
		dp[i][i] = f[i][i] = arr[i];
	}
	fori(len,2,n+1){
		forar(i,n-len+1){
			f[i][i+len-1] = f[i][i+len-2]^f[i+1][i+len-1];
			dp[i][i+len-1] = max(max(dp[i][i+len-2],dp[i+1][i+len-1]),f[i][i+len-1]);
		}
	}
	int q;
	cin >> q;
	forar(i,q){
		int l ,r;
		cin >> l >> r;
		cout << dp[l-1][r-1] << endl;
	}
	
}
