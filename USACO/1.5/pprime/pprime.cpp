/*
ID: soroosh4
LANG: C++11
TASK: pprime
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("pprime.in","r",stdin),freopen("pprime.out","w",stdout)
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

vector<int> primes = {2,3};
int a,b;
vector<int> ans = {2,3,5,7,11};

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int ppow(int n,int exp){
	if(exp==1)
		return n;
	if(exp==0)
		return 1;
	int k = ppow(n,exp/2);
	k *= k;
	k *= (exp%2 == 1) ? n : 1;
	return k;
}

int cntdig(int n){
	int i = 0;
	while(n>0){
		n/=10;
		i++;
	}
	return i;
}

int palin(int n){
	int pal = 0;
	while(n>0){
		pal*=10;
		pal+=n%10;
		n/=10;
	}
	return pal;
}

bool isprime(int n){
	if(n > primes.back()){
		int i = 0;
		while(i < primes.size() && primes[i]*primes[i] <= n){
			if(n%primes[i] == 0)
				return false;
			i++;
		}
		return true;		
	}else{
		int query = *lower_bound(primes.begin(),primes.end(),n);
		return n == query;
	}
}

void genPrimes(int limit){
	fori(i,4,limit+1){
		if(isprime(i)){
			primes.pb(i);
		}
	}
}

void genAns(){
	fori(i,10,10000){
		int num = i;
		int cnt = cntdig(num);
		int v = num/10;
		num *= ppow(10,cnt-1);
		num += palin(v);
		if(isprime(num)){
			ans.pb(num);
		}
	}
}

void Solution(){
	cin >> a >> b;
	genPrimes(100000);
	genAns();
	sort(ans.begin(),ans.end());
	vector<int>::iterator e;
	e = lower_bound(ans.begin(),ans.end(),b+1);
	for(vector<int>::iterator it = lower_bound(ans.begin(),ans.end(),a-1);it != e;it++){
		if((*it) <= b && (*it) >= a)
			cout << *it << endl;
	}
}
