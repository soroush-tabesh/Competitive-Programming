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
	int n,t,k,d;
	cin >> n >> t >> k >> d;
	int sita = (n / k);
	if(n % k != 0)
		sita++;
	sita *= t;
	
	int sitb = 0;
	int tempcake = d/t;
	if(d%t != 0)
		tempcake++;
	sitb += tempcake*t;
	tempcake *= k;
	n -= tempcake;
	int interval = d%t;
	if(interval == 0)
		interval = t;
	while(n>0){
		//second oven
		n -= k;
		sitb += interval;
		//first oven
		if(n>0){
			n-=k;
			sitb += t-interval;
		}
	}
	
	if(sitb < sita)
		cout << "YES";
	else
		cout << "NO";
	
}




