//In The Name of Allah
//Sun 12/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e6+5;

void Solution();

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

double rec(double x){
	if(x <= 2)
		return 1;
	x = sqrt(x)*rec(x/2) + 1;
	return x;
}

void Solution(){
	freopen("plotter.txt","w",stdout);
	int a,b;
	cin >> a >> b;
	cout << fixed;
	cout.precision(3);
	fori(i,a,b){
		cout << "{" << i << "," << rec(i) << "}";
		if(i!=b-1){
			cout << ",";
		}
		cout << endl;
	}
}
