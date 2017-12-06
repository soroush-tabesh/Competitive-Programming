//In The Name of Allah
//Sat 27/8/96
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

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	ll n,k;
	string s;
	cin >> n >> k >> s;
	ll pref=0,post=0,bet=0,tbet=0;
	bool is = true;
	forar(i,s.length()){
		if(s[i] == '1')
			is = false;
		if(is)
			pref++;
	}
	is = true;
	forar(i,s.length()){
		if(s[s.length()-i-1] == '1')
			is = false;
		if(is)
			post++;
	}
	forar(i,s.length()){
		if(s[i] == '0'){
			tbet++;
		}
		else{
			bet = max(bet,tbet);
			tbet=0;
		}
	}
	bet = max(bet,tbet);
	if(bet == n){
		cout << n*k << endl;
	}else{
		if(k==1){
			cout << bet << endl;
		}else{
			cout << max(bet,pref+post) << endl;
		}
	}
}
