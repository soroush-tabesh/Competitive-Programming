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
	string n,m;
	ll ns,ms;
	cin >> ns >> ms;
	cin >> n >> m;
	
	ll ans_s = 1001;
	vector<ll> ans_chr;
	
	forar(i,ms-ns+1){
		ll ts = 0;
		vector<ll> t_chr;
		forar(j,ns){
			if(n[j] != m[i+j]){
				ts++;
				t_chr.pb(j);
			}
		}
		if(ts < ans_s){
			ans_s = ts;
			swap(ans_chr,t_chr);
		}
	}
	
	cout << ans_s << endl;
	for(ll c : ans_chr){
		cout << c+1 << " ";
	}
}