//In The Name of Allah
//Sat 4/6/96
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

int n;
int data[500*1000+5];
set<int> prcd;
int ans[500*1000+5];
int height[500*1000+5];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool comp(int a,int b){
	return height[a] > height[b] || (height[a] == height[b] && a > b);
}

void Solution(){
	cin >> n;
	forar(i,n){
		int a;
		cin >> a;
		data[i] = i;
		height[i] = a;
	}
	sort(data,data+n,comp);
	forar(it,n){
		int cur = data[it];
		auto fnd = prcd.lower_bound(cur);
		prcd.insert(fnd,cur);
		if(fnd == prcd.end() || height[*fnd] == height[cur])
			continue;
		ans[*fnd]++;
	}
	forar(i,n){
		cout << ans[i] << " ";
	}
	cout << endl;
}

