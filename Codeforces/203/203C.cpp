//In The Name of Allah
//Sun 19/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

int n,d;
int a,b;
pii data[M]; // need - person

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> d >> a >> b;
	forar(i,n){
		int x,y;
		cin >> x >> y;
		x*=a;
		y*=b;
		data[i].F = x+y;
		data[i].S = i;
	}
	sort(data,data+n);
	int res = 0;
	while(res < n && (d-=data[res].F) >= 0)
		res++;
	cout << res << endl;
	forar(i,res){
		cout << data[i].S+1 << " ";
	}
	
}

 