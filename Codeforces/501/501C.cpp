#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define dgr first
#define xsm second
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

pair<int ,int> all[70*1000];
set<int> deg1s;
pair<int ,int> ans[70*1000];


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
	int n,m = 0;
	cin >> n;
	ForI(i,0,n){
		cin >> all[i].dgr;
		cin >> all[i].xsm;
		if(all[i].dgr == 1)
			deg1s.insert(i);
	}
	while(deg1s.size() != 0){
		int cur = *(deg1s.begin());
		int ngb = all[cur].xsm;
		deg1s.erase(cur);
		all[ngb].xsm ^= cur;
		if(--all[ngb].dgr == 1)
			deg1s.insert(ngb);
		else if(all[ngb].dgr == 0)
			deg1s.erase(ngb);
		ans[m].first = cur;
		ans[m].second = ngb;
		m++;
	}
	cout << m << endl;
	ForI(i,0,m){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
}
