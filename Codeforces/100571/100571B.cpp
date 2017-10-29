//In The Name of Allah
//Sat 6/8/96
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

ll n,q,a,b;
ll sum[M];
ll data[M];
ll troy[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> q >> troy[0] >> troy[1] >> a >> b;
	forar(i,n){
		cin >> data[i];
	}
	fori(i,2,n+10){
		troy[i] = ((troy[i-1]*b)%mod + (troy[i-2]*a)%mod)%mod;
	}
	forar(i,q){
		ll l,r;
		cin >> l >> r;
		l--;
		r--;
		if(l==r){
			sum[l] = (sum[l]+troy[0])%mod;
			sum[l+1] = (sum[l+1]+mod-(b*troy[0])%mod)%mod;
			sum[l+2] = (sum[l+2]+mod-(a*troy[0])%mod)%mod;
		}else{
			sum[l] = (sum[l]+troy[0])%mod;
			sum[l+1] = (sum[l+1]+troy[1])%mod;
			sum[l+1] = (sum[l+1]+mod-(b*troy[0])%mod)%mod;
			sum[r+1] = (sum[r+1]+mod-troy[r-l+1])%mod;
			sum[r+2] = (sum[r+2]+mod-(a*troy[r-l])%mod)%mod;
		}
	}
	sum[1] = (b*sum[0]+sum[1])%mod;
	fori(i,2,n){
		sum[i] += ((b*sum[i-1])%mod+(a*sum[i-2])%mod)%mod;
		sum[i] %= mod;
	}
	forar(i,n){
		cout << (sum[i] + data[i])%mod << " ";
	}
}
