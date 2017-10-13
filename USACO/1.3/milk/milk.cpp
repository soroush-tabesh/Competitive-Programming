/*
ID: soroosh4
LANG: C++11
TASK: milk
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("milk.in","r",stdin),freopen("milk.out","w",stdout)
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

int n,m;
pii data[5002];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

bool comp(pii a,pii b){
	return a.F < b.F;
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		int p,a;
		cin >> p >> a;
		data[i] = {p,a};
	}
	sort(data,data+m,comp);
	int i = 0,ans = 0;
	while(n>0){
		if(n > data[i].S){
			n-=data[i].S;
			ans += data[i].F * data[i].S;
			i++;
		}else{
			ans += data[i].F * n;
			n = 0;
		}
	}
	cout << ans << '\n';
}
