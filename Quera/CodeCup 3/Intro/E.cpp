//In The Name of Allah
//Tue 11/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e6+5;

void Solution();

int n,m;
int data[10005];
int dp[105][10005];
const int inf = 100*1000*1000;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int getans(int vn,int vm){
	if(vn < 1 || vm < 0)
		return -1;
	if(vn == 1){
		int i = 0;
		while(i*i < vm){
			i++;
		}
		if(i*i == vm){
			return ((i-data[vn-1])*(i-data[vn-1]));
		}
	}
	if(dp[vn][vm] > -2)
		return dp[vn][vm];
	int res = inf;
	fori(i,0,101){
		int r = getans(vn-1,vm-i*i);
		if(r!=-1){
			r += ((i-data[vn-1])*(i-data[vn-1]));
			res = min(r,res);
		}
	}
	if(res == inf)
		res = -1;
	return (dp[vn][vm] = res);
}

void Solution(){
	cin >> n >> m;
	forar(i,n){
		cin >> data[i];
	}
	sort(data,data+n,less<int>());
	forar(i,105){
		forar(j,10005){
			dp[i][j] = -2; // -2:not checked
		}
	}
	cout << getans(n,m) << endl;
}
