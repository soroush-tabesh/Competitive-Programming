//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: fact4
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("fact4.in","r",stdin),freopen("fact4.out","w",stdout)
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
ll temp = 1;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	fori(i,2,n+1){
		temp *= i;
		while(temp%10 == 0)
			temp/=10;
		temp %= 1000;
	}
	while(temp%10 == 0)
			temp/=10;
	cout << temp%10 << endl;
}
