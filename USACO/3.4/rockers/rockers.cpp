//In The Name of Allah
//Mon 6/6/96
/*
ID: soroosh4
LANG: C++11
TASK: rockers
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("rockers.in","r",stdin),freopen("rockers.out","w",stdout)
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

int n,m,t,ans;
int data[25];
int disk[25];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void check(int mpos,int dpos,int cnt){
	if(dpos >= m){
		return;
	}
	if(mpos >= n){
		ans = max(ans,cnt);
		return;
	}
	if(disk[dpos] >= data[mpos]){
		disk[dpos] -= data[mpos];
		check(mpos+1,dpos,cnt+1);
		disk[dpos] += data[mpos];
	}else{
		check(mpos,dpos+1,cnt);
	}
	check(mpos+1,dpos,cnt);
}

void Solution(){
	cin >> n >> t >> m;
	forar(i,n){
		cin >> data[i];
	}
	forar(i,m){
		disk[i] = t;
	}
	check(0,0,0);
	cout << ans << endl;
}
