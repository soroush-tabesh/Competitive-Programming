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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n;
string s;
pair<char,int> dp[200]; // val - ind

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> s;
	n = s.length();
	dp[n-1] = {s[n-1],n-1};
	for(int i = n-2;i>=0;i--){
		if(s[i] >= dp[i+1].F){
			dp[i] = {s[i],i};
		}else{
			dp[i] = dp[i+1];
		}
	}
	int i = 0;
	while(i < n){
		cout << dp[i].F;
		i = dp[i].S + 1;
	}
}
