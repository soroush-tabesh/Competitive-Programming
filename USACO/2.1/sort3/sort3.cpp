/*
ID: soroosh4
LANG: C++11
TASK: sort3
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("sort3.in","r",stdin),freopen("sort3.out","w",stdout)
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

int n,ans;
int val[1000];
int c[4];
int dp[4][4];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> val[i];
		c[val[i]]++;
	}
	int i = 0;
	while(i < n){
		if(i<c[1]){
			dp[1][val[i]]++;
		}else if(i<c[2]+c[1]){
			dp[2][val[i]]++;
		}else{
			dp[3][val[i]]++;
		}
		i++;
	}
	int t;
	// 2 in 1 with 1 in 2
	t = min(dp[1][2],dp[2][1]);
	dp[1][2] -= t;
	dp[2][1] -= t;
	ans += t;
	// 1 in 3 with 3 in 1
	t = min(dp[1][3],dp[3][1]);
	dp[1][3] -= t;
	dp[3][1] -= t;
	ans += t;
	// 2 in 3 with 3 in 2
	t = min(dp[3][2],dp[2][3]);
	dp[3][2] -= t;
	dp[2][3] -= t;
	ans += t;
	// aux 1
	if(dp[1][2]){
		t = dp[3][1];
		ans += t;
		dp[3][2] += t;
	}else if(dp[1][3]){
		t = dp[2][1];
		ans += t;
		dp[2][3] += t;
	}
	// aux 2
	ans += dp[2][3];
	
	cout << ans << endl;
	
}
