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

int mark[1000*1000+5];
pll data[1000*1000+5];
vector<int> primes;
ll sum;
int cur;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

bool comp(pll a,pll b){
	return (a.F * b.S > b.F * a.S || (a.F * b.S == b.F * a.S && a.S < b.S) );
}

bool isprime(int x){
	for(int k : primes){
		if(x%k == 0)
			return false;
	}
	return true;
}

void getdenoms(int x){
	if(mark[x] != cur){
		mark[x] = cur;
		sum += x;
	}
	for(int p : primes){
		if(p*p > x)
			break;
		if(x%p == 0)
			getdenoms(x/p);
	}
}

void Solution(){
	
	primes.pb(2);
	int i = 3;
	while(primes.back() < 10000){
		if(isprime(i)){
			primes.pb(i);
			//cout << i << endl;
		}
		i++;
	}
	
	int n = 1000*1000;
	forar(i,n){
		if(i%(100*1000)==0)
			Log("Yeap");
		sum = 1;
		mark[1] = i;
		mark[i] = i;
		cur = i;
		getdenoms(i);
		data[i] = make_pair(sum,i);
	}
	
	sort(data,data+n+1,comp);
	
	//forar(i,15){
	//	cout << data[i].F << " " << data[i].S << endl;
	//}
	cout << data[15].S << endl;
}