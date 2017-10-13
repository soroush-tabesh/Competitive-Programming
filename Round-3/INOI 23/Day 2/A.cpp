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

const ll delta = 10667;

void SolutionA();
void SolutionB();

int main()
{
	Init;
	//WFile;
	//SolutionA();
	SolutionB();
	return 0;
}

void SolutionA(){
	ll x = 1392;
	ll ans = 0;
	fori(a,1,delta){
		fori(b,1,delta){
			if((a*b)%x == 0){
				ans ++;
				ans%=delta;
			}
		}
	}
	cout << ans;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v*=v;
	if(exp%2==1)
		v*=base;
	return v;
}

ll funcf(ll x){
	ll ans = 0;
	fori(a,1,delta){
		fori(b,1,delta){
			if((a*b)%x == 0){
				ans++;
				ans%=delta;
			}
		}
	}
	return ans;
}

void SolutionB(){
	ll i = 0;
	ll temp;
	ll ans = 0;
	while((temp = ppow(2,i)) < delta){
		ans += funcf(temp);
		Log(i);
		ans %= delta;
		i++;
	}
	cout << ans;
}
