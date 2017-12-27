//In The Name of Allah
//Wed 6/10/96
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

const ll mod = 1e9+7,M = 5e3+100;

void Solution();

int n;
char s[M];
ll dp[M][M];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> s[i];
	}
	dp[1][1] = 1;
	for(int i = 2;i<=n;i++){
		if(s[n-i] == 's'){
			int j = 0;
			while(dp[i-1][j] == 0 && j < i+2)j++;
			while(dp[i-1][j] && j < i+5){
				dp[i][j+1] += dp[i-1][j];
				j++;
			}
		}else{
			int j = 0;
			while(dp[i-1][j] == 0 && j < i+2)j++;
			while(dp[i-1][j] && j < i+5)j++;
			ll sum = 0;
			while(--j > 0){
				sum += dp[i-1][j];
				sum %= mod;
				dp[i][j] = sum;
			}
		}
	}
	ll ans = 0;
	for(int j = 0;j <=n;j++){
		ans += dp[n][j];
		ans %= mod;
	}
	cout << ans << endl;
	
}
