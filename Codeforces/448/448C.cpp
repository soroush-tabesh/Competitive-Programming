//In The Name of Allah
//Mon 17/7/96
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

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

int n;
int data[5005];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int solve(int l,int r,int mh){
	if(l >= r)
		return 0;
	int mind = min_element(data+l,data+r)-data;
	if((data[mind]-mh) < (r-l))
		return min(solve(l,mind,data[mind])+solve(mind+1,r,data[mind])+data[mind]-mh,r-l);
	else
		return r-l;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
	}
	cout << solve(0,n,0) << endl;
}
