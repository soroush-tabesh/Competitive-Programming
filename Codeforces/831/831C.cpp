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
ll jury[2005];
ll data[2005];
set<ll> ans;

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
	cin >> k >> n;
	forar(i,k){
		cin >> jury[i];
		if(i)
			jury[i]+=jury[i-1];
	}
	forar(i,n){
		cin >> data[i];
	}
	sort(jury,jury+k);
	sort(data,data+n);
	forar(start,k){
		ll axiom = data[0]-jury[start];
		ll rem = 1;
		ll j = start+1;
		while(rem != n && j < k){
			if(data[rem] - jury[j] == axiom)
				rem++;
			j++;
		}
		if(rem == n){
			ans.insert(axiom);
		}
	}
	cout << ans.size() << endl;
	
}