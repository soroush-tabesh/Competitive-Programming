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

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	int n,pos,l,r;
	cin >> n >> pos >> l >> r;
	int ans = 0;
	if(l>1 && r < n){
		cout << r - l + min(abs(r-pos),abs(pos-l)) + 2 << endl;
	}else if(l == 1 && r == n){
		cout << 0 << endl;
	}else if(l==1){
		cout << abs(r-pos)+1 << endl;
	}else{
		cout << abs(pos-l)+1 << endl;
	}
}
