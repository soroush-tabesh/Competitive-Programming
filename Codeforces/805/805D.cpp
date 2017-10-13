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

string data;
ll n,ans,bcnt,i;

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
	cin >> data;
	n = data.length();
	for(i = n-1;i >= 0;i--){
		if(data[i] == 'b'){
			bcnt++;
		}else if(bcnt > 0)
			break;
	}
	for(;i >= 0;i--){
		if(data[i] == 'a'){
			ans += bcnt;
			ans %= mod;
			bcnt *= 2;
			bcnt %= mod;
		}
		while(i > 0 && data[i-1] == 'b'){
			i--;
			bcnt++;
		}
	}
	cout << ans;
}




