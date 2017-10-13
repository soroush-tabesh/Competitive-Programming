#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define frs first
#define scn second
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

int data[1000];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
    //WFile;
	#endif
	Solution();
    return 0;
}

int fnd(int a,int b,int x){
	for(int i = a;i < b;i++)
		if(data[i] == x)
			return i;
	return b;
}

void Solution(){
	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 0;i < n;i++)
		cin >> data[i];
	int c = 0;
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			ll last = data[j];
			ll sum = data[i]+data[j];
			ll ind = j;
			while((ind=fnd(ind,n,sum)) != n){
				sum = last+data[ind];
				last = data[ind];
				c++;
			}
			ans += c;
			ans %= mod;
			c=0;
		}
	}
	cout << ans;
}
