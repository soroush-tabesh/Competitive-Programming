//In The Name of Allah
//Wed 29/9/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n;
int data1[M],data2[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data1[i];
	}
	forar(i,n){
		cin >> data2[i];
	}
	int cur = 0;
	fori(i,1,n){
		if(data1[i] > cur){
			cout << 0;
			cur = data1[i];
		}else{
			cout << 1;
		}
	}
	if(data2[n-2])
		cout << 0;
	else
		cout << 1;
	cout << endl;
}
