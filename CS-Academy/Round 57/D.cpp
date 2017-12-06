//In The Name of Allah
//Sat 27/8/96
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

ll n;
ll dp[1010],sum[256];
string s;

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> s;
	n = s.length();
	dp[0] = 1;
	sum[s[0]] = 1;
	fori(i,1,n){
		dp[i] = dp[i-1];
		forar(j,i){
			if(s[i] == s[j]){
				dp[i] += dp[i-1] - dp[j];
			}
		}
		dp[i] -= sum[s[i]];
		sum[s[i]] += dp[i]-dp[i-1];
	}
}
