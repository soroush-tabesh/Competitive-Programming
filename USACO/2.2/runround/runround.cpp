/*
ID: soroosh4
LANG: C++11
TASK: runround
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("runround.in","r",stdin),freopen("runround.out","w",stdout)
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

ll tar;
bool mark[12];
bool rep[12];
bool is;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	if(exp==1)
		return base;
	ll v = ppow(base,exp/2);
	v*=v;
	if(exp%2)
		v*=base;
	return v;
}

bool check(ll res){
	vector<pair<ll,bool> > digs;
	ll x = res;
	while(x>0){
		digs.pb({x%10,0});
		x/=10;
	}
	reverse(digs.begin(),digs.end());
	ll i = 0,cnt = 0;
	memset(rep,0,sizeof rep);
	while(cnt < digs.size() && !digs[i].S){
		if(rep[digs[i].F]){
			cnt = digs.size()+1;
			break;
		}else{
			rep[digs[i].F] = 1;
		}
		cnt++;
		digs[i].S = 1;
		i += digs[i].F;
		i %= digs.size();
	}
	return (cnt == digs.size() && i == 0 && res > tar);
}

void next(ll res,ll layer,bool up){
	//check if it's the end
	if(is || layer > 9)
		return;
	
	// if we are on layer zero
	if(layer == 0){
		res /= 10;
		if(check(res)){
			is = true;
			cout << res << endl;
		}
		return;
	}
	
	// increase ones place digit as much as possible and test it by going lower level. when going to a lower level prepare a new position for new digit;
	ll ones = res%10;
	res /= 10;
	mark[ones] = 0;
	ones++;
	for(;ones <= 9;ones++){
		if(!mark[ones]){
			mark[ones] = 1;
			res *= 10;
			res += ones;
			res *= 10;
			next(res,layer-1,false);
			res /= 100;
			mark[ones] = 0;
		}
	}
	
	// when increase is not possible, erase it and go for a higher level
	if(up)
		next(res,layer+1,true);
}

void Solution(){
	cin >> tar;
	ll k = tar;
	while(k>0){
		mark[k%10] = 1;
		k/=10;
	}
	next(tar,1,true);
}
