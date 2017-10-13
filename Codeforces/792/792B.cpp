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

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	int n,k;
	cin >> n >> k;
	vector<int> kids;
	forar(i,n){
		kids.pb(i+1);
	}
	int cur = 0;
	forar(i,k){
		int a;
		cin >> a;
		int toelim = (cur + a) % kids.size();
		if(toelim == kids.size()-1){
			cur = 0;
		}else{
			cur = toelim;
		}
		cout << kids[toelim] << " ";
		kids.erase(kids.begin()+toelim);
	}
	
	
}