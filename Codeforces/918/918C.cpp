//In The Name of Allah
//Mon 9/11/96
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
	string s;
	int n;
	cin >> s;
	n = s.length();
	int ans = 0;
	forar(i,n){
		int bal = 0;
		int sv = 0;
		fori(j,i,n){ //inclusive
			bool is = 1;
			switch(s[j]){
				case '?':
					if(bal > 0){
						sv++;
						bal--;
					}else{
						bal++;
					}
					break;
				case '(':
					bal++;
					break;
				case ')':
					bal--;
					if(bal < 0){
						if(sv > 0){
							sv--;
							bal+=2;
						}else{
							is = 0;
						}
					}
					break;
			}
			if(!is)
				break;
			if(bal == 0){
				ans++;
			}
		}
	}
	cout << ans << endl;
}
