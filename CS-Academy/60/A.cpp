//In The Name of Allah
//Wed 15/9/96
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

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	int n;
	int sum = 0;
	cin >> n;
	int data[1000];
	forar(i,n){
		cin >> data[i];
		sum += data[i];
	}
	sort(data,data+n);
	sum -= data[0] + data[n-1];
	cout << sum / (n-2) << endl;
}
