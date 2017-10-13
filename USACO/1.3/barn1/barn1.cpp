/*
ID: soroosh4
LANG: C++11
TASK: barn1
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("barn1.in","r",stdin),freopen("barn1.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
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
const int M = 100*1000+5;

void Solution();

int m,s,c;
int l,h;
vector<int> gaps;
int stalls[201];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> m >> s >> c;
	l = s;
	int last = 0;
	forar(i,c){
		cin >> stalls[i];
	}
	sort(stalls,stalls+c);
	forar(i,c){
		int t = stalls[i];
		l = min(l,t);
		h = max(h,t);
		if(!last){
			last = t;
			continue;
		}
		gaps.pb(t-last-1);
		last = t;
	}
	sort(gaps.begin(),gaps.end(),greater<int>());
	int ans = h-l+1;
	int i = 0;
	while(m>1 && i < gaps.size()){
		ans -= gaps[i];
		m--;
		i++;
	}
	cout << ans << '\n';
	
}
