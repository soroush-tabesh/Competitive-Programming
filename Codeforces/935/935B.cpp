//In The Name of Allah
//Mon 30/11/96
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

inline void Solution(){
	int n;
	string s;
	cin >> n >> s;
	int x = 0,y = 0;
	int state = (s[0] == 'U' ? 1 : 0);
	int ans = 0;
	forar(i,n){
		if(s[i] == 'U')
			y++;
		else
			x++;
		if(x == y)
			continue;
		if(x < y && state == 0){
			ans ++;
			state = 1;
		}
		if(x > y && state == 1){
			ans++;
			state = 0;
		}
	}
	cout << ans << endl;
}
