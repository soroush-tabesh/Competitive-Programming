//In The Name of God
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

int n;
int a[1000][2];

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
	cin >> n;
	bool change = false;
	bool order = false;
	forar(i,n){
		cin >> a[i][0] >> a[i][1];
		if(a[i][0] != a[i][1])
			change = true;
		if(i != 0){
			if(a[i][0] > a[i-1][0])
				order = true;
		}
	}
	
	if(change){
		cout << "rated";
	}else{
		if(!order)
			cout << "maybe";
		else
			cout << "unrated";
	}
}




