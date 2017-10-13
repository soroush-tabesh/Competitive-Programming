//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("shopping.in","r",stdin),freopen("shopping.out","w",stdout)
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

ll data[1000*1000+5];
ll n;
ll dp[1000*1000+5][2]; // dp=a-b
//bool mark[1000*1000+5][2];
ll mx0,mn0;
ll mx1,mn1;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
	}
	mn0 = mx0 = dp[n-1][0] = data[n-1];
	mn1 = mx1 = dp[n-1][1] = -data[n-1];
	//mark[n-1][0] = mark[n-1][1] = 1;
	for(int i = n-2;i >=0;i--){
		// player 0
		dp[i][0] = mn1 + data[i];
		
		// player 1
		dp[i][1] = mx0 - data[i];
		
		// update
		mx0 = max(mx0,dp[i][0]);
		mx1 = max(mx1,dp[i][1]);
		mn0 = min(mn0,dp[i][0]);
		mn1 = min(mn1,dp[i][1]);
	}
	if(mx0 > 0){
		cout << "karakter e komaki_1: " << mx0;
	}else if (mx0 < 0){
		cout << "karakter e komaki_2: " << ((-1)*mx0);
	}else{
		cout << "mosavi";
	}
}
