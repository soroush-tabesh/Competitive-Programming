//In The Name of Allah
//Sat 12/3/97
#pragma GCC optimize "-Ofast"
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

const ll mod = 1e9+7,M = (1<<22) + 10;

void Solution();

int n,m,ans,inv;
int arr[M];
bool exs[M];
bool marktrans[M];
bool markmask[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

void dfsmask(int v);

void dfstrans(int v){
	if(marktrans[v])
		return;
	marktrans[v] = 1;
	dfsmask(v);
	forar(i,n){
		dfstrans(v|(1<<i));
	}
}

void dfsmask(int v){
	if(!exs[v] || markmask[v])
		return;
	markmask[v] = 1;
	dfstrans(v^inv);
}

inline void Solution(){
	cin >> n >> m;
	inv = (1<<n)-1;
	forar(i,m){
		cin >> arr[i];
		arr[i] ^= inv;
		exs[arr[i]] = 1;
	}
	forar(i,m){
		if(!markmask[arr[i]]){
			++ans;
			dfsmask(arr[i]);
		}
	}
	cout << ans << endl;
}
