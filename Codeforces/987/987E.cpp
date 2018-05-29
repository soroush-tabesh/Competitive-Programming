//In The Name of Allah
//Tue 8/3/97
#pragma GCC optimize "-O"
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

int n,cmp;
int arr[M*10];
bool mark[M*10];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

void dfs(int v){
	if(mark[v])
		return;
	mark[v] = 1;
	dfs(arr[v]);
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> arr[i];
		--arr[i];
	}
	forar(i,n){
		if(!mark[i]){
			dfs(i);
			cmp++;
		}
	}
	int chn = n-cmp;
	if((n%2 == 0) ^ (chn % 2 == 0))
		cout << "Um-nik" << endl;
	else
		cout << "Petr" << endl;
}
