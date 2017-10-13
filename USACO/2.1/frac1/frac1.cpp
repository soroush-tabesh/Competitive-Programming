/*
ID: soroosh4
LANG: C++11
TASK: frac1
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("frac1.in","r",stdin),freopen("frac1.out","w",stdout)
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

int n;
vector<pii> nums;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

bool comp(pii l ,pii r){
	return (l.F * r.S < l.S * r.F);
}

void Solution(){
	cin >> n;
	forar(i,n+1){
		fori(j,int(max(1,i)),n+1){
			int g = __gcd(i,int(j));
			nums.pb({i/g,j/g});
		}
	}
	sort(nums.begin(),nums.end(),comp);
	nums.resize(distance(nums.begin(),unique(nums.begin(),nums.end())));
	for(pii k : nums){
		cout << k.F << '/' << k.S << endl;
	}
}
