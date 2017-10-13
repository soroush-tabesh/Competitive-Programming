#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

bool h[1000*1000];
int n,m,k;
int cur = 1;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m >> k;
	forar(i,m){
		int a;
		cin >> a;
		h[a] = 1;
	}
	if(h[1]){
		cout << cur;
		return;
	}
	forar(i,k){
		int a,b;
		cin >> a >> b;
		if(a == cur){
			cur = b;
			if(h[b])
				break;
		}else if(b == cur){
			cur = a;
			if(h[a])
				break;
		}
	}
	cout << cur;
}