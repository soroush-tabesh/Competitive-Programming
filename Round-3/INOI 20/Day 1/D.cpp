//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll delta = 10861;

void Solution();

bool sleep[65];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	int n = 60;
	int ans = 1;
	forar(first,n){
		Log("----------");
		memset(sleep,0,sizeof sleep);
		int awake = n;
		int cur = first;
		while(awake>1){
			sleep[cur] = 1;
			Log(cur+1);
			awake--;
			int tar = cur+1;
			while(tar){
				cur++;
				cur%=n;
				if(!sleep[cur]){
					tar--;
				}
			}
		}
		Log(cur + 1);
		ans *= cur+1;
		ans %= delta;
	}
	cout << ans;
}