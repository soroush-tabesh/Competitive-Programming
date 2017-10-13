/*
ID: soroosh4
LANG: C++11
TASK: crypt1
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("crypt1.in","r",stdin),freopen("crypt1.out","w",stdout)
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

bool digits[10];
vector<int> diglist;
int ans;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

pair<int,pair<int,int> > sep(int k){
	pair<int,pair<int,int> > ans;
	ans.S.S = k%10;
	k/=10;
	ans.S.F = k%10;
	k/=10;
	ans.F = k;
	return ans;
}

bool check(int num,int cnt){
	int i = 0;
	while(num > 0){
		i++;
		int d = num%10;
		if(!digits[d])
			return false;
		num/=10;
	}
	if(i != cnt)
		return false;
	return true;
}

void solve(int cur,int remdig){
	if(remdig == 0){
		pair<int,pair<int,int> > num = sep(cur);
		int part1 = num.F * num.S.S;
		int part2 = num.F * num.S.F;
		if(check(part1,3) && check(part2,3) && check(part1+10 * part2,4)){
			ans++;
		}
	}else{
		cur *= 10;
		for(int k : diglist){
			solve(cur + k,remdig-1);
		}
	}
}

void Solution(){
	int n;
	cin >> n;
	forar(i,n){
		int t;
		cin >> t;
		digits[t] = true;
		diglist.pb(t);
	}
	solve(0,5);
	cout << ans << '\n';
}
