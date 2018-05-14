//In The Name of Allah
//Wed 10/8/96
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

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

int n,m;
int temp[200];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		cin >> temp[i];
	}
	forar(i,n){
		int a,b,ans = 0;
		cin >> a >> b;
		forar(j,m){
			if(temp[j] >= a && temp[j] <= b)
				ans++;
		}
		cout << ans << endl;
	}
}
