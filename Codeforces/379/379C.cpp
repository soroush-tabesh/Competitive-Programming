//In The Name of Allah
//Sun 22/5/96
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

int n,minim;
pii data[4*100*1000]; // number - person

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool comp(pii l,pii r){
	return l.S < r.S;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i].F;
		data[i].S = i;
	}
	sort(data,data+n);
	forar(i,n){
		data[i].F = max(data[i].F,minim+1);
		minim = data[i].F;
	}
	sort(data,data+n,comp);
	forar(i,n){
		cout << data[i].F << " ";
	}
}

