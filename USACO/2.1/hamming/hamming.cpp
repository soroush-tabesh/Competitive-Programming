/*
ID: soroosh4
LANG: C++11
TASK: hamming
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("hamming.in","r",stdin),freopen("hamming.out","w",stdout)
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

int n,b,d;
vector<int> ans = {0};

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

bool check(int x){
	for(int k : ans){
		int dist = 0;
		forar(i,b){
			if((x & (1<<i)) != (k & (1 << i))){
				dist++;
			}
		}
		if(dist < d)
			return false;
	}
	return true;
}

void Solution(){
	cin >> n >> b >> d;
	fori(i,1,1<<b){
		if(check(i)){
			ans.pb(i);
		}
	}
	forar(i,int(min(int(ans.size()),n))){
		if(i){
			if(i%10)
				cout << ' ';
			else
				cout << endl;
		}
		cout << ans[i];
	}
	cout << endl;
}
