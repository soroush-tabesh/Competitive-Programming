//In The Name of Allah
//Fri 14/10/96
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

const ll mod = 1e9+7,M = 2e3+100;

void Solution();

int n,m;
int inpa[M],inpb[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	forar(i,n){
		cin >> inpa[i];
	}
	forar(i,m){
		cin >> inpb[i];
	}
	int ans = 0;
	forar(j,m-n+1){
		bool is = true;
		forar(i,n){
			if(inpa[i]+inpb[i+j] != 1)
				is = false;
		}
		if(is)
			ans++;
	}
	cout << ans << endl;
}
