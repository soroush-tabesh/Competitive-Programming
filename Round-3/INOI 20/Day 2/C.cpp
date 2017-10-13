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

const ll delta = 10883;

void Solution();

vector<int> primes;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

bool isprime(int x){
	for(int k : primes){
		if(k*k > x)
			return true;
		if(x%k == 0)
			return false;
	}
	return true;
}

int pfunc(int x){
	int ans = 0;
	string s = "";
	while(x>0){
		s+=("0123456789")[x%10];
		x/=10;
	}
	reverse(s.begin(),s.end());
	forar(i,s.length()){
		if(s[i] == '0')
			continue;
		fori(j,i,s.length()){
			int topro = 0;
			int k = i;
			while(k <= j){
				topro*=10;
				topro+=int(s[k]-'0');
				k++;
			}
			if((*lower_bound(primes.begin(),primes.end(),topro)) == topro){
				ans++;
			}
		}
	}
	return ans;
}

void Solution(){
	int n = 1389000;
	primes.pb(2);
	int i = 3;
	while(primes.back() < n+1){
		if(isprime(i)){
			primes.pb(i);
		}
		i++;
	}
	int ans = 0;
	fori(k,1,n+1){
		ans += pfunc(k);
		ans %= delta;
	}
	cout << ans << endl;
}