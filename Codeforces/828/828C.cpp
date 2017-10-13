//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
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

ll seq[10*1000*1000];
string t[100*1000+5];
ll n;

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
	cin >> n;
	ll m = 0;
	fori(i,1,n+1){
		cin >> t[i];
		ll k;
		cin >> k;
		forar(j,k){
			ll v;
			cin >> v;
			v--;
			if(seq[v] == 0){
				seq[v] = i;
			}
			if(t[seq[v]].length() < t[i].length()){
				seq[v] = i;
			}
			m = max(m,t[i].length()+v);
		}
	}
	ll curinter = 0;
	ll minter = -1;
	forar(i,m){
		if(seq[i] != 0 && t[seq[i]].length() + i - 1 > minter){ //apply interval
			curinter = seq[i];
			minter = t[seq[i]].length() + i - 1;
		}
		if(i > minter){
			cout << 'a';
		}else{
			cout << t[curinter][i-(minter - t[curinter].length()+1)];
		}
	}
	
}


