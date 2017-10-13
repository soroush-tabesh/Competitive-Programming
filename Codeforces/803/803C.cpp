#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

set<ll> divisset;
map<ll,ll> facs_map;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void finddivs(vector<pll> temp){
	if(temp.size() == 0)
		return;
	ll a = temp.back().first;
	temp.back().second -= 1;
	if(temp.back().second < 1)
		temp.pop_back();
	finddivs(temp);
	set<ll> td(divisset);
	for(set<ll>::iterator it = td.begin();it != td.end();it++){
		divisset.insert((*it)*a);
	}
}

void Solution(){
	ll n,k,cnt = 1;
	cin >> n >> k;
	ll gcd = 0;
	bool is = false;
	
	// finding divisors
	vector<pll> temp;
	vector<ll> divis;
	ll np = n;
	for(ll i = 2;i * i <= n;i++){
		while(np%i == 0){
			facs_map[i]++;
			np /= i;
		}
	}
	facs_map[np]++;
	for(map<ll,ll>::iterator it = facs_map.begin();it != facs_map.end();it++){
		temp.pb(*it);
		//cout << it->first << " ^ " << it->second << endl;
	}
	divisset.insert(1);
	finddivs(temp);
	for(set<ll>::iterator it = divisset.begin();it != divisset.end();it++){
		divis.pb(*it);
	}
	
	// find the seq gcd
	//Log(n/divis[2]);
	double sum = k;
	sum *= (double)k+1;
	sum /= 2;
	while(sum <= n/divis[gcd] && gcd < divis.size()){
		gcd++;
		is = true;
	}
	gcd--;
	if(!is){
		cout << -1;
		return;
	}
	while(cnt <= k){
		ll o = cnt*divis[gcd];
		n -= o;
		cnt++;
		if(cnt > k)
			o += n;
		cout << o << " ";
	}
}
