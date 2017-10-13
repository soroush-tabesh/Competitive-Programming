//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
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

set<ll> data;
bool input[20000];
int cnt = 0;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	fori(mask,1389,2011){
		forar(w,11){
			if(mask & (1 << (10-w)))
				input[cnt] = 1;
			cnt++;
		}
	}
	data.insert(0);
	ll cur = 0;
	forar(i,cnt){
		cur = 2*cur + 1 + (input[i] ? 1 : 0);
		if(data.find(cur) == data.end()){
			data.insert(cur);
			cur = 0;
		}
	}
	ll n = data.size();
	ll l = 0;
	for(ll k : data){
		if(data.find(2*k+1) == data.end() && data.find(2*k+2) == data.end())
			l++;
	}
	ll ans = (n*l)%delta;
	ans *= (n*l)%delta;
	cout << ans % delta;
}