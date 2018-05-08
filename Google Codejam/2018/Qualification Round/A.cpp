//In The Name of Allah
//Sat 18/1/97
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

inline ll val(string &s){
	ll res = 0;
	ll chr = 1;
	forar(i,s.length()){
		if(s[i] == 'C'){
			chr *= 2;
		}else{
			res += chr;
		}
	}
	return res;
}

inline bool check(string &s){
	forar(i,s.length()-1){
		if(s[i] == 'C' && s[i+1] == 'S')
			return true;
	}
	return false;
}

inline void swp(string &s){
	int a = 0;
	forar(i,s.length()-1){
		if(s[i] == 'C' && s[i+1] == 'S')
			a = i;
	}
	swap(s[a],s[a+1]);
}

inline void Solution(){
	int tt;
	cin >> tt;
	fori(t,1,tt+1){
		ll d;
		cin >> d;
		string s;
		cin >> s;
		int ans = 0;
		while(check(s) && val(s) > d){
			ans++;
			swp(s);
		}
		if(val(s) > d){
			cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
		}else{
			cout << "Case #" << t << ": " << ans << endl;
		}
	}
}
