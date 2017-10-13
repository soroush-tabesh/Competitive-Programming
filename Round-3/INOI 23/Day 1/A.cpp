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

const ll delta = 10957;

void Solution();
void SolutionB();

ll sum;
ll dp;
ll dpsum;

int main()
{
	Init;
	//WFile;
	Solution();
	//SolutionB();
	return 0;
}

int ppow(int base,int exp){
	if(exp==0)
		return 1;
	if(exp == 1)
		return base;
	int v = ppow(base,exp/2);
	v*=v;
	v%=delta;
	if(exp%2)
		v*=base;
	return v%delta;
}

void Solution(){
	int n;
	n = delta+3;
	//cin >> n;
	fori(mask,1,n){
		int ones=0,zeros=0;
		int k = mask;
		while(k > 0){
			if(k%2)
				ones++;
			else
				zeros++;
			k/=2;
		}
		sum += ppow(2,zeros) * ppow(3,ones);
		sum %= delta;
	}
	
	int ans = 0;
	fori(i,1,n){
		ll t = sum;
		t *= i;
		t %= delta;
		ans += t;
		ans %= delta;
	}
	
	cout << ans;
}

void SolutionB(){
	dp = 3;
	dpsum = 3;
	fori(i,2,10001){
		dp *= 5;
		dp %= delta;
		dpsum += dp;
		dpsum %= delta;
	}
	ll ans = ppow(2,10000)-1;
	ans *= ppow(2,9999);
	ans %= delta;
	ans *= dpsum;
	ans %= delta;
	cout << ans;
}