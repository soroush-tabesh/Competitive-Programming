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

int p,x,y;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool has(int s,int tar){
	int i = (s/50) % 475;
	forar(k,25){
		i = (i*96+42)%475;
		if(i+26 == tar)
			return true;
	}
	return false;
}

void print(int s){
	int i = (s/50) % 475;
	forar(k,25){
		i = (i*96+42)%475;
		cout << i + 26 << endl;
	}
}

void Solution(){
	cin >> p >> x >> y;
	for(int i = x;i >= y;i -= 50){
		if(has(i,p)){
			cout << 0;
			return;
		}
	}
	int i = 0;
	while(true){
		i++;
		if(has(x+50*i,p)){
			cout << (i+1)/2;
			return;
		}
	}
}




