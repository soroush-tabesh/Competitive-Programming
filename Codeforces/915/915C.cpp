//In The Name of Allah
//Sat 23/10/96
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

string sa,sb;

int main()
{
	Init;
	Solution();
	return 0;
}

void solve(int j){
	if(j >= sb.length())
		return;
	string tsa = sa;
	int tar = lower_bound(sa.begin()+j,sa.end(),sb[j]) - sa.begin();
	swap(tsa[j],tsa[tar]);
	sort(tsa.begin()+j+1,tsa.end());
	while(tsa > sb){
		tsa = sa;
		swap(tsa[j],tsa[--tar]);
		sort(tsa.begin()+j+1,tsa.end());
	}
	sa = tsa;
	if(sa[j] != sb[j]){
		sort(sa.begin()+j+1,sa.end(),greater<char>());
		return;
	}
	solve(j+1);
}

void Solution(){
	cin >> sa >> sb;
	sort(sa.begin(),sa.end());
	if(sa.length() < sb.length()){
		forar(i,sa.length()){
			cout << sa[sa.length()-i-1];
		}
		return;
	}
	solve(0);
	cout << sa << endl;
}
