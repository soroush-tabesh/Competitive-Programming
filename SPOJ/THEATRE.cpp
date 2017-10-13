//In The Name of Allah
//Fri 21/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

int n;
ll data[M];
ll ans = 1;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[n-i-1];
	}
	stack<ll> cand;
	forar(i,n){
		while(!cand.empty() && cand.top() <= data[i]){
			cand.pop();
		}
		if(!cand.empty()){
			ans *= cand.top();
			ans %= mod;
		}
		cand.push(data[i]);
	}
	cout << ans << endl;
}
