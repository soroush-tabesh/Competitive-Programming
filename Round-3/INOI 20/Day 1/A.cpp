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

const ll delta = 10861;

void Solution();

bool data[1400];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

bool isprime(int x){
	if(x == 1)
		return false;
	for(int i = 2; i*i <= x;i++){
		if(x%i == 0)
			return false;
	}
	return true;
}

void Solution(){
	int n = 1389;
	int ans = 0;
	fori(i,1,n+1){
		if(isprime(i)){
			data[i] = 1;
			//cout << 1;
		}else{
			//cout << 0;
		}
	}
	//cout << endl;
	bool is = true;
	while(is){
		ans++;
		is = false;
		fori(i,1,n){
			if(data[i] && !data[i+1]){
				data[i] = !data[i];
				data[i+1] = !data[i+1];
				i++;
				is = true;
			}
		}
	}
	ans--;
	ans = ans + ans*ans + ans*ans*ans;
	ans %= delta;
	cout << ans << endl;
}