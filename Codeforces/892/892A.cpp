//In The Name of Allah
//Fri 26/8/96
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

ll n,sum;
vector<ll> data;

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		ll a;
		cin >> a;
		sum += a;
	}
	forar(i,n){
		int b;
		cin >> b;
		data.pb(b);
	}
	sort(data.begin(),data.end(),greater<int>());
	if(data[0] + data[1] >= sum){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
