//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("104.in","r",stdin),freopen("104.out","w",stdout)
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

vector<ll> prime;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

bool check(ll x){
	ll i = 0;
	while(prime[i]*prime[i] <= x){
		if(x%prime[i] == 0)
			return false;
		i++;
	}
	return true;
}

void Solution(){
	prime.pb(2);
	ll i = 3;
	ll sum = 2;
	while(prime.back() < 2*1000*1000){
		if(check(i)){
			prime.pb(i);
			sum += i;
		}
		i++;
	}
	cout << sum - i + 1 << endl;
}
