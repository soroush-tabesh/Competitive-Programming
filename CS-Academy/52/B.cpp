//In The Name of Allah
//Wed 19/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

int n;
int data[5005];
int rep[10005];
int ans;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
		rep[data[i]]++;
	}
	sort(data,data+n);
	forar(i,n){
		fori(j,i+1,n){
			if(data[i] != 0 && data[j] != 0){
				ans += rep[data[i]+data[j]];
			}else{
				ans += (upper_bound(data,data+n,data[j])-data)-j-1;
			}
		}
	}
	cout << ans << endl;
}

