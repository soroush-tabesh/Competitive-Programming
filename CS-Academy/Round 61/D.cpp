//In The Name of Allah
//Wed 22/9/96
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

const int inf = 2e9;
int n,mn,dp[M],longest;

int main()
{
	Init;
	Solution();
	return 0;
}

void find(int x) {  
	int left = 1, right = longest;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (dp[mid] <= x) {
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	dp[++right] = x;
	if (right > longest) {
		longest = right;
	}
}

void Solution() {
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		dp[i] = inf;
	}
	longest = 0;
	for (int i = 1; i <= n; ++i) {		
		int x;	
		cin >> x;
		find(x);
	}
	cout << n-longest << endl;
}