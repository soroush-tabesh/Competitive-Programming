//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: stamps
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("stamps.in","r",stdin),freopen("stamps.out","w",stdout)
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

int k,n;
int stamp[55];
int dp[2000*1000+5];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> k >> n;
	forar(i,n){
		cin >> stamp[i];
	}
	sort(stamp,stamp+n);
	if(stamp[0] != 1){
		cout << 0 << endl;
		return;
	}
	forar(i,2000*1000+5){
		dp[i] = k+1;
	}
	dp[0] = 0;
	int i = 0;
	while(i < 2000*1000+5){
		if(dp[i] == k+1)
			break;
		forar(j,n){
			dp[i+stamp[j]] = min(dp[i]+1,dp[i+stamp[j]]);
		}
		i++;
	}
	cout << i-1 << endl;
	
}
