/*
ID: soroosh4
LANG: C++11
TASK: numtri
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("numtri.in","r",stdin),freopen("numtri.out","w",stdout)
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

int dp[1000][1000];
int r;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> r;
	forar(i,r){
		forar(j,i+1){
			cin >> dp[i][j];
		}
	}
	for(int i = r-2;i>=0;i--){
		forar(j,i+1){
			dp[i][j] += max(dp[i+1][j],dp[i+1][j+1]);
		}
	}
	cout << dp[0][0] << endl;
}
