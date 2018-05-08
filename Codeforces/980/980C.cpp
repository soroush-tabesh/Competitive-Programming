//In The Name of Allah
//Tue 18/2/97
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

int n,k;
int tail[256];
int inp[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> inp[i];
	}
	forar(i,256){
		tail[i] = -1;
	}
	forar(i,n){
		int num = inp[i];
		if(tail[num] != -1){
			cout << tail[num] << " ";
			continue;
		}
		int fur = num;
		forar(l,k){
			if(tail[max(0LL,num-l)] == -1)
				fur = max(0LL,num-l);
			else
				break;
		}
		if(fur){
			if(num - tail[fur-1]+1 <= k)
				fur = tail[fur-1];
		}
		for(int k = num;k>=fur;k--){
			if(tail[k] != -1)
				break;
			tail[k] = fur;
		}
		cout << tail[num] << " ";
	}
	cout << endl;
}
