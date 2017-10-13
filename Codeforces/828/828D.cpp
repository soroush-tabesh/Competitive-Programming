//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
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

void Solution();

ll n,k;

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
	cin >> n >> k;
	// node 1 is center
	ll curnode = 2;
	ll fullbranches = (n-1)%k;
	ll normbranch = k-fullbranches;
	
	cout << 2*((n-1)/k) + min(fullbranches,2LL) << endl;
	
	forar(branch,fullbranches){
		ll last = 1;
		forar(i,(n-1)/k+1){
			cout << last << " " << curnode << endl;
			last = curnode;
			curnode ++;
		}
	}
	forar(branch,normbranch){
		ll last = 1;
		forar(i,(n-1)/k){
			cout << last << " " << curnode << endl;
			last = curnode;
			curnode++;
		}
	}
	
}