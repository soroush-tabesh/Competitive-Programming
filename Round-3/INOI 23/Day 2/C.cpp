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

int main()
{
	Init;
	//WFile;
	SolutionA();
	return 0;
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
	return v%delta;
}

void SolutionA(){
	ll k = 5;
	string s = "b123456789a";
	const ll ssize = 11;
	ll ans = 0;
	bool mark[ssize];
	
	do{
		memset(mark,0,sizeof mark);
		ll dels = 0;
		ll iters = 0;
		char last = 0;
		bool is;
		do{
			iters++;
			is = false;
			last = 0;
			forar(i,s.length()){
				if(mark[i])
					continue;
				if(s[i] < last){
					dels++;
					mark[i] = 1;
					is = true;
				}
				last = s[i];
			}
		}while(is);
		iters--;
		if(dels == ssize-1 && iters <= k && !mark[0]){
			ans++;
			//Log(s);
		}
	}while(next_permutation(s.begin(),s.end()));
	
	cout << ans << endl;
	cout << ppow(ans,3) << endl;
}
