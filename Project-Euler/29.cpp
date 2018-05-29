//In The Name of Allah
//Thu 3/3/97
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

bool npr[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

map<int,int> decom(int a,int b){
	map<int,int> res;
	for(int i = 1;i*i <= a;i++){
		while(!npr[i] && a%i==0){
			a/=i;
			res[i]++;
		}
	}
	if(a-1)
		res[a]++;
	for(auto& x : res){
		x.S *= b;
	}
	return res;
}

inline void Solution(){
	npr[0] = npr[1] = 1;
	forar(i,M){
		if(npr[i])
			continue;
		for(int j = i*2;j < M;j+=i){
			npr[j] = 1;
		}
	}
	map< map<int,int> ,bool> lst;
	fori(a,2,101){
		fori(b,2,101){
			lst[decom(a,b)] = 1;
		}
	}
	cout << lst.size() << endl;
}
