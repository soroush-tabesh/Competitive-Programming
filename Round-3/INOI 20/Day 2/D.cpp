//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("sub.txt","r",stdin)//,freopen("out.txt","w",stdout)
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

const ll delta = 10883;

void Solution();

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	string s;
	ll ans = 0;
	while(getline(cin,s)){
		if(s.find("-->") != s.npos){
			forar(i,s.length()){
				if(s[i] == ':' || s[i] == ',' || s[i] == '-' || s[i] == '>'){
					s[i] = ' ';
				}
			}
			stringstream ss(s);
			ll h1,h2,m1,m2,s1,s2,l1,l2;
			ss >> h1 >> m1 >> s1 >> l1 >> h2 >> m2 >> s2 >> l2;
			
			h1 *= 3600*1000;
			h2 *= 3600*1000;
			
			m1 *= 60*1000;
			m2 *= 60*1000;
			
			s1 *= 1000;
			s2 *= 1000;
			
			ll mil1 = h1 + m1 + s1 + l1;
			ll mil2 = h2 + m2 + s2 + l2;
			ans += mil2 - mil1 + 1;
			ans %= delta;
		}
	}
	cout << ans;
}