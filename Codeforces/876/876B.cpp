//In The Name of Allah
//Mon 24/7/96
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

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

int n,k,m;
int data[M];
int md[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> k >> m;
	forar(i,n){
		cin >> data[i];
		md[data[i]%m]++;
	}
	int ans = -1;
	forar(i,m){
		if(md[i] >= k){
			ans = i;
		}
	}
	if(ans == -1){
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	forar(i,n){
		if(data[i]%m == ans && k){
			k--;
			cout << data[i] << " ";
		}
	}
}
