//In The Name of Allah
//Sun 29/5/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
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

const ll mod = 1e9+7;

void Solution();

int n,x,y,z;
ll sum;
vector<int> negative;
vector<int> posetive;
int vertval[1005];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void greedyMatching(){
	while(!negative.empty() && !posetive.empty()){
		int from = posetive.size()-1,to = negative.size()-1;
		
		// check for efficiency
		bool is = false;
		while(abs(posetive[from]-negative[to])*z > x+y){
			to--;
			if(to < 0){
				posetive.pop_back();
				is = true;
				break;
			}
		}
		if(is)
			continue;
		
		// convert to array value
		from = posetive[from];
		to = negative[to];
		
		// transfer gravel
		int transfer = min(vertval[from],-vertval[to]);
		vertval[from] -= transfer;
		vertval[to] += transfer;
		sum += abs(from-to)*z*transfer;
		
		// removes from queue if ok
		if(vertval[from] <= 0){
			posetive.pop_back();
		}
		if(vertval[to] >= 0){
			negative.erase(lower_bound(negative.begin(),negative.end(),to));
		}
	}
}

void Solution(){
	cin >> n >> x >> y >> z;
	forar(i,n){
		int a,b;
		cin >> a >> b;
		vertval[i] = a-b;
		if(vertval[i] > 0)
			posetive.pb(i);
		else if(vertval[i] < 0)
			negative.pb(i);
	}
	greedyMatching();
	forar(i,n){
		if(vertval[i] < 0){
			sum -= x*vertval[i];
			vertval[i] = 0;
		}else{
			sum += y*vertval[i];
			vertval[i] = 0;
		}
	}
	cout << sum << endl;
}

